# Add all test files including the file holding the test main function
add_executable(CocktailProTest
        ../src/test/RecipeBook_Test.cpp
        ../src/test/VorhandeneZutaten_Test.cpp ../src/test/RecipeStep_Test.cpp ../src/test/Schuettler_Test.cpp ../src/test/Waage_Test.cpp ../src/test/Timer_Test.cpp ../src/test/Stampfer_Test.cpp)

# Link CocktailProTest against CocktailProSource
linkCocktailProSource(CocktailProTest)

find_package(GTest)
if (GTEST_FOUND)
    # GTest is installed global
    target_link_libraries(CocktailProTest GTest::GTest GTest::Main)
else ()
    # GTest is not found. Download, build, and install it in the build directory
    set(GOOGLETEST_DIR ${CMAKE_BINARY_DIR}/googletest)
    externalproject_add(googletest
            URL https://github.com/google/googletest/archive/release-1.8.1.tar.gz
            PREFIX ${GOOGLETEST_DIR}
            CMAKE_ARGS
            -DCMAKE_INSTALL_PREFIX=${GOOGLETEST_DIR}
            -DCMAKE_MAKE_PROGRAM=${CMAKE_MAKE_PROGRAM}
            -DCMAKE_C_COMPILER=${CMAKE_C_COMPILER}
            -DCMAKE_CXX_COMPILER=${CMAKE_CXX_COMPILER}
            -DBUILD_GMOCK=OFF)
    add_dependencies(CocktailProTest googletest)

    # Link CocktailProTest against the Library
    target_include_directories(CocktailProTest PUBLIC ${GOOGLETEST_DIR}/include)
    # Add ${CMAKE_FIND_LIBRARY_CUSTOM_LIB_SUFFIX} as suffix to lib, in case the Operating system uses lib32 or lib64 as install directory
    target_link_directories(CocktailProTest PUBLIC ${GOOGLETEST_DIR}/lib64)
    target_link_directories(CocktailProTest PUBLIC ${GOOGLETEST_DIR}/lib)
    target_link_libraries(CocktailProTest gtest gtest_main pthread)
endif ()

# In case you wish to use CTest, testing is enabled and the tests were discovered
include(GoogleTest)
enable_testing()
gtest_discover_tests(CocktailProTest)

install(TARGETS CocktailProTest RUNTIME CONFIGURATIONS ${CMAKE_BUILD_TYPE})
