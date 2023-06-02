Code Examples and demos
#######################

To create C++ executables, run the commands:

.. code-block:: console

    > ~Cpp-Template-GTest-on-Gitlab$ mkdir build
    > ~Cpp-Template-GTest-on-Gitlab$ cd build
    > ~Cpp-Template-GTest-on-Gitlab/build$ cmake .. [-Dlib_defs]
    > ~Cpp-Template-GTest-on-Gitlab/build$ make

Inside the `build/` folder, several sub-folders are created. Executables will be found in those.

To add an new executable to a CMake file, please refer to the section "Adding a new executable"
in the :ref:`CMake documentation<CMakeHowTo>`.
