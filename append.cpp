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

template <typename T, typename K>
void append(Vector<T> & v, const K & item) {
  T * newItems = new T[v.length + 1]{};
  for (size_t i{}; i < v.length; ++i) {
    newItems[i] = v.items[i];
  }

  newItems[v.length] = T{item};

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

template <typename T, typename F>
auto map(const Vector<T> & v, F fn) {
  using K = std::invoke_result_t<F, T>;

  Vector<K> newVector{};
  forEach(v, [&](const T & item) {
    append(newVector, fn(item));
  });
  return newVector;
}

template <typename T>
void deleteAll(Vector<T> & v) {
  delete[] v.items;
  v.items = nullptr;
  v.length = 0;
}

int main() {
  Vector<String> v{};

  append(v, "bob");
  append(v, String{"sally"});

  auto print = [](const auto & item) {
    std::cout << item << '\n';
  };

  forEach(v, print);

  auto capitalize = [](const String & str) {
    String newStr{str};
    newStr.s[0] += 'A' - 'a';
    return newStr;
  };

  auto newVector = map(v, [](const String & item) {
    return std::strlen(item);
  });

  std::cout << '\n';

  forEach(newVector, print);

  deleteAll(v);
  deleteAll(newVector);
}
