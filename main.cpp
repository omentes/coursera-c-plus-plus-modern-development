#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> Reversed(const vector<int>& v) {
    int len = v.size() - 1;
    vector<int> v2 = {};
    if (len > 0) {
        while ( len > -1)
        {
            v2.push_back(v[len--]);
        }
    }
    return v2;
}

int main() {
    vector<int> numbers = {1, 5, 3, 4, 2};
    numbers = Reversed(numbers);
// numbers должен оказаться равен {2, 4, 3, 5, 1}
    for (auto d : numbers) {
        cout << d << ' ';
    }
    return 0;
}