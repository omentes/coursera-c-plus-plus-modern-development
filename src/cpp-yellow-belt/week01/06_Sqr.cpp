#include <iostream>
#include <map>
#include <vector>

template <typename T>
T Sqr(T x) ;

template <typename First, typename Second>
pair<First, Second> Sqr(pair<First, Second> x) {
  x.first = Sqr(x.first);
  x.second = Sqr(x.second);
  return x;
}

template <typename Key, typename T>
map<Key, T> Sqr(map<Key, T> x) {
  map<Key, T> n;
  for (auto [key, i] : x) {
    n[key] = Sqr(i);
  }
  return n;
}

template <typename T>
vector<T> Sqr(vector<T> x) {
  vector<T> n;
  for (auto i : x) {
    n.push_back(Sqr(i));
  }
  return n;
}

template <typename T>
T Sqr(T x) {
  return x*x;
}
