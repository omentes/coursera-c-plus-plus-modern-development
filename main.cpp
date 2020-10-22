#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
#include "reload.h"
using namespace std;


//
//using namespace std;
//template <typename Value, typename Key>
//Value& GetRefStrict(map<Key, Value>& items, const Key key) {
//  if (items.count(key)) {
//    return items[key];
//  }
//  throw runtime_error("");
//}
//
//int main() {
//
//  map<int, string> m = {{0, "value"}};
//  string& item = GetRefStrict(m, 0);
//  item = "newvalue";
//  cout << m[0] << endl; // выведет newvalue
//  return 0;
//}

//using namespace std;
//int reverse(int x) {
//  string str = to_string(x);
//  reverse(str.begin(), str.end());
//  long k = stol(str);
//
//  return x >= 0 ? k : -k ;
//}
//
//int main() {
//
//  cout << reverse(1534236469) << endl;
//  return 0;
//}
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int max = nums.size();
    for (int i = max - 1; i > -1; --i) {
      for (int j = 0; j < max; ++j) {
        if (i == j || nums[i] + nums[j] != target) {
          continue;
        }
        return {i, j};
      }

    }
    return {};
  }
};

int main() {
  vector<int> v = {2,7,11,15};
  Solution sol;
  cout << sol.twoSum(v, 9) << endl;
  return 0;
}
