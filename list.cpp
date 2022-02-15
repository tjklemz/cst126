#include <type_traits>
#include <cstddef>
#include <iostream>

using std::size_t;

template <typename T>
struct Node {
  T data;
  Node * next;
};

template <typename T>
struct List {
  Node<T> * head;
  Node<T> * tail;
  size_t length;

  // default ctor
  // we're not doing anything besides the default... so use the default :)
  // no need to change anything here
  List() = default;

  // copy ctor
  List(const List<T> & other) {
    // copy everything over
    // remember, this is a ctor, so there's nothing to cleanup
  }

  // copy assignment
  List & operator=(const List<T> & other) {
    // pointer comparison (shallow compare) to make sure we're not assigning to ourself
    // see, sometimes pointer comparisons are okay :)
    if (this == &other) {
      return *this;
    }

    // do the copying here, and remember to clean anything up (since this is _not_ a ctor)

    // return our brand new self
    return *this;
  }

  // dtor
  ~List() {
    // clean up
  }

  bool empty() const {
    return false; // do actual logic here
  }
};

template <typename T, typename K>
void append(List<T> & list, const K & item) {
  T data{item}; // convert the type if needed from "K" to "T", e.g. "char *" to "String"
  Node<T> * newItem = new Node<T>{data};

  // logic here...
}

template <typename T>
T first(const List<T> & list) {
  return T{}; // change this to actually return the first item
}

template <typename T>
T last(const List<T> & list) {
  return T{}; // change this to actually return the last item
}

template <typename T, typename F>
void forEach(const List<T> & list, F fn) {

}

// this is sometimes called "exists" or "has" or "contains"
template <typename T>
bool includes(const List<T> & list, const T & item) {
  return false; // change this to actually work
}

template <typename T, typename F>
List<T> filter(const List<T> & list, F fn) {
  List<T> l{};
  return l;
}

template <typename T, typename F>
void removeIf(List<T> & list, F fn) {

}

// using "auto" for the return since we want List<K>, but K is internal
template <typename T, typename F>
auto map(const List<T> & list, F fn) {
  using K = std::invoke_result_t<F, T>;

  List<K> l{};
  return l;
}

template <typename T, typename F>
void transform(List<T> & list, F fn) {

}

// create a new List that is both "a" and "b" (may include duplicates, i.e. simple)
template <typename T>
List<T> concat(const List<T> & a, const List<T> & b) {
  List<T> l{};
  return l;
}

template <typename T>
List<T> uniq(const List<T> & list) {
  List<T> l{};
  return l;
}

// similar to "concat" but removes duplicates (hint: concat + uniq)
template <typename T>
List<T> set_union(const List<T> & a, const List<T> & b) {
  List<T> l{};
  return l;
}

template <typename T>
List<T> set_intersection(const List<T> & a, const List<T> & b) {
  List<T> l{};
  return l;
}

template <typename T>
List<T> set_difference(const List<T> & a, const List<T> & b) {
  List<T> l{};
  return l;
}

// this is also called "symmetric difference"
template <typename T>
List<T> set_xor(const List<T> & a, const List<T> & b) {
  List<T> l{};
  return l;
}


// could declare this almost anywhere
auto print = [](const auto & item) {
  std::cout << item << '\n';
};

int main() {
  List<int> a{};

  append(a, 12);
  append(a, 42);
  append(a, 27);

  List<int> b{a}; // this should end up calling the copy ctor!

  append(b, 42);
  append(b, 1337);

  List<int> c{};
  c = b;
  append(c, 9000);

  std::cout << "a:\n";
  forEach(a, print);

  std::cout << "b:\n";
  forEach(b, print);

  std::cout << "c:\n";
  forEach(c, print);
}
