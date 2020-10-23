/*
 * 9. Palindrome Number
Determine whether an integer is a palindrome.
 An integer is a palindrome when it reads the same backward as forward.
Follow up: Could you solve it without converting the integer to a string?

Example 1:
Input: x = 121
Output: true

 Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

 Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

 Example 4:
Input: x = -101
Output: false


Constraints:
  -2^31 <= x <= 2^31 - 1
  https://leetcode.com/problems/palindrome-number/
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
class Solution {
 public:

  bool isPalindrome(int x) {
    string str("");
    if (x == 0) {
      return true;
    } else if (x < 0) {
      return false;
    }
    while (x > 10) {
      int m = x % 10;
      x /= 10;
      str.push_back(static_cast<char>(m + 48));
    }
    if (x == 10) {
      str.push_back(static_cast<char>('0'));
      str.push_back(static_cast<char>('1'));
    } else if (x) {
      str.push_back(static_cast<char>(x + 48));

    }
    int last = str.size();
    int first = 0;
    int it = last / 2 + 1;
    last--;
//    cout << str << endl;
    while (it--) {
      if (str[last--] == str[first++]) {
        continue;
      } else {
        return false;
      }
    }
    return true;
  }
};
