#include <type_traits>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstddef>
using std::size_t;

template <typename T, typename F>
void append(T *& items, size_t & n, F createItem) {
  T * newItems = new T[n + 1]{};
  for (size_t i{}; i < n; ++i) {
    newItems[i] = items[i];
  }

  newItems[n] = createItem();

  delete[] items;
  items = newItems;
  ++n;
}

template <typename T, typename F>
void forEach(T * items, size_t n, F fn) {
  for (size_t i{}; i < n; ++i) {
    fn(items[i]);
  }
}

template <typename T, typename F>
size_t findIndex(T * items, size_t n, F comparator) {
  for (size_t i{}; i < n; ++i) {
    if (comparator(items[i])) {
      return i;
    }
  }
  return -1;
}

template <typename T>
void deleteAll(T *& items, size_t & n) {
  if constexpr (std::is_pointer_v<T>) {
    for (size_t i{}; i < n; ++i) {
      delete[] items[i];
    }
  }
  delete[] items;
  items = nullptr;
  n = 0;
}

char * copy(const char * s) {
  char * newItem = new char[std::strlen(s) + 1]{};
  std::strcpy(newItem, s);
  return newItem;
}

auto id = [](auto x) {
  return [=]() { return x; };
};

struct User {
  char handle[16];
  size_t numFollowing;
  char ** following;
};

struct Tweet {
  char text[141];
  char creator[16];
};

int main() {
  Tweet ** tweets{};
  size_t numTweets{};

  std::ifstream f{"tweets.txt"};
  char buffer[256]{};
  while(f.getline(buffer, 255)) {
    Tweet * tweet = new Tweet{};
    std::sscanf(buffer, "%s %[^\n]", tweet->creator, tweet->text);
    append(tweets, numTweets, id(tweet));
  }

  char currentUser[16]{};
  std::cout << "login: ";
  std::cin.getline(currentUser, 15);

  forEach(tweets, numTweets, [=](auto tweet) {
    if (!std::strcmp(tweet->creator, currentUser)) {
      std::cout << tweet->creator << ": " << tweet->text << '\n';
    }
  });

  char userToFind[16]{};
  std::cout << "find: ";
  std::cin.getline(userToFind, 255);
  size_t index = findIndex(tweets, numTweets, [=](auto tweet) {
    return !std::strcmp(tweet->creator, userToFind);
  });

  if (index >= 0) {
    Tweet * tweet = tweets[index];
    std::cout << tweet->creator << ": " << tweet->text << '\n';
  } else {
    std::cout << "not found" << '\n';
  }

  deleteAll(tweets, numTweets);
}
