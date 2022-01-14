#include <iostream>

template <typename T>
void append(T *& items, int n, T item) {
  T * newItems = new T[n + 1]{};
  for (int i{}; i < n; ++i) {
    newItems[i] = items[i];
  }
  newItems[n] = item;

  delete[] items;
  items = newItems;
}

template <typename T, typename F>
void forEach(T items[], int n, F fn) {
  for (int i{}; i < n; ++i) {
    fn(items[i]);
  }
}

int main() {
  // create a lambda that we'll reuse down below
  auto print = [](auto item) { std::cout << item << '\n'; };

  // let's append ints...
  int * nums{};
  int n{};

  append(nums, n++, 1);
  forEach(nums, n, print);

  delete[] nums; // append called "new" so we need to delete

  // let's append floats. it should work the same way:
  float * fs{};
  int fN{};

  append(fs, fN++, 0.5f);
  forEach(fs, fN, print);

  delete[] fs; // append called "new" so we need to delete
}
