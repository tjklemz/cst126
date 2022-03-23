# Lab 3: Twitter

For this lab, we'll build a very simple Twitter app that reads in some tweets and lets us follow users and view their tweets.

For a beginning stub, see here: https://github.com/tjklemz/cst126/blob/main/lab3.cpp


The goal is to become more familiar with basic structs + dynamic arrays; and also to begin to look at shallow vs deep copy. In a future lab, we'll look at constructors / destructors.

You might need to create multiple versions of "append" to handle the different types. Once we create String and Vector, this all goes away. :) We want to see how to manually do things to understand what String and Vector are solving for us.

### Data:

tweets.txt 

^ use this data file or make your own that's similar for the list of tweets. We are assuming that most recent tweets are at the top. The format is "@user <tweet text>" per line.

```c++
struct User {
  char handle[16];
  int numFollowing;
  char ** following;
};

struct Tweet {
  char text[141];
  char creator[16];
};

/* in main: */
Tweet ** tweets{};
User ** users{};
```

Use the "append"/etc functions that we've been creating. You might need to modify it to work with these struct types.

### Features

We want the following features:

When running this program, ask the user to "login". (Simply have them type their name.) If their handle doesn't match one of the existing users, create one. We will use this to display the correct feed for this user.
Display a menu with the following options:
1. Follow a user. [adds the handle to the "following" list. user must exist.]
2. Unfollow a user.
3. View tweets. [list of your own tweets]
4. View tweets + mentions. [own tweets + tweets that mention you]
5. View feed. [list of tweets of those you follow]
6. Logout. [useful for testing. prompt login after this and don't delete any data]
7. Exit

### Requirements

See rubric for grading on Labs. In addition to that, this lab must:

- Use forEach with lambda (where it makes sense).
- Use find or any or removeIf with lambda (depending on how you implement).
- Use the append/deleteAll that we've created (modifying is ok).

