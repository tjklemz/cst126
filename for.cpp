#include <iostream>

int main() {
  int nums[]{1, 2, 3, 4, 5};

  for (auto n : nums) {
    std::cout << n << '\n';
  }

  std::cout << '\n';

  const char * strs[]{
    "bob",
    "george",
    "calvin",
    "susan"
  };

  for (auto s : strs) {
    std::cout << s << '\n';
  }
}
