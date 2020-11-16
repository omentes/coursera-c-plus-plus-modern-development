#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
  int how;
  cin >> how;
  vector<int> v1(how);
  for (auto& it : v1) {
    it = how--;
  }
  do {
    bool space = false;
    for (const auto& it : v1) {
      if (space) { cout << ' '; }
      cout << it;
      space = true;
    }
    cout << endl;
  } while (prev_permutation(v1.begin(), v1.end()));
  return 0;
}
