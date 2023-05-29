#####################################################
## Top-level CMakeLists.txt to run the executables ##
#####################################################
cmake_minimum_required(VERSION 3.22)
cmake_policy(VERSION 3.22)

# set the project name
project(gtestTemplate
        VERSION 0.1
        DESCRIPTION "C++ Template project for GTest, using CMake"
        LANGUAGES CXX)

# Add folders where Find instructions are located
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake"
                              "${CMAKE_CURRENT_LIST_DIR}/docs/sphinx/cmake")

# Only do these if this is the main project
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    # Optionally set things like CMAKE_CXX_STANDARD, CMAKE_POSITION_INDEPENDENT_CODE here
    # specify the C++ standard
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED True)

    # add CMake build option
    set(CMAKE_BUILD_TYPE Debug)

    # add compilation options
    add_compile_options(-Wall)
    add_compile_options(-Wextra)
    add_compile_options(-lstdc++)
    add_compile_options($ENV{MAKELESS_GCC_OPT})
    add_compile_options(-Werror)

    add_compile_definitions(BIG_INT_SELECT_GMP)

    # Let's nicely support folders in IDEs
    set_property(GLOBAL PROPERTY USE_FOLDERS ON)

    # Testing only available if this is the main app
    # Note this needs to be done in the main CMakeLists
    # since it calls enable_testing, which must be in the
    # main CMakeLists.
    include(CTest)
endif()

    # Forbid the launch of make from the /src/ folder => only from the build folder
if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed.
                         Please make a new directory (called a build directory)
                         and run CMake from there. You may need to remove CMakeCache.txt." )
endif()

# Check if the system is macOS (using the APPLE variable) and set the GMP library name accordingly.
# This ensures compatibility with macOS systems when searching for the GMP library.
if(APPLE)
    set(GMP_LIB_NAME "libgmp.dylib")
else()
    set(GMP_LIB_NAME "libgmp.so")
endif()

find_library(GMP_LIB_PATH ${GMP_LIB_NAME} REQUIRED)
get_filename_component(GMP_LIB_DIR ${GMP_LIB_PATH} DIRECTORY)

set(CPPTEMPLATE_DEP_LIBS
    gmp
    gmpxx)

set(CPPTEMPLATE_SRC_INCS
        ${PROJECT_SOURCE_DIR}/src
        ${PROJECT_SOURCE_DIR}/src/ZKPs)

set(CPPTEMPLATE_DEP_INCS
        ${GMP_LIB_DIR})

# Subdirectories
# Compiled lib
add_subdirectory("${CMAKE_CURRENT_LIST_DIR}/src")

# Testing only available if this is the main app
# Emergency override MODERN_CMAKE_BUILD_TESTING provided as well
if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING)
        AND BUILD_TESTING)
    option(PACKAGE_TESTS "Build the tests" ON)
    if(PACKAGE_TESTS)
        enable_testing()
        include(GoogleTest)
        add_subdirectory(include)
        add_subdirectory(tests)
    endif()
endif()
