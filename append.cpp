#include <type_traits>
#include <iostream>
#include <cstddef>
using std::size_t;

template <typename T, typename F>
void append(T *& items, size_t & n, F createItem) {
  T * newItems = new T[n + 1]{};
  for (size_t i{}; i < n; ++i) {
    newItems[i] = items[i];
  }

  newItems[n] = createItem();

  delete[] items;
  items = newItems;
  ++n;
}

template <typename T, typename F>
void forEach(T items[], size_t n, F fn) {
  for (size_t i{}; i < n; ++i) {
    fn(items[i]);
  }
}

template <typename T>
void deleteAll(T *& items, size_t & n) {
  if constexpr (std::is_pointer_v<T>) {
    for (size_t i{}; i < n; ++i) {
      delete[] items[i];
    }
  }
  delete[] items;
  items = nullptr;
  n = 0;
}

char * copy(const char * s) {
  char * newItem = new char[std::strlen(s) + 1]{};
  std::strcpy(newItem, s);
  return newItem;
}

auto id = [](auto x) {
  return [=]() { return x; };
};

int main() {
  // create a lambda that we'll reuse down below
  auto print = [](auto item) { std::cout << item << '\n'; };

  auto get1 = id(1);
  print(get1());
  print(id(1)());

  // let's append ints...
  int * nums{};
  size_t n{};

  append(nums, n, id(1));
  forEach(nums, n, print);

  deleteAll(nums, n);

  char ** strs{};
  size_t numStrs{};

  // calls copy immediately
  append(strs, numStrs, id(copy("bob")));
  // or, slightly different way, where copy gets called later instead of immediately:
  append(strs, numStrs, []() {
    return copy("sally");
  });

  forEach(strs, numStrs, print);

  deleteAll(strs, numStrs);
}
