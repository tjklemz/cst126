# Lab 1: Word Frequency

Lab 1 will be based on exercise 2 in 12.20 in our textbook (p. 398 in the 201901 edition) with the added element of command line arguments. We will be learning how to break down a problem, understanding the scope of it, and lots of string and array manipulation.

From the book:

Write a program that reads in a text file a word at a time. Store the word into a dynamically created array the first time this word has been encountered. Create a parallel integer array to hold a count of the number of times that each particular word appeared in the text file. If the word appears in the text file multiple times do not add it into your dynamic array, but make sure to increment the corresponding punctuation from all words before doing any comparisons.

Create and use the following text file containing a quote from Albert Einstein to test your program.

The definition of insanity is doing the same thing over and over and expecting different results.

At the end of your program, generate a report that prints the contents of your two arrays in a format similar to the following:

```
Word        Frequency
The         2
definition  1
Of          1
insanity    1
over        2
and         2
```

Once your program works with the test file shown above, create a much bigger file and rerun your program to see if it still works correctly.

-----------

We will want an additional, simple feature: To be able to specify the file on the command line when running the program. Example: `./myprogram file.txt`

We will go over this in the lab. To start with, we'll hardcode our file name in our program.
