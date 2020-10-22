#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int main() {
    bool flag = false;
    int lines, stops, it = 1;
    string stop, bus;
    map <int, set<string>> exists;
    set<string> exist;

    bus = "New bus ";
    cin >> lines;
    while (lines--) {
        cin >> stops;
        exist.clear();
        while (stops--) {
            cin >> stop;
            exist.insert(stop);
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
