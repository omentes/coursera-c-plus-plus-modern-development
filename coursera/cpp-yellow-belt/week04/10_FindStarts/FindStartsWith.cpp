
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    char prefix) {
  string first(1, prefix);
  auto start = lower_bound(range_begin, range_end, first);
  string second(1, ++prefix);
  auto last = upper_bound(range_begin, range_end, second);
  return make_pair(start, last);
}

