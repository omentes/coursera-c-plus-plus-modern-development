#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
  int64_t days, temp, avg = 0;
  vector<int64_t> temperature, v = {};
  vector<int64_t> result = {};
  cin >> days;
  if (days < 1) {
    return 1;
  }

  while (days--) {
    cin >> temp;
    temperature.push_back(temp);
    avg += temp;
  }
  avg /= static_cast<int64_t>(temperature.size());
  for (int64_t i = 0; i < static_cast<int64_t>(temperature.size()); ++i) {
    if (temperature[i] > avg) {
      result.push_back(i);
    }
  }
  cout << result.size() << endl;
  if (result.size()) {
    for (auto v : result) {
      cout << v << ' ';
    }
  }
  max<double, double>(1.0, 1.00);
  return 0;
}
