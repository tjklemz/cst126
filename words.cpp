#include <iostream>
#include <fstream>

int mystrlen(const char * s) {
  int i{-1};
  while (s[++i]);
  return i;
}

void mystrcpy(char * dest, const char * src) {
  int i{};
  while (src[i]) {
    dest[i] = src[i];
    ++i;
  }
  dest[i] = '\0';
}

int main() {
  char words[100][100]{};
  int n{};

  char buffer[100]{};
  std::ifstream f{"words.txt"};
  while (f.getline(buffer, 99)) {
    mystrcpy(words[n], buffer);
    ++n;
  }
  std::cout << n << " words" << '\n';
  for (int i{}; i < n; ++i) {
    std::cout << words[i] << ' ' << mystrlen(words[i]) << '\n';
  }

  double avg{};
  for (int i{}; i < n; ++i) {
    avg += mystrlen(words[i]);
  }
  avg /= n;
  std::cout << "avg: " << avg << '\n';
}
