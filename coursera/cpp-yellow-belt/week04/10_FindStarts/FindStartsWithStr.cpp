#include <string>
#include <vector>
#include <algorithm>

using namespace std;


template <typename RandomIt>
pair<RandomIt, RandomIt> FindStartsWith(
    RandomIt range_begin, RandomIt range_end,
    const string& prefix) {

  return equal_range(
      range_begin,
      range_end,
      prefix,
      [&prefix](const string& lhs, const string& rhs) {
        return lhs.compare(0, prefix.length(), rhs.substr(0, prefix.length())) < 0;
      }
  );
};
