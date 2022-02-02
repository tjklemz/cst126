#include <iostream>

int main() {
  const char * s{"hello"};
  int flags{};
  flags |= (1 << (s[0] - 'a'));
  std::cout << (flags & (1 << ('h' - 'a'))) << '\n';
}
