# 3.8 is the first release to support C++17.
cmake_minimum_required(VERSION 3.8)

project(projectname
        VERSION 1.0.0
        DESCRIPTION "C++ project template"
        LANGUAGES CXX)

add_subdirectory(src)

# Only run tests if this is the project root, i.e. you're not reading
# this file because you've included my project, and if you *wanted* to.
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(test)
endif()

option(ENABLE_CLANG_TIDY "Enable static analysis with clang-tidy using project's settings" OFF)
if(ENABLE_CLANG_TIDY)
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif()
