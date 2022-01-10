#include <iostream>

struct Point {
  int x;
  int y;
};

int main() {
  Point p; // no initializer, so we get whatever is in memory (garbage):
  std::cout << "p: " << p.x << ' ' << p.y << '\n';

  Point p1{}; // default initializer, both zeros by default
  std::cout << "p1: " << p1.x << ' ' << p1.y << '\n';

  Point * p2 = new Point{}; // default initializer, but allocated on the heap
  // have to use "->" instead of "." for pointers:
  std::cout << "p2: " << p2->x << ' ' << p2->y << '\n';

  Point p3{1}; // x = 1, y = 0 which is default
  std::cout << "p3: " << p3.x << ' ' << p3.y << '\n';

  Point p4{2, 3}; // x = 2, y = 3
  std::cout << "p4: " << p4.x << ' ' << p4.y << '\n';
}
