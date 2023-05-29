Getting started
###############

Requirements and Installation
*****************************

*To clone:* Install git and then clone the repository:

.. code-block:: console

	> sudo apt-get install -y git-all
	> git clone https://gitlab.inria.fr/magnet/tailed_modules.git

*To Build automatically:* Install cmake and automatically generate makefile + personal config file:

.. code-block:: console

	> sudo apt install -y cmake

Install GMP package:

.. code-block:: console

	> sudo apt-get install libgmp-dev

Alternatively install from source: https://gmplib.org/#DOWNLOAD

Install MPC (and MPFR): (This action is required before installing gmpy2):

.. code-block:: console

	> sudo apt-get install libmpc-dev

Install gmpy2: (See more details at `Read the docs: gmpy2 <https://gmpy2.readthedocs.io/en/latest/intro.html#installation>`_):

.. code-block:: console

	> pip install gmpy2

Install Boost lib (C++):

.. code-block:: console

    > sudo apt-get install libboost-all-dev

Alternatively, install from source: https://www.boost.org/users/download/


*To create the documentation:* Install Doxygen (with Graphviz),
Sphinx (with Read the Docs theme), Breathe and Sphinx-BibTeX extension:

.. code-block:: console

	> sudo apt-get install doxygen
	> sudo apt install graphviz
	> sudo apt-get install python3-sphinx
	> pip install breathe
	> pip install sphinxcontrib-bibtex

Install Oat++ (preferably in the `include/` folder):

.. code-block:: console

	> ~tailed_modules/include$ git clone https://github.com/oatpp/oatpp.git
	> ~tailed_modules/include$ cd oatpp/
	> ~tailed_modules/include/oatpp$ mkdir build && cd build
	> ~tailed_modules/include/oatpp$ cmake ..
	> ~tailed_modules/include/oatpp$ make install

See details at: `Oat++ documentation <https://oatpp.io/docs/start/>`_

Install oatpp-websocket (also preferably in the `include/` folder):

.. code-block:: console

	> ~tailed_modules/include$ git clone https://github.com/oatpp/oatpp-websocket.git
	> ~tailed_modules/include$ cd oatpp-websocket/
	> ~tailed_modules/include/oatpp-websocket$ mkdir build && cd build
	> ~tailed_modules/include/oatpp-websocket$ cmake ..
	> ~tailed_modules/include/oatpp-websocket$ make install

See details at: `oatpp-websockets documentation <https://github.com/oatpp/oatpp-websocket>`_

Install the python-dev package, for the matching python3.X version:

.. code-block:: console

    > sudo apt-get install python3.X-dev

See details at: `python's devguide <https://devguide.python.org/>`_

ALTERNATIVELY, install CPython and compile it from the source:

.. code-block:: console

    > git clone https://github.com/python/cpython.git
    > cd cpython
    > mkdir build && cd build
    > ./configure --with-pydebug && make -j

See details at: `cpython documentation <https://github.com/python/cpython>`_

Install libyaml

.. code-block:: console

    > sudo apt install libyaml-dev

See details at: `libyaml documentation <https://pyyaml.org/wiki/LibYAML>`_

*To come later*:

- Install encryption library: BOTAN

For Development
***************

Testing
=======

In order to clone the submodule Googletest in ./include/ folder for the first time,
execute the following in it:

.. code-block:: console

    > ~tailed_modules/include$ git submodule update --init --recursive

C++ Unit Tests with GoogleTests
-------------------------------

Run the commands:

.. code-block:: console

    > ~tailed_modules$ mkdir build
    > ~tailed_modules$ cd build
    > ~tailed_modules/build$ cmake .. && make
    > ~tailed_modules/build$ make test

Or:

.. code-block:: console

    > ~tailed_modules/build$ cmake .. && make
    > ~tailed_modules/build$ cd tests
    > ~tailed_modules/build/tests$ ./runUnitTests

C++ Functional Tests with GoogleTest and a local server
-------------------------------------------------------

To run the functional tests, you will need a connection to a server.
So before running those tests, you will need to install,
for example, the following module:

.. code-block:: console

   > git clone https://gitlab.inria.fr/magnet/tailed-messaging-server.git

Following the instructions to install the required libraries, you should then be able to run:

.. code-block:: console

   > ~tailed-messaging-server$ sudo docker-compose build
   > ~tailed-messaging-server$ sudo docker-compose up

As mentioned in the terminal, once the server is launched, it can be stopped properly using the command `Ctrl + C`.

If you need to fully clear the cache, use:

.. code-block:: console

   > ~tailed-messaging-server$ sudo docker-compose down

Once this is installed, run the functional tests with:

.. code-block:: console

    > ~tailed-messaging-server$ ./runFuncTests


Python Unit Tests with Pytest
-----------------------------

Run the commands:

.. code-block:: console

    > ~tailed_modules$ cd tests
    > ~tailed_modules/tests$ python3 -m pytest


Documenting
===========

Documentation will be generated when pushing to master, and displayed at https://magnet.gitlabpages.inria.fr/tailed_modules/

If you need to modify the documentation, and wish to check the result on your personal station, you will need to install:

.. code-block:: console

	> sudo apt-get install doxygen
	> sudo apt install graphviz
	> sudo apt-get install python3-sphinx
	> pip install breathe
	> pip install sphinxcontrib-bibtex

To generate the Doxygen documentation, in the `docs/` folder, run the command:

.. code-block:: console

	> ~tailed_modules/docs$ doxygen Doxyfile

This will generate xml files that will be read by Breathe and integrated in the Sphinx documentation.

In the `docs/sphinx` folder, run the command:

.. code-block:: console

	> ~tailed_modules/docs/sphinx$ sphinx-build source html

The file `index.html`, in the newly created `html/` folder, will contain display a webpage with the Sphinx documentation enriched by the Doxygen files.

In the Sphinx source files, it is then possible to use the following commands:

.. code-block:: console

	.. doxygenindex::
	.. doxygenfunction::
	.. doxygenstruct::
	.. doxygenenum::
	.. doxygentypedef::
	.. doxygenclass::

For example, in the form:

.. code-block:: rst

	.. doxygenclass:: ProverDataAnd
   		:project: Tailed_Modules
   		:members:
   		:protected-members:
   		:private-members:
   		:undoc-members:

where the variable `Tailed_Modules` is declared in the `conf.py` file as the path where to find the xml files produced by Doxygen:

.. code-block:: rst

	# Breathe Configuration
	breathe_projects = {
    	"Tailed_Modules": "../../doxygen/xml/",}

Find more details on Breathe documentation page: https://breathe.readthedocs.io/en/latest/index.html


Tree
====

.. code-block:: console

  .
  ├──  README.md
  ├──  CMakeLists.txt
  ├──  .gitlab-ci.yml
  ├──  .gitignore
  ├──  build
  ├──  cmake/
  |    └── FindBotan.cmake
  ├──  docs
  |    ├── cmake
  |    │   └── FindSphinx.cmake
  |    ├── CMakeLists.txt
  |    ├── Doxyfile
  |    ├── doxygen
  |    │   └── HowTo
  |    │       └── Tailed_Modules__HowTo.tex
  |    └── sphinx
  |        ├── html
  |        └── source
  |            ├── conf.py
  |            ├── contributor
  |            │  ├── citing.rst
  |            │  ├── conventions.rst
  |            │  ├── dev_procedures.rst
  |            │  ├── documentation
  |            │  │  └── doc_guide.rst
  |            │  ├── gitlab
  |            │  │  ├── git_guide.rst
  |            │  │  └── protocols.rst
  |            │  └── testing
  |            │      └── GTest.rst
  |            ├── images
  |            │  ├── Add_CI_slaves.png
  |            │  ├── CI_Enabling_Gitlab.png
  |            │  ├── CI_menu_Gitlab.png
  |            │  ├── Create_CI_features.png
  |            │  ├── Log_multiple_branches.png
  |            │  ├── Network_modes-Decentralized.png
  |            │  └── Tailed_v4.png
  |            ├── index.rst
  |            ├── lib_doc
  |            │  ├── General
  |            │  │  ├── data.rst
  |            │  │  ├── getting-started.rst
  |            │  │  ├── glossary.rst
  |            │  │  └── principles.rst
  |            │  ├── MAS
  |            │  │  ├── Agents
  |            │  │  │  ├── agents.rst
  |            │  │  │  └── learning_modes.rst
  |            │  │  └── Communication
  |            │  │      ├── comm_modules.rst
  |            │  │      ├── distributed.rst
  |            │  │      ├── mas.rst
  |            │  │      └── simulated_comm_module.rst
  |            │  ├── Protocols
  |            │  │  ├── Low-Level
  |            │  │  │  ├── secretShare
  |            │  │  │  │  ├── add_secret_sharing.rst
  |            │  │  │  │  └── func_secret_sharing.rst
  |            │  │  │  └── zkp
  |            │  │  │      ├── preliminary
  |            │  │  │      │  ├── definitions.rst
  |            │  │  │      │  ├── notations.rst
  |            │  │  │      │  ├── references.rst
  |            │  │  │      │  └── zkp-principles.rst
  |            │  │  │      └── proofs
  |            │  │  │          ├── all-in-place.rst
  |            │  │  │          ├── poly.rst
  |            │  │  │          ├── proof_of_addition.rst
  |            │  │  │          ├── proof_of_bit.rst
  |            │  │  │          ├── proof_of_conjunction.rst
  |            │  │  │          ├── proof_of_disjunction.rst
  |            │  │  │          ├── proof_of_equality.rst
  |            │  │  │          ├── proof_of_exponentiation.rst
  |            │  │  │          ├── proof_of_knowledge.rst
  |            │  │  │          ├── proof_of_linrel.rst
  |            │  │  │          ├── proof_of_modulo.rst
  |            │  │  │          ├── proof_of_multiplication.rst
  |            │  │  │          ├── proof_of_range.rst
  |            │  │  │          └── proof_of_variance.rst
  |            │  │  ├── Mid-Level
  |            │  │  │  ├── dp.rst
  |            │  │  │  └── randomness.rst
  |            │  │  └── smc_modules.rst
  |            │  └── Python_Layer
  |            │      ├── python_data.rst
  |            │      └── python.rst
  |            └── refs.bib
  ├──  examples
  |    ├── CMakeLists.txt
  |    ├── datastore_test.cpp
  |    ├── main_alice.cpp
  |    ├── main_bob.cpp
  |    ├── main_lambda_user.cpp
  |    ├── main_OpRegistry.cpp
  |    ├── main_zkp.cpp
  |    ├── MPFR
  |    │   ├── main_MPFR.cpp
  |    │   ├── RealMpfr.cpp
  |    │   └── RealMpfr.hpp
  |    ├── zkptest.cpp
  |    └── zkptest.hpp
  ├──  include/
  ├──  src
  |    ├── bigint
  |    │     ├── bigintbotan.hpp
  |    │     ├── bigint.hpp
  |    │     ├── bigintmpz.cpp
  |    │     ├── bigintmpz.hpp
  |    │     ├── bigintvector.cpp
  |    │     ├── bigintvector.hpp
  |    │     ├── CMakeLists.txt
  |    │     ├── tlbigint.cpp
  |    │     └── tlbigint.hpp
  |    ├── CMakeCache.txt
  |    ├── CMakeLists.txt
  |    ├── data
  |    │     ├── CMakeLists.txt
  |    │     ├── iterator.hpp
  |    │     ├── iterator.hxx
  |    │     ├── serializer.cpp
  |    │     ├── serializer.hpp
  |    │     ├── tailed_compound.cpp
  |    │     ├── tailed_compound.hpp
  |    │     ├── tailed_compound.hxx
  |    │     ├── tailed_data.cpp
  |    │     ├── tailed_data.hpp
  |    │     ├── tailed_data.hxx
  |    │     ├── tailed_data_test.cpp
  |    │     ├── tailed_exceptions.hpp
  |    │     ├── tailed_expr.cpp
  |    │     ├── tailed_expr.hpp
  |    │     ├── tailed_expr.hxx
  |    │     ├── tailed_store.cpp
  |    │     ├── tailed_store.hpp
  |    │     ├── tailed_store.hxx
  |    │     ├── tl_operator.cpp
  |    │     ├── tl_operator.hpp
  |    │     ├── tl_uuid.hpp
  |    │     ├── type_utils.cpp
  |    │     └── type_utils.hpp
  |    ├── knowledgeDB
  |    │     ├── claim.cpp
  |    │     ├── claimDB.cpp
  |    │     ├── claimDB.hpp
  |    │     ├── claim.hpp
  |    │     ├── CMakeLists.txt
  |    │     ├── knowledgeBase.cpp
  |    │     ├── knowledgeBase.hpp
  |    │     ├── status.cpp
  |    │     ├── status.hpp
  |    │     ├── variable.cpp
  |    │     ├── variableDB.cpp
  |    │     ├── variableDB.hpp
  |    │     └── variable.hpp
  |    ├── lazyevaluation
  |    │     ├── CMakeLists.txt
  |    │     └── LZE.hpp
  |    ├── main.cpp
  |    ├── mas
  |    │     ├── Agent.cpp
  |    │     ├── Agent.hpp
  |    │     ├── backtrace.cpp
  |    │     ├── backtrace.hpp
  |    │     ├── BasicAgent.cpp
  |    │     ├── BasicAgent.hpp
  |    │     ├── CMakeLists.txt
  |    │     ├── CommunicationModule.cpp
  |    │     ├── CommunicationModule.hpp
  |    │     ├── contract.cpp
  |    │     ├── contract.hpp
  |    │     ├── Environment.hpp
  |    │     ├── message
  |    │     │     ├── atomicMessage.cpp
  |    │     │     ├── atomicMessage.hpp
  |    │     │     ├── bigIntMessage.cpp
  |    │     │     ├── bigIntMessage.hpp
  |    │     │     ├── boolMessage.cpp
  |    │     │     ├── boolMessage.hpp
  |    │     │     ├── CMakeLists.txt
  |    │     │     ├── compoundMessage.cpp
  |    │     │     ├── compoundMessage.hpp
  |    │     │     ├── internalMessage.cpp
  |    │     │     ├── internalMessage.hpp
  |    │     │     ├── intMessage.hpp
  |    │     │     ├── tupleMessage.hpp
  |    │     │     ├── vectorMessage.cpp
  |    │     │     └── vectorMessage.hpp
  |    │     ├── Message.cpp
  |    │     ├── Message.hpp
  |    │     ├── oatppComm
  |    │     │     ├── Agent.hpp
  |    │     │     ├── AgentUser.cpp
  |    │     │     ├── AgentUser.hpp
  |    │     │     ├── CMakeLists.txt
  |    │     │     ├── Communication_utils.cpp
  |    │     │     ├── Communication_utils.hpp
  |    │     │     ├── connection.cpp
  |    │     │     ├── connection.hpp
  |    │     │     ├── dto.hpp
  |    │     │     ├── exceptions.hpp
  |    │     │     ├── http.cpp
  |    │     │     ├── http.hpp
  |    │     │     ├── http_polling.cpp
  |    │     │     ├── http_polling.hpp
  |    │     │     ├── message.cpp
  |    │     │     ├── message.hpp
  |    │     │     ├── OatppCommModule.cpp
  |    │     │     ├── OatppCommModule.hpp
  |    │     │     ├── SpecializedAgent.cpp
  |    │     │     ├── SpecializedAgent.hpp
  |    │     │     ├── test_utils.cpp
  |    │     │     ├── test_utils.hpp
  |    │     │     ├── websocket.cpp
  |    │     │     └── websocket.hpp
  |    │     ├── SimpleAgent.cpp
  |    │     ├── SimpleAgent.hpp
  |    │     ├── simulatedComm
  |    │     │     ├── CMakeLists.txt
  |    │     │     ├── SimulCommModule.cpp
  |    │     │     └── SimulCommModule.hpp
  |    │     ├── ValueTypes.cpp
  |    │     └── ValueTypes.hpp
  |    ├── protocols
  |    │     ├── CMakeLists.txt
  |    │     ├── commitmentscheme
  |    │     │     ├── CMakeLists.txt
  |    │     │     ├── commitmentscheme.cpp
  |    │     │     ├── commitmentscheme.hpp
  |    │     │     ├── commitmentscheme.hxx
  |    │     │     ├── tlcommitmentscheme.cpp
  |    │     │     ├── tlcommitmentscheme.hpp
  |    │     │     └── tlcommitmentscheme.hxx
  |    │     ├── gopa
  |    │     │     ├── CMakeLists.txt
  |    │     │     ├── gopa.cpp
  |    │     │     └── gopa.hpp
  |    │     ├── ProtocolBaseCallback.hpp
  |    │     ├── ProtocolBaseTypes.hpp
  |    │     ├── protocol.hpp
  |    │     ├── ProtocolSelection.cpp
  |    │     ├── ProtocolSelection.hpp
  |    │     ├── ProtocolTag.hpp
  |    │     └── secretshare
  |    │         ├── beaver.cpp
  |    │         ├── beaver.hpp
  |    │         ├── cipolla.cpp
  |    │         ├── CMakeLists.txt
  |    │         ├── damgard
  |    │         │     ├── CMakeLists.txt
  |    │         │     ├── damgard.cpp
  |    │         │     └── damgard.hpp
  |    │         ├── SecShareCallBacks.cpp
  |    │         ├── SecShareCallBacks.hpp
  |    │         └── SecShareProtocol.hpp
  |    ├── python
  |    │     ├── __init__.py
  |    │     ├── LZE_matrix.py
  |    │     ├── LZE.py
  |    │     ├── tl_obj.py
  |    │     └── tl_obj_test.py
  |    ├── smc
  |    │     ├── additivesecretsharing.cpp
  |    │     ├── additivesecretsharing.hpp
  |    │     ├── CMakeLists.txt
  |    │     ├── operationscollection.cpp
  |    │     ├── operationscollection.hpp
  |    │     ├── smcframework.cpp
  |    │     ├── smcframework.hpp
  |    │     ├── smcprimint.cpp
  |    │     ├── smcprimint.hpp
  |    │     └── smcprimitives.hpp
  |    ├── users
  |    │     ├── CMakeLists.txt
  |    │     ├── users.cpp
  |    │     └── users.hpp
  |    ├── utilities
  |    │     ├── CMakeLists.txt
  |    │     ├── random.cpp
  |    │     └── random.hpp
  |    └── ZKPs
  |        ├── CMakeLists.txt
  |        ├── protocols
  |        │     ├── CMakeLists.txt
  |        │     ├── zkpprotocols.cpp
  |        │     └── zkpprotocols.hpp
  |        ├── prover
  |        │     ├── CMakeLists.txt
  |        │     ├── proverdataand.cpp
  |        │     ├── proverdataand.hpp
  |        │     ├── proverdataequality.cpp
  |        │     ├── proverdataequality.hpp
  |        │     ├── proverdataexp.cpp
  |        │     ├── proverdataexp.hpp
  |        │     ├── proverdataknowledge.cpp
  |        │     ├── proverdataknowledge.hpp
  |        │     ├── proverdatalinrel.cpp
  |        │     ├── proverdatalinrel.hpp
  |        │     ├── proverdataor.cpp
  |        │     ├── proverdataor.hpp
  |        │     ├── proverdataprod.cpp
  |        │     ├── proverdataprod.hpp
  |        │     ├── proverdatarange.cpp
  |        │     ├── proverdatarange.hpp
  |        │     ├── proverdatasum.cpp
  |        │     ├── proverdatasum.hpp
  |        │     ├── prover.hpp
  |        │     └── prover.hxx
  |        ├── verifier
  |        │     ├── CMakeLists.txt
  |        │     ├── verifierdataand.cpp
  |        │     ├── verifierdataand.hpp
  |        │     ├── verifierdataequality.cpp
  |        │     ├── verifierdataequality.hpp
  |        │     ├── verifierdataexp.cpp
  |        │     ├── verifierdataexp.hpp
  |        │     ├── verifierdataknowledge.cpp
  |        │     ├── verifierdataknowledge.hpp
  |        │     ├── verifierdatalinrel.cpp
  |        │     ├── verifierdatalinrel.hpp
  |        │     ├── verifierdataor.cpp
  |        │     ├── verifierdataor.hpp
  |        │     ├── verifierdataprod.cpp
  |        │     ├── verifierdataprod.hpp
  |        │     ├── verifierdatarange.cpp
  |        │     ├── verifierdatarange.hpp
  |        │     ├── verifierdatasum.cpp
  |        │     ├── verifierdatasum.hpp
  |        │     ├── verifier.hpp
  |        │     └── verifier.hxx
  |        └── zkptemplates
  |            ├── CMakeLists.txt
  |            ├── zkptemplateand.cpp
  |            ├── zkptemplateand.hpp
  |            ├── zkptemplatebit.cpp
  |            ├── zkptemplatebit.hpp
  |            ├── zkptemplatecell.cpp
  |            ├── zkptemplatecell.hpp
  |            ├── zkptemplate.cpp
  |            ├── zkptemplateeqcommsch.cpp
  |            ├── zkptemplateeqcommsch.hpp
  |            ├── zkptemplateequality.cpp
  |            ├── zkptemplateequality.hpp
  |            ├── zkptemplateeqvalue.cpp
  |            ├── zkptemplateeqvalue.hpp
  |            ├── zkptemplateexp.cpp
  |            ├── zkptemplateexp.hpp
  |            ├── zkptemplategenequality.cpp
  |            ├── zkptemplategenequality.hpp
  |            ├── zkptemplate.hpp
  |            ├── zkptemplateknowledge.cpp
  |            ├── zkptemplateknowledge.hpp
  |            ├── zkptemplatelinrel.cpp
  |            ├── zkptemplatelinrel.hpp
  |            ├── zkptemplatemodulo.cpp
  |            ├── zkptemplatemodulo.hpp
  |            ├── zkptemplateor.cpp
  |            ├── zkptemplateor.hpp
  |            ├── zkptemplateprod.cpp
  |            ├── zkptemplateprod.hpp
  |            ├── zkptemplaterange.cpp
  |            ├── zkptemplaterange.hpp
  |            ├── zkptemplatesum.cpp
  |            ├── zkptemplatesum.hpp
  |            └── zkptemplatewithcommit.hpp
  └──  tests/
  └──  build/
       └── zkp_poc (exec)