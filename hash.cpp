#include <iostream>
#include <iomanip>
#include <cstddef>
using std::size_t;

// K&R hash, the simplest hash
size_t hash(const char * s) {
  size_t h{};
  for (size_t i{}; s[i]; ++i) {
    h += s[i];
  }
  return h;
}

// djb2 hash, a very good distribution
// http://www.cse.yorku.ca/~oz/hash.html
size_t hash2(const char * s) {
  size_t h{};
  for (size_t i{}; s[i]; ++i) {
    h = h * 33 + s[i]; // no one's sure why 33
  }
  return h;
}

int main() {
  const char * strs[]{
    "bob",
    "frank",
    "joe",
    "sally",
    "susan",
  };

  std::cout << "---- K&R hash ----\n\n";
  for (size_t i{}; i < 5; ++i) {
    std::cout << std::setw(6)
      << strs[i] << ": "
      << std::setw(12)
      << hash(strs[i]) << " -> "
      << hash(strs[i]) % 5 << '\n';
  }

  std::cout << "\n---- djb2 hash ----\n\n";
  for (size_t i{}; i < 5; ++i) {
    std::cout << std::setw(6)
      << strs[i] << ": "
      << std::setw(12)
      << hash2(strs[i]) << " -> "
      << hash2(strs[i]) % 5 << '\n';
  }
}
