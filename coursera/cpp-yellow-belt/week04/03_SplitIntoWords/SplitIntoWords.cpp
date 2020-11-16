#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> SplitIntoWords(const string& s) {
  vector<string> result;
  auto start = s.begin();
  auto it = s.begin();
  while (it != s.end()) {
    if (*it == ' ' || it == s.end()) {
      string tmp = string(start,  it);
      result.push_back(tmp);
      start = ++it;
    }
    it++;
  }
  string tmp = string(start,  it);
  result.push_back(tmp);

  return result;
}
