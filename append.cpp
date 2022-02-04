#include <type_traits>
#include <iostream>
#include <cstddef>
#include "string.hpp"

using std::size_t;

template <typename T>
struct Vector {
  T * items;
  size_t length;
};

template <typename T>
void append(Vector<T> & v, T item) {
  T * newItems = new T[v.length + 1]{};
  for (size_t i{}; i < v.length; ++i) {
    newItems[i] = v.items[i];
  }

  newItems[v.length] = item;

  delete[] v.items;
  v.items = newItems;
  ++v.length;
}

template <typename T, typename F>
void forEach(const Vector<T> & v, F fn) {
  for (size_t i{}; i < v.length; ++i) {
    fn(v.items[i]);
  }
}

template <typename T, typename F>
void transform(Vector<T> & v, F fn) {
  for (size_t i{}; i < v.length; ++i) {
    v.items[i] = fn(v.items[i]);
  }
}

template <typename T>
void deleteAll(Vector<T> & v) {
  delete[] v.items;
  v.items = nullptr;
  v.length = 0;
}

auto id = [](auto x) {
  return [=]() { return x; };
};

int main() {
  Vector<String> v{};

  append(v, String{"bob"});
  append(v, String{"sally"});

  forEach(v, [](auto item) {
    std::cout << item << '\n';
  });

  deleteAll(v);
}
