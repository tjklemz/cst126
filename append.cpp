#include <type_traits>
#include <iostream>
#include <cstddef>
using std::size_t;

template <typename T>
struct Vector {
  T * items;
  size_t length;
};

template <typename T, typename F>
void append(Vector<T> & v, F createItem) {
  T * newItems = new T[v.length + 1]{};
  for (size_t i{}; i < v.length; ++i) {
    newItems[i] = v.items[i];
  }

  newItems[v.length] = createItem();

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
  if constexpr (std::is_pointer_v<T>) {
    for (size_t i{}; i < v.length; ++i) {
      delete[] v.items[i];
    }
  }
  delete[] v.items;
  v.items = nullptr;
  v.length = 0;
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
  Vector<int> v{};

  append(v, id(42));
  append(v, id(36));

  transform(v, [](auto item) {
    return item * 2;
  });

  forEach(v, [](auto item) {
    std::cout << item << '\n';
  });

  deleteAll(v);
}
