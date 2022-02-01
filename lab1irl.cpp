#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

int main() {
  std::unordered_map<std::string, int> words{};
  std::ifstream f{"words.txt"};
  std::string line{};
  while (std::getline(f, line)) {
    ++words[line];
  }

  for (const auto & [key, value] : words) {
    std::cout << key << ' ' << value << '\n';
  }
}
