#include <iostream>

int main() {
  int * num = new int[5]{};

  for (int i = 0; i < 5; ++i) {
    std::cout << num[i] << std::endl;
  }

  delete[] num;
  return 0;
}
