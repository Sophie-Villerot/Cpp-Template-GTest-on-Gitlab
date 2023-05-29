Code Examples and demos
#######################

To create C++ executables, run the commands:

.. code-block:: console

    > ~tailed_modules$ mkdir build
    > ~tailed_modules$ cd build
    > ~tailed_modules/build$ cmake .. [-Dlib_defs]
    > ~tailed_modules/build$ make

Inside the `build/` folder, several sub-folders are created. Executables will be found in those.

To add an new executable to a CMake file, please refer to the section "Adding a new executable"
in the :ref:`CMake documentation<CMakeHowTo>`.

Examples related to the ZKP
***************************

Zero-Knowledge Proof of Knowledge
=================================

Aim:
^^^^

Using the Communication module (as a simulation or through an Oatpp-based service),
two users (Prover and Verifier) interact to check a proof of knowledge.

File considered:
^^^^^^^^^^^^^^^^

  - `examples/ZKPs/mainZKP.hpp`

How to execute:
^^^^^^^^^^^^^^^

In the folder `build/examples/ZKPs/`,
the executable `zkpKnowledgeExample` can be called, in one single Terminal window:

.. code-block:: console

    > ~tailed_modules/build/examples/ZKPs$ ./zkpKnowledgeExample

What to expect:
^^^^^^^^^^^^^^^

There is no user's interaction required, the executable should finish without error.

.. code-block:: console

    > ~tailed_modules/build/examples/ZKPs$ Process finished with exit code 0

Examples related to the Oatpp Communication Module (exclusively in C++)
***********************************************************************

Lambda User
===========

Aim:
^^^^

Run in as many Terminal windows as you wish,
averaging all numbers sent by users connected to the server
(in the 60 seconds time window for connection),
using Local Differential Privacy (Gaussian here).

File considered:
^^^^^^^^^^^^^^^^

  - `examples/mas/oatppComm/mainLambdaUser.cpp`

How to execute:
In the folder `build/examples/mas/oatppComm/`,
run `./lambda` in several windows,
enter unique usernames for each,
then enter any integer ("normal" or big)
and wait for the average.

In one window:

.. code-block:: console

    > ~tailed_modules/build$ cmake .. && make
    > ~tailed_modules/build$ cd examples/mas/oatppComm
    > ~tailed_modules/build/examples/mas/oatppComm$ ./lambda

What to expect:
^^^^^^^^^^^^^^^

Average will be displayed in each Terminal window,
before the program finishes.

Alice and Bob
=============

Aim:
^^^^

Run in two different Terminal windows,
users Alice and Bob exchange simple integers,
through messages sent via the Oatpp-based communication Module.

File considered:
^^^^^^^^^^^^^^^^

  - `examples/mas/oatppComm/mainAliceFirst.cpp`
  - `examples/mas/oatppComm/mainBobSecond.cpp`

How to execute:
^^^^^^^^^^^^^^^

In the folder `build/examples/mas/oatppComm`,
run `./aliceFirst` in one window then `./bobSecond` in another.

In one window:

.. code-block:: console

    > ~tailed_modules/build$ cmake .. && make
    > ~tailed_modules/build$ cd examples/mas/oatppComm
    > ~tailed_modules/build/examples/mas/oatppComm$ ./aliceFirst

And in another one:

.. code-block:: console

    > ~tailed_modules/build$ cd examples/mas/oatppComm
    > ~tailed_modules/build/examples/mas/oatppComm$ ./bobSecond

What to expect:
^^^^^^^^^^^^^^^

Bob will receives a message from Alice and the program will finish.

Averaging demo in C++
=====================

Aim:
^^^^

Several data owners will average a value in plaintext
through the use of the simulated communication module
under the supervision of one coordinator.

File considered:
^^^^^^^^^^^^^^^^
  - `examples/mas/averaging.hpp`
  - `examples/mas/averaging.cpp`
  - `examples/mas/mainAveraging.cpp`

How to execute:
^^^^^^^^^^^^^^^

In the folder `build/examples/mas`,
run `./averageExample`

.. code-block:: console

    > ~tailed_modules/build$ cd examples/mas
    > ~tailed_modules/build/examples/mas$ ./averageExample

What to expect:
^^^^^^^^^^^^^^^

There is no user's interaction required, the executable should finish without error.

.. code-block:: console

    > ~tailed_modules/build/examples/mas$ Process finished with exit code 0

Demos (using C++ and Python)
****************************

This process is described in more detail elsewhere in the documentation.
The current page aims at describing which example needs which executable(s) to be run.
Indeed, some examples need next to their own executable to start a communication server
or other agents at other nodes in the network to collaborate with.




Examples related to Queries (exclusively in Python)
***************************************************
