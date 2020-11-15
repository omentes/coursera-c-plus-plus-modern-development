#include <iostream>
#include <vector>
#include <algorithm>
#include "reload.h"

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


int main() {
  PrintVectorPart({6, 1, 8, -5, 4});
  cout << endl;
  PrintVectorPart({-6, 1, 8, -5, 4});  // ничего не выведется
  cout << endl;
  PrintVectorPart({6, 1, 8, 5, 4});
  cout << endl;
  return 0;
}