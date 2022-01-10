#include <iostream>
#include <cstring>

void append(char **& arr, int n, const char * item) {
  char ** newArr = new char * [n + 1];
  for (int i = 0; i < n; ++i) {
    newArr[i] = arr[i];
  }
  char * newItem = new char[strlen(item) + 1];
  std::strcpy(newItem, item);
  newArr[n] = newItem;

  delete[] arr;
  arr = newArr;
}

void deleteAll(char **& arr, int &n) {
  for (int i = 0; i < n; ++i) {
    delete[] arr[i];
  }

  delete[] arr;
  arr = nullptr;
  n = 0;
}

int main() {
  int n{};
  char ** lines{};

  append(lines, n++, "bob");
  append(lines, n++, "hello world");
  append(lines, n++, "yo yo yo");

  for (int i = 0; i < n; ++i) {
    std::cout << lines[i] << '\n';
  }

  deleteAll(lines, n);
}
