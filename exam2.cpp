#include <iostream>
#include <cstring>

size_t mystrlen(const char * s) {
  size_t i{};
  while (s[i]) {
    ++i;
  }
  return i;
}

bool equal(const char * s1, const char * s2) {
  size_t i{};
  for (; s1[i]; ++i) {
    if (s1[i] != s2[i]) {
      return false;
    }
  }
  return s1[i] == s2[i];
}

char * copy(const char * s) {
  char * s2 = new char[std::strlen(s) + 1]{};
  std::strcpy(s2, s);
  return s2;
}

void append(char **& items, size_t & n, const char * item) {
  char ** newItems = new char * [n + 1]{};
  for (size_t i{}; i < n; ++i) {
    newItems[i] = items[i];
  }
  newItems[n] = copy(item);
  ++n;
  delete[] items;
  items = newItems;
}

void deleteAll(char **& items, size_t & n) {
  for (size_t i{}; i < n; ++i) {
    delete[] items[i];
  }
  delete[] items;
  items = nullptr;
  n = 0;
}

int main() {
  char ** names{};
  size_t numNames{};
  append(names, numNames, "bob");
  append(names, numNames, "joe");
  append(names, numNames, "sally");

  std::cout << mystrlen(names[0]) << '\n'
            << equal(names[0], "bob") << '\n'
            << equal(names[0], "bobby") << '\n';

  deleteAll(names, numNames);
}
