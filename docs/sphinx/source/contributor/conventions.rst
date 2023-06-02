Conventions
###########

Pipelines on Gitlab master branch should always be passing: if need be,
comment the part of your code that is not
working as desired before pushing.

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

For Python Use
**************

All conventions follow (as best as our knowledge extend) the PEP 8 styling guide,
for documentation, testing as well as code writing.

For Git Use
***********

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

