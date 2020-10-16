#include <iostream>
#include <string>
#include <algorithm>

class ReversibleString {
 public:
  ReversibleString() {};
  ReversibleString(const string& str) {
    s = str;
  };
  void Reverse() {
    reverse(s.begin(), s.end());
  }
  string ToString() const {
    return s;
  }
 private:
  string s;
};
