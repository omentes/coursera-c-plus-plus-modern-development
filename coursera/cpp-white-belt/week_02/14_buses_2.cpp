#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    bool flag = false;
    int lines, stops, it = 1;
    string stop, bus;
    map <int, vector<string>> exists;
    vector<string> exist;

    bus = "New bus ";
    cin >> lines;
    while (lines--) {
        cin >> stops;
        exist.clear();
        while (stops--) {
            cin >> stop;
            exist.push_back(stop);
        }
        for (const auto& [name, item] : exists) {
            if (item == exist) {
                flag = true;
                cout << "Already exists for " << name << endl;
                break ;
            }
        }
        if (!flag) {
            exists[it] = exist;
            cout << "New bus " << it++ << endl;
        }
        flag = false;
    }


    return 0;
}
