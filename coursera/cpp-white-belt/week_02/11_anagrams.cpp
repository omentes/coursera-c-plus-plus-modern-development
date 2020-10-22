#include <iostream>
#include <map>

using namespace std;

map<char, int> charMapByWord(const string& str)
{
    map<char, int> m;
    for (const char& c : str) {
        m[c]++;
    }
    return m;
}

int main() {
    int lines;
    string first, second;
    cin >> lines;
    while (lines--) {
        cin >> first >> second;
        string result = (charMapByWord(first) == charMapByWord(second)) ? "YES" : "NO";
        cout << result << endl;
    }
    return 0;
}