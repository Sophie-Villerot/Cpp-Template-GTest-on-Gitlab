
.. _CMakeHowTo:

CMake - HowTo
*************

CMake is used in the library as a tool to compile and link properly a multitude of C/C++ files.
It is called via the commands:

.. code-block:: console

    > cd build
    > cmake .. && make

Several executables are then generated and can be called in the build/ folders, the most important being:
 - In the `build/tests` folder, `./runUnitTests` executes all unit tests generated with GTest;
 - In the `build/tests` folder, `./runFuncTests` executes all functional tests generated with GTest;
 - In the `build/example` folder, `./zkptest` executes the communication protocol(s) using the Redis server or the simulation.

Adding a file in an existing folder
===================================

If a `CMakeList.txt` file is not present in the folder containing the new file, please refer to the next section.
The file's names (header and/or source) need to be added in the `CMakeList.txt`,
as in this example (the new files being `myNewFile.cpp` and `myNewFile.hpp`):

.. code-block:: cmake

    ###################################################
    ## SUB-LEVEL CMakeLists.txt for protocols folder ##
    ###################################################

    add_subdirectory(gopa)
    add_subdirectory(secretshare)
    add_subdirectory(./commitmentscheme)
    # add_subdirectory(./homomorphicencrption)
    # add_subdirectory(./ZKPs)


    # set SRCS and HEADERS variable to .cpp/.hpp files
    set(SRCS ProtocolSelection.cpp
             myNewFile.cpp)

    set(HEADERS protocol.hpp
                ProtocolSelection.hpp
                ProtocolTag.hpp
                ProtocolBaseTypes.hpp
                myNewFile.hpp)

    target_sources(${PROJECT_NAME}
               PRIVATE ${SRCS}
               PUBLIC  ${HEADERS})


Adding a new folder
===================

To add files from a new folder, you need to go in the parent folder
and declare the existence of this new folder inside the `CMakeList.txt`
as in this example (the new folder being `myNewFolder`):

.. code-block:: cmake

    ####################################################
    ## src-LEVEL CMakeLists.txt to run the executable ##
    ####################################################

    set(BINARY ${PROJECT_NAME})

    # form the lib
    add_library(${BINARY} ${SRCS})

    add_subdirectory(./bigint)
    add_subdirectory(./knowledgeDB)
    add_subdirectory(./data)
    add_subdirectory(./users)
    add_subdirectory(./smc)
    add_subdirectory(./mas)
    add_subdirectory(./utilities)
    add_subdirectory(./ZKPs)
    add_subdirectory(./protocols)
    add_subdirectory(./myNewFolder)

    target_include_directories(${PROJECT_NAME} PUBLIC .)

Then inside `myNewFolder`, a `CMakeList.txt` is required, to list new files
(the new files being `myNewFile.cpp` and `myNewFile.hpp`):

.. code-block:: cmake

    #####################################################
    ## SUB-LEVEL CMakeLists.txt for myNewFolder folder ##
    #####################################################


    # set SRCS and HEADERS variable to .cpp/.hpp files
    set(SRCS myNewFile.cpp)

    set(HEADERS myNewFile.hpp)

    target_sources(${PROJECT_NAME}
               PRIVATE ${SRCS}
               PUBLIC  ${HEADERS})


Adding flags/options to call another library
============================================

In the top-level `CMakeList.txt`, add your options in the line:

.. code-block:: cmake

    # add compilation options
    add_compile_options(-Wall)
    #add_compile_options(-Werror)

    add_compile_definitions(BIG_INT_SELECT_GMP)

The flags for libraries are mostly needed in the tests, so in the `tests/CMakeList.txt`,
there are:

.. code-block:: cmake

    # dependences declaration for GMP and Oatpp libs
    target_link_libraries(${PROJECT_NAME}
            gmp
            gmpxx
            oatpp::oatpp
            oatpp::oatpp-websocket)

Add a new line with yours.


Adding a new executable
=======================

There are several executable already in place as listed above.
In case you need to add yours (named `myExec` here), inside the right folder, add in the `CMakeList.txt`:

.. code-block:: cmake

    #####################################################
    ## SUB-LEVEL CMakeLists.txt for myNewFolder folder ##
    #####################################################

    # set SRCS and HEADERS variable to .cpp/.hpp files
    set(SRCS myNewFile.cpp)

    set(HEADERS myNewFile.hpp)

    target_sources(${PROJECT_NAME}
            PRIVATE ${SRCS_EX}
            PUBLIC  ${HEADERS_EX})

    add_executable(myExec main.cpp ${SRCS_EX})
    target_link_libraries(myExec Tailed)

Cleaning the cache
==================

This can be done with:

.. code-block:: console

    > cd build
    > make clean