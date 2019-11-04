#!/usr/bin/env groovy

node {
    // Specifying the directories and files needed later
    // Some paths are relative, because a few jenkins plugins need relative paths
    def BUILD_DIR = "${env.WORKSPACE}/cmake-build-debug"
    def INSTALL_DIR = "${env.WORKSPACE}/install"
    def CONFIG_DIR = "${env.WORKSPACE}/config"
    def SOURCE_DIR = "${env.WORKSPACE}/src/main"

    def REPORTS_DIR_REL = "reports"
    def DOXYGEN_DIR_REL = "${REPORTS_DIR_REL}/doxygen"

    def REPORTS_DIR = "${env.WORKSPACE}/${REPORTS_DIR_REL}"
    def GITSTATS_DIR = "${REPORTS_DIR}/gitstats"
    def CCCC_DIR = "${REPORTS_DIR}/cccc"
    def COVERAGE_DIR = "${REPORTS_DIR}/coverage"
    def DOXYGEN_DIR = "${env.WORKSPACE}/${DOXYGEN_DIR_REL}"

    def COMPILER_WARNINGS_LOG_REL = "${REPORTS_DIR_REL}/compiler-warnings.log"
    def DOXYGEN_WARNINGS_LOG_REL = "${DOXYGEN_DIR_REL}/doxygen-warnings.log"
    def CPPCHECK_REPORT_REL = "${REPORTS_DIR_REL}/cppcheck-report.xml"
    def GTEST_REPORT_REL = "${REPORTS_DIR_REL}/gtest-report.xml"

    def COMPILER_WARNINGS_LOG = "${env.WORKSPACE}/${COMPILER_WARNINGS_LOG_REL}"
    def DOXYGEN_WARNINGS_LOG = "${env.WORKSPACE}/${DOXYGEN_WARNINGS_LOG_REL}"
    def CPPCHECK_REPORT = "${env.WORKSPACE}/${CPPCHECK_REPORT_REL}"
    def GTEST_REPORT = "${env.WORKSPACE}/${GTEST_REPORT_REL}"

    def EVALUATION_DIR = "/tmp/SWE/${env.JOB_NAME}"
    

    stage("Pull") {
        // Pulling the sources from the repository
        // WARNING: Be sure, that you are using the right repository
        git url: "https://code.fbi.h-da.de/SE/cocktailpro_legacy.git", credentialsId: "b5b0468b-4d7b-46cf-80c8-bb6d45929adb"
    }

/*
    def COCKTAIL_PRO_IMAGE
    stage("Build Docker Image") {
        // Preparing the name to suit the docker image name syntax
        def imageName = env.JOB_NAME
        imageName = imageName.replaceAll(" ", "_")
        imageName = imageName.replaceAll("[^-_a-zA-Z0-9]", "")
        imageName = imageName.replaceAll("^[-_]+", "")
        imageName = imageName.replaceAll("[-_]+\$", "")
        imageName = imageName.replaceAll("_{3,}", "__")
        if (128 < imageName.length()) {
            imageName = imageName.substring(0, 128)
        }
        imageName = imageName.toLowerCase()

        // Building the image with the correct adjusted job name and build number from jenkins as name and tag for the image
        COCKTAIL_PRO_IMAGE = docker.build("${imageName}:${env.BUILD_NUMBER}")
    }
*/

    stage("Prepare Environment") {
        // Delete the old build directory
        dir("${BUILD_DIR}") {
            deleteDir()
        }

        // Delete the old install directory
        dir("${INSTALL_DIR}") {
            deleteDir()
        }

        // Delete the old evaluation directory
        dir("${EVALUATION_DIR}") {
            deleteDir()
        }

        // Creating needed directories with their needed parents if they are absent
        sh "mkdir -p ${REPORTS_DIR}"
        sh "mkdir -p ${GITSTATS_DIR}"
        sh "mkdir -p ${CCCC_DIR}"
        sh "mkdir -p ${COVERAGE_DIR}"
        sh "mkdir -p ${DOXYGEN_DIR}"
        sh "mkdir -p ${INSTALL_DIR}"
        sh "mkdir -p ${EVALUATION_DIR}"
    }

/* // Only for Build in Docker Container
    COCKTAIL_PRO_IMAGE.inside {
	// Any build steps should be inside the docker container
*/
	stage("Generate CMake Project Buildsystem") {
		// Setting up the CMake project and reloading the CMakeLists.txt
		sh "cmake -G 'Unix Makefiles' \
			-S ${env.WORKSPACE} -B ${BUILD_DIR} \
			-DRUN_GTESTS=OFF \
			-DCMAKE_BUILD_TYPE=Debug \
			-DCMAKE_INSTALL_PREFIX='${INSTALL_DIR}' \
			-DDOXYGEN_OUTPUT_DIRECTORY='${DOXYGEN_DIR}' \
			-DDOXYGEN_PROJECT_NAME=CocktailPro \
			-DDOXYGEN_PROJECT_BRIEF='Praktikum Software Engineering, fbi, h_da, WS2019'"
	}

	stage("Build") {
		//sh "cmake --build ${BUILD_DIR} --target CocktailPro 2> ${COMPILER_WARNINGS_LOG}"        
		sh "cmake --build ${BUILD_DIR} --target CocktailPro 2>&1 | tee -a ${COMPILER_WARNINGS_LOG}"
	}

	try {
		stage("Doxygen") {
			sh "cmake --build ${BUILD_DIR} --target CocktailProDoxygen 2>&1 | tee -a ${DOXYGEN_WARNINGS_LOG}"
			//sh "cmake --build ${BUILD_DIR} --target CocktailProDoxygen 2> ${DOXYGEN_WARNINGS_LOG}"
		}
	} catch (err) {
		currentBuild.result = 'SUCCESS'
	}

	try {
		stage("CppCheck") {
				sh "cmake --build ${BUILD_DIR} --target CocktailProCppCheck 2> ${CPPCHECK_REPORT}"
		}
	} catch (err) {
		currentBuild.result = 'SUCCESS'
	}

	try {
		stage("CCCC") {
			sh "cccc --opt_infile=${CONFIG_DIR}/cccc.opt --outdir=${CCCC_DIR} --report_mask=pPS ${SOURCE_DIR}/*"
		}
	} catch (err) {
		currentBuild.result = 'SUCCESS'
	}

	try {		
		stage("GitStats") {
			sh "gitstats ${env.WORKSPACE} ${GITSTATS_DIR} >> ${GITSTATS_DIR}/gitstats.log"
		}
	} catch (err) {
		currentBuild.result = 'SUCCESS'
	}		
		
		
	try {
		stage("Test") {
			// Build Executable for Test
			sh "cmake --build ${BUILD_DIR} --target CocktailProTest"
			
			// Clear previously generated coverage data
			sh "lcov --zerocounters --directory ${env.WORKSPACE}"
			// Generate base information. Every line is available with a calling count of zero
			sh "lcov --no-external --capture --initial --directory ${env.WORKSPACE} --output-file ${COVERAGE_DIR}/lcov.base.info"
	
			//Execute Test
			dir("${BUILD_DIR}") {
				sh "./CocktailProTest --gtest_output='xml:${GTEST_REPORT}'"
			}
		}
	} catch (err) {
		currentBuild.result = 'UNSTABLE'
	}
		
    try {		
			stage("Coverage") {
				// Parsing the created .gcda files of CocktailProTest and generating the information file
				sh "lcov --no-external --quiet --capture --directory ${env.WORKSPACE} --output-file ${COVERAGE_DIR}/lcov.test.info"
				// Merging the base information and the test information to prevent that uncalled files vanish in the result
				sh "lcov --add-tracefile ${COVERAGE_DIR}/lcov.base.info --add-tracefile ${COVERAGE_DIR}/lcov.test.info --output-file ${COVERAGE_DIR}/lcov.total.info"
				// Removing not needed files to help student to focus on the right parts
				sh "lcov --quiet --remove ${COVERAGE_DIR}/lcov.total.info '${BUILD_DIR}/*' '${SOURCE_DIR}/Main.*' '${env.WORKSPACE}/src/test/*' '*.h' -o ${COVERAGE_DIR}/lcov.info"
				// Generate the HTML files out of the information
				sh "genhtml --quiet --function-coverage ${COVERAGE_DIR}/lcov.info --output-directory ${COVERAGE_DIR}"
			}
	} catch (err) {
		currentBuild.result = 'SUCCESS'
	}			

        stage("Install") {
            sh "cmake --build ${BUILD_DIR} --target install"
        }
/* // Only for Build in Docker Container		
    }
*/
    try {	
		stage("Publish") {
			// Parsing the Console output for Compiler Warnings and the Doxygen Log file
			warnings canComputeNew: false, canResolveRelativePaths: false, categoriesPattern: "",
					defaultEncoding: "", excludePattern: "", healthy: "", includePattern: "", messagesPattern: "",
					parserConfigurations: [[parserName: "GNU C Compiler 4 (gcc)", pattern: "${COMPILER_WARNINGS_LOG_REL}"],
										   [parserName: "Doxygen", pattern: "${DOXYGEN_WARNINGS_LOG_REL}"]],
					unHealthy: ""
			publishCppcheck pattern: "${CPPCHECK_REPORT_REL}"
			// Publish Doxygen
			publishHTML([allowMissing: false, alwaysLinkToLastBuild: false, keepAll: false,
						 reportDir   : "${DOXYGEN_DIR}/html", reportFiles: "index.html",
						 reportName  : "Doxygen Document", reportTitles: ""])
			// Publish CCCC Report
			publishHTML([allowMissing: false, alwaysLinkToLastBuild: false, keepAll: false,
						 reportDir   : "${CCCC_DIR}", reportFiles: "cccc.html",
						 reportName  : "CCCC Report", reportTitles: ""])
			// Publish Code Coverage
			publishHTML([allowMissing: false, alwaysLinkToLastBuild: false, keepAll: false,
						 reportDir   : "${COVERAGE_DIR}", reportFiles: "index.html",
						 reportName  : "Code Coverage", reportTitles: ""])
			// Publish Git Statistics
			publishHTML([allowMissing: false, alwaysLinkToLastBuild: false, keepAll: false,
						 reportDir   : "${GITSTATS_DIR}", reportFiles: "index.html",
						 reportName  : "Git Statistics", reportTitles: ""])
			// Publish Google Test Results
			xunit([GoogleTest(deleteOutputFiles: true, failIfNotNew: false,
					pattern: "${GTEST_REPORT_REL}", skipNoTestFiles: false, stopProcessingIfError: false)])

			// Upload files for evaluation
			sh "cp -R ${INSTALL_DIR}/* ${EVALUATION_DIR}"
			
			// Activate Chuck Norris
			chuckNorris()
		}
	} catch (err) {
        currentBuild.result = 'SUCCESS'
    }	

}
