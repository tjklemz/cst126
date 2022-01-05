#include <iostream>
#include <fstream>

int main() {
  char buffer[100] = {'\0'};
  char lines[100][100] = {'\0'};

  std::ifstream fin("words.txt");

  int n = 0;
  while (fin.getline(buffer, 99)) {
    strcpy(lines[n], buffer);
    ++n;
  }

  std::cout << "there are " << n << " lines" << std::endl;
  for (int i = 0; i < n; ++i) {
    std::cout << lines[i] << std::endl;
  }

  return 0;
}
