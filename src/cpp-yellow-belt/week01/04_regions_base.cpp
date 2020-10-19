#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

int FindMaxRepetitionCount(const vector<Region> &regions) {
  int result = 0;
  if (regions.empty()) {
    return result;
  }
  map<tuple<const string&, const string&, const int64_t&, const map<Lang, string>&>, int> counters;
  for (const auto& region : regions) {
    tuple<const string &, const string &, const int64_t &, const map<Lang, string> &>
        tuple1(region.std_name, region.parent_std_name, region.population, region.names);
    //= ;
    counters[tuple1]++;
  }
  for (const auto& [counter, value] : counters) {
    if (value > result) {
      result = value;
    }
  }
  return result;
}
