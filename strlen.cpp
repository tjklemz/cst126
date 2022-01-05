#include <iostream>

int strlen(char * str) {
  int i{};
  while (str[i++]);
  return i-1;
}

int main(int argc, char ** argv) {
  if (argc != 2) {
    std::cerr << "Incorrect usage. Please pass exactly one string.\n";
    return -1;
  }
  std::cout << strlen(argv[1]) << std::endl;
  return 0;
}
