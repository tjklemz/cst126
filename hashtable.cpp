#include <iostream>
#include <cstddef>

std::size_t hash(const char * s) {
  std::size_t h{};
  while (*s++) {
    h = h * 33 + s[0];
  }
  return h;
}

char * copy(const char * s) {
  // allocate a new char * and return it
  // don't forget to include <cstring>
  return nullptr; // stub, replace
}

struct Entry {
  char * key;
  int value;
};

// used only for cleanup
void deleteEntry(Entry *& entry) {
  // ☠️
}

// used only for cleanup
void deleteEntries(Entry **& ht, std::size_t capacity) {
  // 🧨
  // loop thru and delete each entry
  // then delete the container
}

void insert(Entry ** ht, std::size_t capacity, const char * k, int v) {
  // create an index based on the hash of the key and the available capacity
  // then insert into the list
}

int main() {
  std::size_t capacity{20};
  Entry ** ht = new Entry * [capacity]{};

  insert(ht, capacity, "bob", 42);
  insert(ht, capacity, "sally", 35);

  std::cout << hash("bob") << ' ' << hash("sally") << '\n';

  for (std::size_t i{}; i < capacity; ++i) {
    // print out the key+value pair...
  }

  deleteEntries(ht, capacity);
}
