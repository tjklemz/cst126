#include <type_traits>
#include <iostream>
#include <cstddef>
#include "string.hpp"

using std::size_t;

template <typename T>
struct Vector {
  T * items{};
  size_t length{};

  // keep in mind the "Rule of Three" is missing
  // so there is not yet proper memory management
  // (you have to build that)
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

template <typename T, typename F>
auto filter(const Vector<T> & v, F fn) {
  Vector<T> filtered{};
  forEach(v, [&](const T & item) {
    if (fn(item)) {
      append(filtered, item);
    }
  });
  return filtered;
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
  append(v, "boss");

  auto print = [](const auto & item) {
    std::cout << item << '\n';
  };

  auto capitalize = [](const String & str) {
    String newStr{str};
    newStr.s[0] += 'A' - 'a';
    return newStr;
  };

  auto startsWithB = [](const auto & item) {
    return item.s[0] == 'b';
  };
  auto v2 = filter(v, startsWithB);
  auto v3 = map(v2, capitalize);
  forEach(v3, print);

  deleteAll(v);
  deleteAll(v2);
  deleteAll(v3);
}
