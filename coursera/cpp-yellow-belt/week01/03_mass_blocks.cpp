#include <iostream>

using namespace std;

int main() {
  size_t quantity, density, w, h, d, sum;
  cin >> quantity >> density;
  sum = 0;
  while (quantity--) {
    cin >> w >> h >> d;
    sum += w * h * d * density;
  }
  cout << sum << endl;
  return 0;
}
