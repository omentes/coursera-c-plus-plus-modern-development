#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    int days, temp, avg;
    vector<int> temperature, v = {};
    vector<int> result = {};
    cin >> days;
    if (days < 1) {
        return 1;
    }

    while (days--) {
        cin >> temp;
        temperature.push_back(temp);
    }
    avg = accumulate(temperature.begin(), temperature.end(), 00L) / temperature.size();

    for (int i = 0; i < static_cast<int>(temperature.size()); ++i) {
        if (temperature[i] > avg) {
            result.push_back(i);
        }
    }
    cout << result.size() << endl;
    for (auto v : result) {
        cout << v << ' ';

    }
    return 0;
}
