pytest - HowTo
**************

The `pytest` library was chosen instead of the `unittest` library directly integrated in Python for its more frequent updates.

You can install it with:

.. code-block:: console

    > pip3 install -U pytest


Compiling the tests
===================

Run the commands:

.. code-block:: console

    > cd tests
    > python3 -m pytest

Writing the new class test
==========================

Most of the rules can be found in the official documentation: https://docs.pytest.org/en/7.2.x/getting-started.html#get-started

Follow the rule for naming your test file:
"all files of the form test_\*.py or \*_test.py in the current directory and its subdirectories"
(additional details can be found here: https://docs.pytest.org/en/7.2.x/explanation/goodpractices.html#test-discovery )

We currently put the unit tests under `/tests/unit_tests/python/`
and functional or integration tests under `/tests/func_tests/python/`

At the beginning of your test file, import the library:

.. code-block:: python

    import pytest

Simple TEST
-----------

From those files you want to test, all test items should:
 - be prefixed as `test` for functions or methods outside of class;
 - be prefixed `test` for functions or methods inside `Test` prefixed test classes (without an __init__ method).

Example:

.. code-block:: python

    # test_capitalize.py

    def capital_case(x):
        return x.capitalize()

    def test_capital_case():
        assert capital_case('semaphore') == 'Semaphore'

