#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

void MoveStrings(vector<string>& source, vector<string>& destination) {
    for (auto str : source) {
        destination.push_back(str);
    }
    source.clear();
}

int main() {
    vector<string> source = {"a", "b", "c"};
    vector<string> destination = {"z"};
    MoveStrings(source, destination);
    for (auto w : destination) {
        cout << w << endl;
    }
    for (auto d : source) {
        cout << d << endl;
    }
    return 0;
}