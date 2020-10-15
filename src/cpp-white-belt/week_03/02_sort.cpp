#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main() {

    int n;
    string tmp;
    vector<string> v;

    cin >> n;
    while (n--) {
        cin >> tmp;
        v.push_back(tmp);
    }
    sort(begin(v), end(v), [](string x, string y) {
        transform(x.begin(), x.end(), x.begin(), [](unsigned char c) { return tolower(c); });
        transform(y.begin(), y.end(), y.begin(), [](unsigned char c) { return tolower(c); });
        return x < y;
    });

    for (const auto& i : v) {
        cout << i << ' ';
    }
    return 0;
}
