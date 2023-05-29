Development Tools and Procedures
********************************

Gitlab
======

.. toctree::
   :maxdepth: 2
   :caption: Git and Gitlab guides and list of procedures to follow

   building/git_guide.rst
   building/protocols.rst

Quick mini-guide to use Git:

  - Updating local repository with new commits (and managing new/deleted branches);

  - Finding a file and its committed updated through all branches;

Dev's Protocols:

  - Rebasing and Submitting a merge request;

  - Managing the CI in Gitlab;

Issue Submission
----------------

Pull request
------------

Using the CMake build system
============================

CMake is a powerful tool to automate the compilation and linkage steps for C/C++ files.
However, it can be tricky to master.
Depending on your needs, please check the following document before looking further.

.. toctree::
   :maxdepth: 2
   :caption: Quick How-to using CMake

   building/cmake.rst

Documentation
=============

.. toctree::
   :maxdepth: 2
   :caption: Git and Gitlab guides and list of procedures to follow

   documentation/doc_guide.rst

Quick mini-guide on how to use:

  - Doxygen

  - Sphinx

as well as rules for writing documentation.

Testing
=======

It should be noted that:

Writing "clean" tests ought to be done using the same principle as for the source code,
in particular, the Single Responsibility Principle,
for the Unit tests (testing one function as a time, using mock(s) if need be)
as well as for the Functional tests (testing one step or one full scenario).

**We privilege the AAA pattern for each test**, known as:

 - Assume: SetUp for the parameters;
 - Act: Use the function;
 - Assert: Check result vs expectation.

.. toctree::
   :maxdepth: 2
   :caption: GTest quick summary

   testing/GTest.rst

.. toctree::
   :maxdepth: 2
   :caption: pytest quick summary

   testing/pytest.rst



