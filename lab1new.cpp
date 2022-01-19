#include <iostream>
#include <fstream>
#include <cstring>

int findIndex(char ** items, int n, const char * item) {
  for (int i{}; i < n; ++i) {
    if (std::strcmp(items[i], item) == 0) {
      return i;
    }
  }
  return -1;
}

bool exists(char ** items, int n, const char * item) {
  return findIndex(items, n, item) >= 0;
}

void append(char **& items, int n, const char * item) {
  char ** newItems = new char * [n + 1]{};
  for (int i{}; i < n; ++i) {
    newItems[i] = items[i];
  }

  char * newItem = new char [std::strlen(item) + 1]{};
  std::strcpy(newItem, item);
  newItems[n] = newItem;

  delete[] items;
  items = newItems;
}

void append(int *& items, int n, int item) {
  int * newItems = new int[n + 1]{};
  for (int i{}; i < n; ++i) {
    newItems[i] = items[i];
  }

  newItems[n] = item;

  delete[] items;
  items = newItems;
}

int main() {
  char ** words{};
  int * nums{};
  int n{};

  std::ifstream f{"words.txt"};
  char buffer[256]{};

  while (f.getline(buffer, 255)) {
    int index = findIndex(words, n, buffer);
    if (index < 0) {
      append(words, n, buffer);
      append(nums, n, 1);
      ++n;
    } else {
      ++nums[index];
    }
  }

  for (int i{}; i < n; ++i) {
    std::cout << words[i] << ' ' << nums[i] << '\n';
  }

  for (int i{}; i < n; ++i) {
    delete[] words[i];
  }
  delete[] words;
  delete[] nums;
}
