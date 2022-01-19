#include <iostream>
#include <fstream>
#include <cstring>

int main() {
  char buffer[100]{};
  char lines[100][100]{};

  std::ifstream f{"words.txt"};

  int n{};
  while (f.getline(buffer, 99)) {
    std::strcpy(lines[n++], buffer);
  }

  std::cout << "there are " << n << " lines" << std::endl;
  for (int i{}; i < n; ++i) {
    std::cout << lines[i] << '\n';
  }
}
