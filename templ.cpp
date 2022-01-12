#include <iostream>

template <typename T, typename F>
void forEach(T items[], int n, F fn) {
  for (int i{}; i < n; ++i) {
    fn(items[i]);
  }
}

int main() {
  int nums[]{1, 2, 3, 4};
  float locs[]{0.5f, 1.5f, 2.5f, 3.5f};

  auto print = [](auto item) {
    std::cout << item << '\n';
  };

  forEach(nums, 4, print);
  forEach(locs, 4, print);
}
