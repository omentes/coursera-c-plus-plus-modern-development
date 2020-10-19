#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

enum class Lang {
  DE, FR, IT
};

struct Region {
  string std_name;
  string parent_std_name;
  map<Lang, string> names;
  int64_t population;
};

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

int main() {
  cout << FindMaxRepetitionCount({
    {
    "Moscow",
    "Russia",
    {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
    89
    }, {
    "Russia",
    "Eurasia",
    {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
    89
    }, {
    "Moscow",
    "Russia",
    {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
    89
    }, {
    "Moscow",
    "Russia",
    {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
    89
    }, {
    "Russia",
    "Eurasia",
    {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
    89
    },
  }) << endl;

  cout << FindMaxRepetitionCount({
     {
         "Moscow",
         "Russia",
         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
         89
     }, {
         "Russia",
         "Eurasia",
         {{Lang::DE, "Russland"}, {Lang::FR, "Russie"}, {Lang::IT, "Russia"}},
         89
     }, {
         "Moscow",
         "Russia",
         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou deux"}, {Lang::IT, "Mosca"}},
         89
     }, {
         "Moscow",
         "Toulouse",
         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
         89
     }, {
         "Moscow",
         "Russia",
         {{Lang::DE, "Moskau"}, {Lang::FR, "Moscou"}, {Lang::IT, "Mosca"}},
         31
     }, {
         "Moscow",
         "Russia",
         {{Lang::IT, "Mosca"}},
         31
     },
 }) << endl;

  return 0;
}
