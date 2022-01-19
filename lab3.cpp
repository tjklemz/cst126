#include <iostream>
#include <fstream>
#include <cstring>

struct User {
  char handle[16];
  int numFollowing;
  char ** following;
};

struct Tweet {
  char text[141];
  char creator[16];
};

int main() {
  std::ifstream f{"tweets.txt"};
  char buffer[256]{};
  Tweet ** tweets{};

  while(f.getline(buffer, 255)) {
    // don't use these... use a Tweet struct!
    char name[16]{};
    char text[141]{};
    std::sscanf(buffer, "%s %[^\n]", name, text);
    std::cout << name << ' ' << text << '\n';
  }
}
