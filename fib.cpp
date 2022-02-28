#include <iostream>

// fibonacci sequence, recursive
int fib(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  return fib(n-1) + fib(n-2);
}

int main() {
  // print out the 7th fibonacci number
  std::cout << fib(7) << '\n';
}
