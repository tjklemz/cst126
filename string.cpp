#include <iostream>
#include <cstring>

struct String {
  char * s{};
  int n{};

  String() {}

  String(const char * cstr) {
    this->n = std::strlen(cstr);
    this->s = new char[n + 1];
    std::strcpy(this->s, cstr);
  }

  // NOTE:  we need more things here... we'll be covering that soon! :)

  ~String() {
    delete[] this->s;
  }
};

int main() { // beginning of lifecycle
  String s1{"hi there"};
  std::cout << s1.s << '\n';

  // we can create a lifecycle at any time
  // normally you'd have an if-statement or for-loop, etc
  // but you can actually create one whenever you want in C/C++ :)
  {
    String s2{"yo yo yo"};
    std::cout << s2.s << '\n';
  } // end of this lifecycle, s2 destructor gets called since it got created in this scope
} // end of lifecycle, again notice no delete for s1 since destructor takes care of that :)

