#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int n, tmp;
    vector<int> v;

    cin >> n;
    while (n--) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(begin(v), end(v), [](int x, int y){ return abs(x) < abs(y);});

    for (const auto& i : v) {
        cout << i << ' ';
    }
    return 0;
}
