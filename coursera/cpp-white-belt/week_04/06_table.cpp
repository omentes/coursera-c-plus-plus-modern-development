#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
  ifstream input("input.txt");
  if (input) {
    int x, y;
    string line;
    getline(input, line, ' ');
    y = stoi(line);
    getline(input, line);
    x = stoi(line);
    for (int kI = 0; kI < y; ++kI) {
      for (int kJ = 0; kJ < x - 1; ++kJ) {
        if (kJ % x != 0) {
          cout << " ";
        }
        cout << setw(10);
        getline(input, line, ',');
        cout << stoi(line);
      }
      if (x != 1) {
        cout << " ";
      }
      cout << setw(10);
      getline(input, line);
      cout << stoi(line);
      if (kI != y -1) {
        cout << endl;
      }
    }
  }
  return 0;
}
