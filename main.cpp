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
  int myAtoi(string s) {
    char check;
    unsigned long long n = 0;
    int i = 0;

    while (s[i]) {
      if ((s[i] < 14 && s[i] > 8) || s[i] == 32) {
        ++i;
        continue;
      } else {
        break ;
      }
    }
    check = '+';
    if (s[i] == '-' || s[i] == '+')
    {
      check = s[i];
      i++;
    }
    while ((s[i] >= '0') && (s[i] <= '9'))
    {
      n = n * 10 + (s[i] - '0');
      i++;
      if (n >= 2147483648) {
        n = check == '-' ? -2147483648 : 2147483647;
        return n;
      }
    }
    return check == '-' ? -n : n;
  }
};
int main() {
  Solution sol;
  cout << sol.myAtoi("18446744073709551617") << endl;
//  cout << sol.reverse(214347865) << endl;
  return 0;
}

