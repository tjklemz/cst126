#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::string;
using std::vector;

struct User {
  string handle;
  vector<string> following;
};

struct Tweet {
  string creator;
  string text;

  bool operator==(const Tweet & other) const {
    return creator == other.creator && text == other.text;
  }
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

template <typename T, typename F>
size_t findIndex(const vector<T> & v, F fn) {
  for (size_t i{}; i < v.size(); ++i) {
    if (fn(v[i])) {
      return i;
    }
  }
  return -1;
}

template <typename T, typename K>
bool includes(const vector<T> & v, const K & item) {
  auto index = findIndex(v, [&](const auto & v_item) {
    return v_item == item;
  });
  return index != -1;
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

template <typename T>
auto concat(const vector<T> & a, const vector<T> & b) {
  auto c{a};
  forEach(b, [&](const auto & item) {
    append(c, item);
  });
  return c;
}

template <typename T>
auto set_union(const vector<T> & a, const vector<T> & b) {
  return uniq(concat(a, b));
}

int main() {
  auto tweets = map(readLines("tweets.txt"), createTweet);

  auto names = uniq(map(tweets, [](const auto & tweet) {
    return tweet.creator;
  }));

  auto users = map(names, createUser);

  // "login"
  auto currentUserIndex = findIndex(users, [](const auto & user) {
    return user.handle == "@guy";
  });
  auto currentUser = users[currentUserIndex];

  // Case 1:  Following a user
  append(currentUser.following, "@bob");
  append(currentUser.following, "@joe");
  append(currentUser.following, "@sally");

  // Case 2:  Unfollowing a user
  currentUser.following = filter(currentUser.following, [](const auto & name) {
    return name != "@bob";
  });

  std::cout << "View your own tweets" << '\n';

  // Case 3:  View your own tweets
  auto myTweets = filter(tweets, [&](const auto & tweet) {
    return tweet.creator == currentUser.handle;
  });
  print(myTweets);

  std::cout << "\nView your own tweets + mentions" << '\n';

  // Case 4:  View your own tweets + mentions
  auto mentions = filter(tweets, [&](const auto & tweet) {
    return tweet.text.find(currentUser.handle) != -1;
  });
  auto tweetsAndMentions = set_union(myTweets, mentions);
  print(tweetsAndMentions);

  std::cout << "\nView feed" << '\n';

  // Case 5: View followers (feed)
  auto feed = filter(tweets, [&](const auto & tweet) {
    return includes(currentUser.following, tweet.creator);
  });
  print(feed);
}
