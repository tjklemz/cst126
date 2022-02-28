#pragma once

// this is a stub
// you'll need to fill out the ctors/etc
struct Vector {
  int * items;
  size_t length;

  Vector() = default;

  // copy ctor
  Vector(const Vector & other) {

  }

  // copy assignment
  Vector & operator=(const Vector & other) {
    if (this == &other) {
      return *this;
    }

    // code here...

    return *this;
  }

  // dtor
  ~Vector() {

  }
};
