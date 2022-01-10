#include <iostream>
#include <fstream>
#include <cstring>

int main() {
  char buffer[100]{};
  char lines[100][100]{};

  std::ifstream f("words.txt");

  int n = 0;
  while (f.getline(buffer, 99)) {
    std::strcpy(lines[n++], buffer);
  }

  std::cout << "there are " << n << " lines" << std::endl;
  for (int i = 0; i < n; ++i) {
    std::cout << lines[i] << '\n';
  }
}
