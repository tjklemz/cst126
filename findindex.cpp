#include <iostream>
#include <cstring>
#include <cstddef>
using std::size_t;

// this findIndex will now work for any array
template <typename T, typename F>
size_t findIndex(T * arr, size_t n, F comparator) {
  for (size_t i{}; i < n; ++i) {
    if (comparator(arr[i])) {
      return i;
    }
  }
  return -1;
}

int main() {
  const char * item = "frank";

  const char * strs[]{"bob", "frank", "sally"};
  auto myLambda = [&item](auto current) {
    return std::strcmp(current, item) == 0;
  };

  auto index = findIndex(strs, 3, myLambda);
  std::cout << "index: " << index << '\n';

  for (auto item : strs) {
    std::cout << item << '\n';
  }
}
