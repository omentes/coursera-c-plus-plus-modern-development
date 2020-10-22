#include <iostream>
#include <vector>
#include <map>
#include <sstream>
#include <utility>
#include <string>
#include "reload.h"
using namespace std;

class Solution {
 public:
  int reverse(int x) {
    long l = static_cast<long>(x);
    long result = 0;
    if (l >= INT32_MAX) {
      return 0;
    }
    while (x) {
      result *= static_cast<long>(10);
      result += static_cast<long>(x % 10);
      x /= static_cast<long>(10);
    }
    if (result > 2147483646 || result < -2147483647) {
      return 0;
    }
    return static_cast<int>(result);
  }
};
int main() {
  Solution sol;
  cout << sol.reverse(-2147483648) << endl;
//  cout << sol.reverse(214347865) << endl;
  return 0;
}

