// This hook expects that the framework dependency is defined on plugin.xml.
// Example:
// <platform name="ios">
//     <!-- .... -->
//     <framework src="path/to/FRAMEWORK_NAME.framework" custom="true" embed="true" />
// </platform>
// For the OutSystems platform it is better to add this hook on both events. As so:
// <platform name="ios">
//     <!-- .... -->
//     <hook type="after_plugin_install" src="path/to/thishook/embed_framework_hook.js" />
//     <hook type="before_build" src="path/to/thishook/embed_framework_hook.js" />
// </platform>

module.exports = function (ctx) {

    var fs = ctx.requireCordovaModule("fs");
    var path = ctx.requireCordovaModule("path");
    var xcode = ctx.requireCordovaModule("xcode");
    var deferral = ctx.requireCordovaModule('q').defer();

    /**
     * Recursively search for file with the tiven filter starting on startPath
     */
    function searchRecursiveFromPath(startPath, filter, rec, multiple) {
        if (!fs.existsSync(startPath)) {
            console.log("no dir ", startPath);
            return;
        }

        var files = fs.readdirSync(startPath);
        var resultFiles = []
        for (var i = 0; i < files.length; i++) {
            var filename = path.join(startPath, files[i]);
            var stat = fs.lstatSync(filename);
            if (stat.isDirectory() && rec) {
                fromDir(filename, filter); //recurse
            }

            if (filename.indexOf(filter) >= 0) {
                if (multiple) {
                    resultFiles.push(filename);
                } else {
                    return filename;
                }
            }
        }
        if (multiple) {
            return resultFiles;
        }
    }

    var xcodeProjPath = searchRecursiveFromPath('platforms/ios', '.xcodeproj', false);
    var projectPath = xcodeProjPath + '/project.pbxproj';
    console.log("Found", projectPath);

    var proj = xcode.project(projectPath);
    var mXCBuildConfigurationSections = proj.parseSync().pbxXCBuildConfigurationSection()

    //create the new BuildConfig
    var newBuildConfig = {}
    for(prop in mXCBuildConfigurationSections) {
        var value = mXCBuildConfigurationSections[prop];
        if(!(typeof value === 'string')) {
            value.buildSettings['EMBEDDED_CONTENT_CONTAINS_SWIFT'] = "YES"
        }
        newBuildConfig[prop] = value;
    }

    //Change BuildConfigs
    proj.hash.project.objects['XCBuildConfiguration'] = newBuildConfig

    fs.writeFile(proj.filepath, proj.writeSync(), 'utf8', function (err) {
        if (err) {
            deferral.reject(err);
            return;
        }
        console.log("finished writing xcodeproj");
        deferral.resolve();
    });

    return deferral.promise;
};
