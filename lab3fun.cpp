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
void forEach(vector<T> v, F fn) {
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

int main() {
  vector<Tweet> tweets{};

  std::ifstream f{"tweets.txt"};
  char buffer[256]{};
  while (f.getline(buffer, 255)) {
    char handle[16]{};
    char text[141]{};
    std::sscanf(buffer, "%s %[^\n]", handle, text);
    Tweet tweet{handle, text};
    append(tweets, tweet);
  }

  auto names = uniq(map(tweets, [](const auto & tweet) {
    return tweet.creator;
  }));

  auto users = map(names, [](const auto & name) {
    return User{name};
  });

  forEach(users, [](const auto & user) {
    std::cout << user.handle << '\n';
  });
}
