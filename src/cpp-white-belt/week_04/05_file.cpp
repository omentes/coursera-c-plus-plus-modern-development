#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
  ifstream input("input.txt");
  if (input) {
    string line;
    cout << fixed << setprecision(3);
    while (getline(input, line)) {
      cout << stod(line) << endl;
    }
  }
  return 0;
}
