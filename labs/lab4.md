# Lab 4: Hashtable

It is now time to build a hashtable, a type of the category we've been calling "bags".

We will only worry about inserting and finding items — no deletion (aside from cleanup).

## Part 0:

Download and run the following code (click on "raw" and then copy or right-click-save-as). This will be our starting point. Be sure you understand how the hash function works.

https://github.com/tjklemz/cst126/blob/main/hashtable.cpp

## Part 1:  Linear Probing

The hashtable.cpp code is stubbed with some insert calls. The "capacity" tells us how many buckets we have but not how many items. We are starting with 100 buckets, and we're trying to insert two items using the keys "bob" and "sally". For starters, the values will just be integers (see the Bucket struct). So:  the key+value storage is a c-string+int hashtable. We give it "bob", we expect an integer (both for getting and setting).

Note that "buckets" could be allocated on the stack here, since we know the capacity. But, since we might want to resize it later, we'll dynamically allocate. We'll look at how resizing will work later.

A) implement the "insert" function using linear probing to find available slots when there is an index collision. You will need to implement and use the "copy" function in order to store a key in a bucket.

B) print out the keys and values in the for-loop in main. Make sure to check if a bucket exists (i.e. not empty — check against nullptr).

C) implement "deleteBuckets". This should loop through and use "deleteBucket", which you should also implement.

D) check that your insert allows for overwriting. For instance, inserting "bob" again should overwrite that slot with the new value.

E) write a "get" function that returns a pointer to a Bucket (i.e. Bucket *) given a key (const char *). Test it out in main and be sure you can retrieve "bob", etc. The "get" function should work when nothing was found (simply return a nullptr). Test this out in main, too.

F) write a "size" function that returns a size_t of how many buckets are being used (i.e. how many items we actually have, not the capacity). Test this in main, printing out the size.


## Part 2:  Word Frequencies


Instead of hard-coding what we're putting into the buckets, let's read from our Lab 1 file, words.txt. If you don't have it, create a text file that has one word (or a phrase) per line. They can be all lowercase, but have some duplicate words/phrases.

Read in that file using our techniques from Lab 2 and Lab 3. Simply call insert with the word/phrase as the key. The value will be the frequency. Use the "get" function to see if you already have it in your buckets. If you do have it, simply increment the frequency in that bucket. If you don't have it, insert the key with a value of 1.


## Part 3:  More Structs

It's annoying to be passing around the capacity all the time. Let's wrap our structure inside another structure:

```c++
struct Hashtable {
  size_t capacity;
  Bucket ** buckets;
};

// initialize in main like so:
Hashtable ht{100, new Bucket * [100]{}}; // look at https://github.com/tjklemz/cst126/blob/main/structs.cpp if this is confusing

// you can also do:
Hashtable ht{};
ht.capacity = 100;
ht.buckets = new Bucket * [ht.capacity]{};

// or:
Hashtable * ht = new Hashtable{100, new Bucket * [100]{}};
// etc
```

Change all of the appropriate functions that work with buckets (e.g. insert, get) to now work with this Hashtable struct. Your delete functions might be fine, buy you might want another delete function that works with the other deletes (e.g. have a deleteHashtable that then calls deleteBuckets and so forth).

Part 4:  Templating

A) Create a forEach function that works with the Hashtable. You can have the lambda function that is passed to "forEach" take either a Bucket pointer/reference or two arguments (the key and then the value):  fn(bucket) or fn(key, value). Remember that your forEach logic is going to be different than our other forEach's. You want to extract your looping/printing code from main.

B) The Hashtable currently is a key-value storage from c-string to integers. Let's template that value type:

```c++
template <typename T>
struct Bucket {
  char * key;
  T value;
};

template <typename T>
struct Hashtable {
  size_t capacity;
  Bucket<T> ** buckets;
};

// then in main:
Hashtable<int> ht{100, new Bucket<int> * [100]{}}; // one option for instantiating; could also use "new" etc
```

Note:  you'll need to update your functions to be templated. Since the main type is templated, that propagates everywhere it gets used (since it's part of the type now). There's no longer a type "Hashtable", rather there is a templated type "Hashtable<T>" (or whatever you use for T).

We are only templating the value, but keep in mind some languages (even C++) allow any type that can be hashed for the key (i.e. not just a c-string — you could have a hashtable that is a key-value of struct Point -> float, or whatever you wanted). But other languages, such as JavaScript, only allow a string for the key. You will find IRL that strings are the most flexible, but there are instances to use other things for keys. We won't worry about hashing non-c-strings for this class, but it follows that same principle:  somehow take multiple scalars and convert them to a single number = the hash.

Extra Credit:

Try storing another type in the bucket instead of the built-ins (like int, float, etc). You should only need to modify main (i.e. your insert/get/etc functions should not need to be modified). Create a struct type that holds some useful information, say, the word length as well as the frequency:

```c++
struct WordMeta {
  size_t freq; // the frequency
  size_t len; // length of the word
  size_t uniq; // number of unique characters (see Quiz 2)
};
```

When you read in the words/phrases from your text file, fill in this meta and put it in the bucket. So you should have a Hashtable<WordMeta> type in main.
