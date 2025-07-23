# simple c calc
## folder structure
- README.md
- Makefile
- src
    - .c source files
- include
    - .h header files
- build
    - .o obj files
- bin
    - executable files
___
## logic
### steps
- prompting the user for an operation and taking user input
- looping through it a first time to check for invalid characters
    - if any is found break and give the use an error and offer to retry or quit
- looping a second time to remove all spaces
- parsing
    - turning the string into a tree with all it's elements in the right data types
- going through the tree and doing the operations
- giving the resut to the user and promppting for a new operation or to quit the program
### source files
#### main.c
- just has the main functions which calls different functions from all the source files
#### io.c
- contains all input/output related functions
#### parsing.c
- contains all parsing related functions
#### math.c
- contains all the pure math related functions
### header file
#### io.h
#### parsing.h
#### math.h
### Makefile
### README.md
