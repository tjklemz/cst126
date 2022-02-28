#include <iostream>

// factorial, e.g. 5! = 5*4*3*2*1
// defined recursively
int fact(int n) {
  if (n < 2) return 1;

  return n*fact(n-1);
}

// an example callstack:
// 5*fact(5-1)
// 5*4*fact(4-1)
// 5*4*3*fact(3-1)
// 5*4*3*2*fact(2-1)
// 5*4*3*2*1, reached the end condition, now begins to pop off the stack
// 5*4*3*2
// 5*4*6
// 5*24
// 120

// 5! -> 5*4*3*2*1
// 0! -> 1

int main() {
  std::cout << fact(5) << '\n';
}
