#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

template <typename T>
vector<T> FindGreaterElements(const set<T>& elements, const T& border) {
  vector<T> result;
  copy_if(elements.begin(), elements.end(), back_inserter(result), [border](T current) {
    return current > border;
  });
  return result;
}