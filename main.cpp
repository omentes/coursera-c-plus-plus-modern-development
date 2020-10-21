#include <iostream>
#include <map>
#include <vector>

using namespace std;
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


int main() {

  cout << Sqr(2) << endl;
  cout << Sqr(9.99) << endl;

  vector<int> v = {1, 2, 3};
  cout << "vector:";
  for (int x : Sqr(v)) {
    cout << ' ' << x;
  }
  cout << endl;

  map<int, pair<int, int>> map_of_pairs = {
      {4, {2, 2}},
      {7, {4, 3}}
  };
  cout << "map of pairs:" << endl;
  for (const auto& x : Sqr(map_of_pairs)) {
    cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
  }
  return 0;
}
