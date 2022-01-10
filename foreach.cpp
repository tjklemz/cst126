#include <iostream>

void forEach(const char * strs[], int n, void (*fn)(const char *)) {
  for (int i = 0; i < n; ++i) {
    fn(strs[i]);
  }
}

void print(const char * s) {
  std::cout << s << '\n';
}

int main() {
  const char * strs[]{"bob", "joe", "frank"};

  // we can pass "print", since a function is an address:
  forEach(strs, 3, print); // 3 is length of strs

  // we can assign our function to a pointer if we want:
  void (*p)(const char *) = print;
  forEach(strs, 3, p);

  // ...that function pointer looks ugly.
  // let's use the new "auto" keyword:
  auto myFunc = print;
  forEach(strs, 3, myFunc);

  // let's create a function on the fly! (lambda)
  forEach(strs, 3, [](const char * s) {
    std::cout << s << '\n';
  });

  // no need to explicitly list the argument type (const char *).
  // instead, make the compiler do the work with "auto"!
  forEach(strs, 3, [](auto s) {
    std::cout << s << '\n';
  });

  // we can also assign like before (all the "autos"!):
  auto myLambda = [](auto s) {
    std::cout << s << '\n';
  };
  forEach(strs, 3, myLambda);
}
