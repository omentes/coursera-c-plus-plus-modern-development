#include <algorithm>
#include <set>

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