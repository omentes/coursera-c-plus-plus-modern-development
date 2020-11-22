#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include "reload.h"

using namespace std;

set<int>::const_iterator FindNearestElement(
    const set<int>& numbers,
    int border) {
  if (numbers.empty()) {
    return numbers.begin();
  }
  auto lower = numbers.lower_bound(border);
  if (*lower == border) {
    return lower;
  }
  auto lower2 = lower_bound(numbers.begin(), prev(lower), border);
  if (*lower - border >= border - *lower2 || border - *lower > border - *lower2) {
    return lower2;
  }
  return lower;
}
// set<int>::const_iterator —
// тип итераторов для константного множества целых чисел

int main() {
  set<int> numbers = {1, 4, 6};
  cout <<
       *FindNearestElement(numbers, 0) << " " << // 1
       *FindNearestElement(numbers, 3) << " " << // 4
       *FindNearestElement(numbers, 5) << " " << // 4
       *FindNearestElement(numbers, 6) << " " << // 6
       *FindNearestElement(numbers, 100) << endl; // 6

  set<int> empty_set;
//
  cout << (FindNearestElement(empty_set, 8) == end(empty_set)) << endl;
  return 0;
}
