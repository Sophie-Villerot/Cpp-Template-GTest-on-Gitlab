Documentation Mini-Guide
************************

.. note::

    Doxygen is used for C++ low-level documentation, aimed at developers.
    Docstring is used for Python low-level documentation.

    Sphinx is used for high-level documentation, aimed mainly at users (and thus giving full examples of APIs usage),
    and can integrate Doxygen comments, as well as Python Docstest comments.

Requirements
============

Documentation will be generated when pushing to master, (and doc, hen the branch is active),
and displayed at the URL https://magnet.gitlabpages.inria.fr/tailed_modules/

Install the proper libraries first:

.. code-block:: console

    > sudo apt-get install doxygen
    > sudo apt install graphviz
    > sudo apt-get install python3-sphinx
    > pip install sphinx_rtd_theme
    > pip install breathe
    > pip install sphinxcontrib-bibtex

Compiling the whole documentation
=================================

To generate the Doxygen documentation, in the `docs/` folder, run the command:

.. code-block:: console

    > cd docs/
    > doxygen Doxyfile

This will generate .xml files that will be read by Breathe and integrated in the Sphinx documentation.

In the `docs/sphinx` folder, run the command:

.. code-block:: console

    > cd docs/sphinx
    > sphinx-build source html

The file `index.html`, in the newly created `html/` folder, will contain display a webpage with the first page of the
Sphinx documentation enriched by the Doxygen comments from C++ files.

Using Doxygen
=============

We use Doxygen for low-level documentation, i.e. documentation aimed at other developers or specific users who would
need a tighter control on the operations taking place under the library's APIs.

Doxygen is key to highlight all comments made in the code's body.
We use it:

  - to describe in general terms the 'raison d'être' of a given class, by adding a few paragraphs above the declaration of the former;

  - to describe public functions used as APIs in the body of such class, as well as detailing the input/ouput parameters;

  - to describe private members, their nature and use, as well as their potential link to algorithms referenced into scientific papers;

  - to warn other developers that a specific or obscure "trick" has been used in order to optimise the code,
    or to explain the consequences of future actions, such as the removal of a particular piece of code.

Commands
--------

While the full list can be seen at this URL: https://www.doxygen.nl/manual/commands.html ,
here is a quick summary of our most used commands:

.. code-block:: cpp

    /** @brief: My new class
    * Overhead for describing a class in general terms
    * as well as setting rules regarding choices of architecture
    * such as polymorphism, template, etc... */

    /** Functions can be introduced in the same fashion, and parameters described by:
    * @param[in]
    * @param[out] or @return */

    /**< Members of a class can be described with this command, and
    * formulae can be added following LaTeX formatting \see {https://www.doxygen.nl/manual/formulas.html} */

Further references:
 - https://doxygen.nl/manual/docblocks.html

Using Sphinx
============

For high-level, user-friendly documentation of the APIs, we use Sphinx.

High-level concepts, e.g. related to architectural decisions of Tailed, or to the integration of other Open Source
libraries, can also be made transparent and explicit in this part of the documentation.
Descriptions of algorithms or equations, when hard to found in papers, can be also integrated here.

Restructured Text
-----------------

RestructuredText is a form of upgraded markdown. There are numerous way to enhance the raw text,
and the best way to learn is certainly to either search on the web how to perform a certain type of formatting,
or to browse the already redacted files mentioned previously.

  - Tables and emphasis work in the way they work with markdown;

  - Integrating a block of code can be done with the command:

   .. code-block:: rst

        .. code-block ::

   (guessing the programming language is left to Sphinx) or, more explicitely:

   .. code-block:: rst

        .. code-block :: python

        .. code-block :: cpp

        .. code_block :: console

            + Followed by a blank line
            Every line following an indentation will be considered as part of the code block
            Other supported languages can be found here: https://pygments.org/languages/

   - Integrating an image:

   .. code-block:: rst

        .. image:: ../../images/ + file in .png
            :width: XXX .. size in pixels
            :alt: Alt text

Quick references:
 - https://docutils.sourceforge.io/docs/user/rst/quickref.html
 - https://www.sphinx-doc.org/en/master/usage/restructuredtext/basics.html

Full references:
 - https://docutils.sourceforge.io/rst.html

Linking Doxygen and Sphinx via Breathe
--------------------------------------

In the Sphinx source files, it is then possible to use the following commands:

.. code-block:: rst

    .. doxygenindex::
    .. doxygenfunction::
    .. doxygenstruct::
    .. doxygenenum::
    .. doxygentypedef::
    .. doxygenclass::

For example, in the form:

.. code-block:: rst

    .. doxygenclass:: ProverDataAND
        :project: Tailed_Modules
        :members:
        :protected-members:
        :private-members:
        :undoc-members:

where the variable `Tailed_Modules` is declared in the `conf.py` file as the path where to find the xml files produced by Doxygen:

.. code-block:: python

    # Breathe Configuration
    breathe_projects = { "Tailed_Modules": "../../doxygen/xml/", }


Find more details on Breathe documentation page: https://breathe.readthedocs.io/en/latest/index.html


