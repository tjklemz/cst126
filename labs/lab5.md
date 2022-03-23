# Lab 5: Vector

0.  Look over the existing string.hpp file in Github and see how the constructors and destructors work.

1.  Take the existing code from append.cpp and modify the Vector struct to have a default constructor, a copy constructor, a copy-assignment constructor, and a destructor. Make sure the existing functions, such as forEach and append, still work (you should no longer need deleteAll). Verify (e.g. using std::cout) that your constructors and destructors in Vector are getting called.

2.  Move the Vector struct into its own file called "vector.hpp". Include that file in your program, making sure everything runs as in the previous step.

3.  Move the functions from append.cpp into "vector.hpp" as well (append, forEach, etc). Verify that everything is working.

4.  Rewrite Lab 2 (without the quantities part) using the "vector.hpp" file. You should use the "string.hpp" struct as well to store the names of ingredients.  You should have a Vector<String> for your ingredients:

```c++
Vector<String> pantry{};

// in your code:
append(pantry, ingredient);
```
