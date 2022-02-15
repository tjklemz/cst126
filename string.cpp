#include <iostream>
#include "string.hpp"

int main() {
  String s1{"emma"};
  String s2{"emma"};

  std::cout << "these should be true:\n";
  std::cout << (s1 == s2) << '\n';
  std::cout << (s1 == "emma") << '\n';
  std::cout << ("emma" == s1) << '\n';

  String s3{"zendaya"};

  std::cout << "\nthese should be false:\n";
  std::cout << (s3 == s1) << '\n';
  std::cout << (s3 == "kirsten") << '\n';
  std::cout << ("kirsten" == s3) << '\n';
}
