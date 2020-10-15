#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int lines;
    string line;
    set<string> strings;

    cin >> lines;

    while (lines--) {
        cin >> line;
        strings.insert(line);
    }
    cout << strings.size();
    return 0;
}
