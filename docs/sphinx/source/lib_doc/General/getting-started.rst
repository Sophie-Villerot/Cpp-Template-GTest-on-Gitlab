Getting started
###############

Requirements and Installation
*****************************

*To clone:* Install git and then clone the repository:

.. code-block:: console

	> sudo apt-get install -y git-all
	> git clone https://github.com/Sophie-Villerot/Cpp-Template-GTest-on-Gitlab.git

*To Build automatically:* Install cmake and automatically generate makefile + personal config file:

.. code-block:: console

	> sudo apt install -y cmake

*To create the documentation:* Install Doxygen (with Graphviz),
Sphinx (with Read the Docs theme), Breathe and Sphinx-BibTeX extension:

.. code-block:: console

	> sudo apt-get install doxygen
	> sudo apt install graphviz
	> sudo apt-get install python3-sphinx
	> pip install breathe
	> pip install sphinxcontrib-bibtex

For Development
***************

Testing
=======

In order to clone the submodule Googletest in ./include/ folder for the first time,
execute the following in it:

.. code-block:: console

    > ~Cpp-Template-GTest-on-Gitlab/include$ git submodule update --init --recursive

C++ Unit Tests with GoogleTests
-------------------------------

Run the commands:

.. code-block:: console

    > ~Cpp-Template-GTest-on-Gitlab$ mkdir build
    > ~Cpp-Template-GTest-on-Gitlab$ cd build
    > ~Cpp-Template-GTest-on-Gitlab/build$ cmake .. && make
    > ~Cpp-Template-GTest-on-Gitlab/build$ make test

Or:

.. code-block:: console

    > ~Cpp-Template-GTest-on-Gitlab/build$ cmake .. && make
    > ~Cpp-Template-GTest-on-Gitlab/build$ cd tests
    > ~Cpp-Template-GTest-on-Gitlab/build/tests$ ./runUnitTests

Documenting
===========

Documentation will be generated when pushing to master, and displayed at XXXXXXXX

If you need to modify the documentation, and wish to check the result on your personal station, you will need to install:

.. code-block:: console

	> sudo apt-get install doxygen
	> sudo apt install graphviz
	> sudo apt-get install python3-sphinx
	> pip install breathe
	> pip install sphinxcontrib-bibtex

To generate the Doxygen documentation, in the `docs/` folder, run the command:

.. code-block:: console

	> ~Cpp-Template-GTest-on-Gitlab/docs$ doxygen Doxyfile

This will generate xml files that will be read by Breathe and integrated in the Sphinx documentation.

In the `docs/sphinx` folder, run the command:

.. code-block:: console

	> ~Cpp-Template-GTest-on-Gitlab/docs/sphinx$ sphinx-build source html

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

	.. doxygenclass:: Algebra
   		:project: Cpp-Template-GTest-on-Gitlab
   		:members:
   		:protected-members:
   		:private-members:
   		:undoc-members:

where the variable `Cpp-Template-GTest-on-Gitlab` is declared in the `conf.py` file as the path where to find the xml files produced by Doxygen:

.. code-block:: rst

	# Breathe Configuration
	breathe_projects = {
    	"Cpp-Template-GTest-on-Gitlab": "../../doxygen/xml/",}

Find more details on Breathe documentation page: https://breathe.readthedocs.io/en/latest/index.html
