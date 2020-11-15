#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void PrintVectorPart(const vector<int>& numbers) {
  auto it = find_if(
      numbers.begin(),
      numbers.end(),
      [](const int& current) {
        return current < 0;
      }
  );
  bool space = false;
  if (it > numbers.begin()) {
    auto i = it;
    while (i != numbers.begin()) {
      --i;
      if (space) {
        cout << ' ';
      }
      cout << *i ;
      space = true;
    }
  }
}