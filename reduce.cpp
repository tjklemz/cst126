#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using std::unordered_map;
using std::vector;
using std::string;


template <typename T, typename K>
void append(vector<T> & v, const K & item) {
  v.push_back(T{item});
}

template <typename T, typename F>
void forEach(const vector<T> & v, F fn) {
  for (size_t i{}; i < v.size(); ++i) {
    fn(v[i]);
  }
}

template <typename T, typename F, typename K>
K reduce(const vector<T> & v, F fn, K acc) {
  forEach(v, [&](const auto & item) {
    acc = fn(acc, item);
  });
  return acc;
}

int main() {
  vector<string> strs{};
  append(strs, "amir");
  append(strs, "katherine");
  append(strs, "mahmoud");

  auto items = reduce(strs, [](auto acc, auto item) {
    acc[item] = true;
    return acc;
  }, unordered_map<string, bool>{});

  for (const auto & [key, value] : items) {
    std::cout << key << ": " << value << '\n';
  }
}
