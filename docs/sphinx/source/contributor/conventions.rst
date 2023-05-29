Our Conventions
###############

Pipelines on Gitlab master branch should always be passing: if need be,
comment the part of your code that is not
working as desired before pushing.

As a rule of thumb, we are trying to commit to master after a
meeting with Jan, unless something needs to be corrected first.

If there is drafted code (usually a rough sketch of new classes to be added
for later work), the idea is to correct it a minima so the code compile and
all the other tests pass.

.. note::

   Functions drafted with a `assert(0);` will need to be implemented.

For C/C++ Use
*************

C++ file names should be:

  - starting with a lowercase letter;
  - without any "_" character and abided by the CamelCase for the rest of the name;
  - identical between .hpp/.cpp/.hxx.

Files extension are chosen to be: `.hpp`, `.cpp` and `.hxx`.

* Files with .hpp extension include the interface that should be seen / called by the users.
* Files with .cpp extension include implementations of non-inline non-template functions, and host declarations of global variables.
* Files with .hxx contain the implementations of inkine and template functions, and header file details (e.g., class definitions, function interfaces ...) which are not intended to be seen / accessed by the user.

The src/ and examples/ directory trees should follow the same structure, i.e., put examples for src/...path.../file.cpp in examples/...path.../fileOrVariant.cpp.  Examples are ideally short and simple, so any functionality which is intended to be used in more than just one or two examples should go into the main src/ branch rather than the examples/ branch.
  
Class definitions may exceptionally contain the implementations of very short (single-line) inline functions, such as setters, getters, etc. as long as they dont hamper readability of the interface.

Please remind that:

* Virtual function should not be defined inline (i.e. in the .hpp file) but in the .cpp file as non-inline.  
* Define destructors of virtual classes as virtual.
* Unless there is a special reason, functions with more than 3 lines shouldn't be inline.  (more precisely, make functions inline if the compiler can clearly generate better code putting the functions inline, e.g., tiny functions or functions which are at the innermost of a huge iteration etc.)
* Unless there is a very good reason, avoid global variables.  Often, static variables (in files, classes or functions) will be sufficient.

.. warning::

   When declaring raw pointer variables, i.e., "Type \*var", the ownership rule should be specified in a comment.  Whenever any confusion may arise (the declaration and comment is not very nearby), remind in a comment the ownership when calling the new or delete operators.  Clear ownership rules helps to avoid unwanted memory leaks.  You can also indicate at allocation where deletion will happen.


Minor issues:

* avoid "struct StructName", unless there is a good reason use "typedef struct { ... } TypeName;".  Never use two names in a declaration, such as in "typedef struct StructName { ... } TypeName;".
* avoid const_cast whenever possible.

For Python Use
**************

All conventions follow (as best as our knowledge extend) the PEP 8 styling guide,
for documentation, testing as well as code writing.

For Git Use
***********

See section on Gitlab use for more information.

Files
=====

Only source files should be committed to the git repository - binary files,
as well as all files that can be recreated using those source files (.pdf, .xml, .html, ...)
should not be uploaded (unless they are tied to an article).

The file .gitignore can be updated at will to avoid automated git add command that would add them.

Commit Message
==============

A commit should be done each time a whole, coherent action has been implemented
(not a whole feature, but a single, self-contained step toward this goal)
so that the code is still compiling and all tests are still passing.

Commit messages should:

 - be less than 70 characters long;
 - describe with an infinitive verb what has been modified;
 - include the number of the issue if the commit resolves one;
 - potentially contains warnings if something is unfinished or broken
   (even better, the number of the related opened issue in Gitlab).

