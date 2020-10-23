/*
 *
  Given a 32-bit signed integer, reverse digits of an integer.

  Note:
  Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

  Example 1:
  Input: x = 123
  Output: 321

  Example 2:
  Input: x = -123
  Output: -321

  Example 3:
  Input: x = 120
  Output: 21

  Example 4:
  Input: x = 0
  Output: 0

  Constraints:
  -2^31 <= x <= 2^31 - 1
  https://leetcode.com/problems/reverse-integer
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */
class Solution {
 public:
  int reverse(int x) {
    long l = static_cast<long>(x);
    long result = 0;
    if (l > 2147483646 || l < -2147483647) {
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
