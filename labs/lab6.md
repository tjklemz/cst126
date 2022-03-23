Lab 6: Linked List

Take the code from here: https://github.com/tjklemz/cst126/blob/main/list.cpp

0. Copy that into a new project for this lab. Look over the code, and read the comments. You will need to complete each function as indicated. It will seem like a lot of code, but each function will not be very long.

1. Get the basics working:  append, forEach (so you can print things out), the copy constructor, the assignment constructor, and the destructor. Once you have those, the code in main should print out properly. Double-check that everything looks good.

2. Once you have that down, begin filling out the rest of the functions, for instance "empty" and "first" and "last". Then, move on to the more complicated functions like "filter" and "map", etc.

3. Complete the set operation functions (e.g. set_union).

4. Try importing our string.hpp file (download it and include it in your project and #include "string.hpp"). Create some List<String> lists and try out the set operations.

Test every single function in main. Group the tests with comments, or create separate test functions (e.g. testAppend, testEmpty, testMap) and call those in main. Use forEach with print to test results.

Remember that only a couple functions will need to deal with pointers or new/delete (e.g. append and removeIf). The rest should be using forEach/map/filter/includes/etc. Think of it like a puzzle, trying to figure out the most elegant way to implement a function.
