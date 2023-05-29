# Setting Up Doxygen
find_package(Doxygen REQUIRED)

# Find all the public directories in /src/: working
get_target_property(ZKP_POC_PUBLIC_HEADER_DIRS ZkpPoc INTERFACE_INCLUDE_DIRECTORIES)
message(STATUS "ZKP_POC_PUBLIC_HEADER_DIRS: ${ZKP_POC_PUBLIC_HEADER_DIRS}")

# Find all public headers in previous directories: working
#file(GLOB_RECURSE ZKP_POC_PUBLIC_HEADERS ${ZKP_POC_PUBLIC_HEADER_DIRS}/*.hpp)
file(GLOB_RECURSE ZKP_POC_PUBLIC_HEADERS ${PROJECT_SOURCE_DIR}/*.hpp ${PROJECT_SOURCE_DIR}/*.h)
message(STATUS "GLOB_RECURSE ZKP_POC_PUBLIC_HEADERS: ${ZKP_POC_PUBLIC_HEADERS}")

#Setting folder/file variables: working
set(DOXYGEN_INPUT_DIR ${PROJECT_SOURCE_DIR})
#message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
set(DOXYGEN_OUTPUT_DIR ${PROJECT_SOURCE_DIR}/docs/doxygen/zkp_poc)
#message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
#message(STATUS "DOXYGEN_OUTPUT_DIR: ${DOXYGEN_OUTPUT_DIR}")
set(DOXYGEN_INDEX_FILE ${DOXYGEN_OUTPUT_DIR}/xml/index.html)
#message(STATUS "DOXYGEN_INDEX_FILE: ${DOXYGEN_INDEX_FILE}")
set(DOXYFILE_IN ${PROJECT_SOURCE_DIR}/docs/Doxyfile)
#message(STATUS "DOXYFILE_IN: ${DOXYFILE_IN}")
set(DOXYFILE_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)
#message(STATUS "DOXYFILE_OUT: ${DOXYFILE_OUT}")

#Replace variables inside @@ with the current values
configure_file(${DOXYFILE_IN} ${DOXYFILE_OUT} @ONLY)

#Creating folder for doxygen docs: doxygen/zkp_poc
#Doxygen won't create this for us
file(MAKE_DIRECTORY ${DOXYGEN_OUTPUT_DIR})

add_custom_command(COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
        #WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        OUTPUT ${DOXYGEN_INDEX_FILE}
        #DEPENDS ${ZKP_POC_PUBLIC_HEADERS}
        #MAIN_DEPENDENCY Doxyfile
        COMMENT "Generating documentation with Doxygen"
        VERBATIM)

# Working for INPUT = "../src" and OUTPUT_DIRECTORY = "docs/doxygen/zkp_poc" in Doxyfile
# To explicitly create docs:
# > cd build
# > cmake ../src && make doc
add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYFILE_OUT}
        WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM)

# Setting Up Sphinx
find_package(Sphinx REQUIRED)

set(SPHINX_SOURCE ${PROJECT_SOURCE_DIR})
set(SPHINX_BUILD ${PROJECT_SOURCE_DIR}/docs/sphinx/build)
set(SPHINX_INDEX_FILE ${SPHINX_BUILD}/html/index.html)

# Only regenerate Sphinx when:
# - Doxygen has rerun
# - Our doc files have been updated
# - The Sphinx config has been updated
# Tell Breathe where to find the Doxygen output: option -Dbreathe_projects.ZkpPoc
# Other docs files you want to track should go here (or in some variable) after DEPENDS
add_custom_target(COMMAND ${SPHINX_EXECUTABLE} -b html
        -Dbreathe_projects.ZkpPoc=${DOXYGEN_OUTPUT_DIR}/xml
        ${SPHINX_SOURCE} ${SPHINX_BUILD}
        OUTPUT ${SPHINX_INDEX_FILE}
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
        DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/index.rst ${DOXYGEN_INDEX_FILE}
        MAIN_DEPENDENCY ${SPHINX_SOURCE}/conf.py
        COMMENT "Generating documentation with Sphinx")

add_custom_target(Sphinx ALL DEPENDS ${SPHINX_INDEX_FILE})

# Add an install target to install the docs
include(GNUInstallDirs)
install(DIRECTORY ${SPHINX_BUILD}
        DESTINATION ${CMAKE_INSTALL_DOCDIR})
