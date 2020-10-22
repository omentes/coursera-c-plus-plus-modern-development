#include <iostream>
#include <set>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    string command, word1, word2;
    int lines;
    set<string> synonyms;
    map<string, int> counter;
    cin >> lines;

    while (lines--) {
        cin >> command;
        if (command == "ADD" || command == "CHECK" ) {
            cin >> word1 >> word2;
            string tmp = (word1 > word2) ? word1 + word2 : word2 + word1;
            if (command == "CHECK") {
                if (synonyms.count(tmp) > 0) {
                    cout << "YES" << endl;
                } else {
                    cout << "NO" << endl;
                }
            } else {
                if (synonyms.count(tmp) == 0) {
                    counter[word1]++;
                    counter[word2]++;
                    synonyms.insert(tmp);
                }
            }
        } else if (command == "COUNT") {
            cin >> word1;
            cout << counter[word1] << endl;
        }

    }
    return 0;
}
