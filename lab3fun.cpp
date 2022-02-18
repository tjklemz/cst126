#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct User {
  string handle;
};

struct Tweet {
  string creator;
  string text;
};

template <typename T, typename K>
void append(vector<T> & v, const K & item) {
  v.push_back(T{item});
}

template <typename T, typename F>
void forEach(const vector<T> & v, F fn) {
  for (size_t i{}; i < v.size(); ++i) {
    fn(v[i]);
  }
}

template <typename T, typename F>
auto map(const vector<T> & v, F fn) {
  using K = std::invoke_result_t<F, T>;

  vector<K> l{};
  forEach(v, [&](const auto & item) {
    append(l, fn(item));
  });
  return l;
}

template <typename T, typename K>
size_t findIndex(const vector<T> & v, const K & item) {
  for (size_t i{}; i < v.size(); ++i) {
    if (v[i] == item) {
      return i;
    }
  }
  return -1;
}

template <typename T, typename K>
bool includes(const vector<T> & v, const K & item) {
  return findIndex(v, item) != -1;
}

template <typename T, typename F>
auto filter(const vector<T> & v, F fn) {
  vector<T> l{};
  forEach(v, [&](const auto & item) {
    if (fn(item)) {
      append(l, item);
    }
  });
  return l;
}

template <typename T>
auto uniq(const vector<T> & v) {
  vector<T> l{};
  forEach(v, [&](const auto & item) {
    if (!includes(l, item)) {
      append(l, item);
    }
  });
  return l;
}

auto readLines(const char * filename) {
  vector<string> lines{};

  std::ifstream f{filename};
  char buffer[256]{};
  while (f.getline(buffer, 255)) {
    append(lines, buffer);
  }
  return lines;
}

auto createTweet(const string & s) {
  char handle[16]{};
  char text[141]{};
  std::sscanf(s.c_str(), "%s %[^\n]", handle, text);
  return Tweet{handle, text};
}

auto createUser(const string & name) {
  return User{name};
}

template <typename T>
void print(const T & item) {
  std::cout << item << '\n';
}

void print(const User & user) {
  std::cout << user.handle << '\n';
}

void print(const Tweet & tweet) {
  std::cout << tweet.creator << ": " << tweet.text << '\n';
}

template <typename T>
void print(const vector<T> & items) {
  forEach(items, [](const T & item) {
    print(item);
  });
}

int main() {
  auto tweets = map(readLines("tweets.txt"), createTweet);

  auto names = uniq(map(tweets, [](const auto & tweet) {
    return tweet.creator;
  }));

  auto users = map(names, createUser);

  print(users);
}
