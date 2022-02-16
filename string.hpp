#pragma once

#include <cstring>

struct String {
  char * s{};
  int n{};

  String(const char * cstr = "") {
    this->n = std::strlen(cstr);
    this->s = new char[n + 1]{};
    std::strcpy(this->s, cstr);
  }

  String(const String & other) : String(other.s) {}

  String & operator=(const String & other) {
    if (this == &other) {
      return *this;
    }

    std::size_t n{std::strlen(other.s) + 1};
    char* new_cstring = new char[n]{};
    std::strcpy(new_cstring, other.s);

    delete[] this->s;
    this->s = new_cstring;
    this->n = n;

    return *this;
  }

  bool operator==(const char * other) const {
    return !std::strcmp(this->s, other);
  }

  bool operator==(const String & other) const {
    return this->operator==(other.s);
  }

  ~String() {
    delete[] this->s;
  }

  operator const char * () const {
    return this->s;
  }
};

