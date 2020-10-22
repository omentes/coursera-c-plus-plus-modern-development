#include <iostream>
#include <vector>

using namespace std;

int main() {
    int lines, day, currentMonth = 0;
    string command;
    vector<int> year = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<vector<string>> current;
    cin >> lines;
    current.resize(year[currentMonth]);
    while (lines--) {
        cin >> command;
        if ("ADD" == command) {
            cin >> day;
            cin >> command;
            current[day - 1].push_back(command);
        } else if ("DUMP" == command) {
            cin >> day;
            cout << current[--day].size() << ' ';
            for (string str : current[day]) {
                cout << str << ' ';
            }
            cout << endl;
        } else if ("NEXT" == command) {
            if (11 == currentMonth) {
                currentMonth = 0;
            } else {
                currentMonth++;
                if (year[currentMonth - 1] - year[currentMonth] > 0) {
                    int tmp = year[currentMonth - 1] - 1;
                    while (tmp != year[currentMonth] - 1) {
                        if (!current[tmp].empty()) {
                            current[year[currentMonth] - 1].insert(
                                    end(current[year[currentMonth] - 1]),
                                    begin(current[tmp]),
                                    end(current[tmp])
                            );
                        }
                        tmp--;
                    }
                }
                current.resize(year[currentMonth]);
            }
        }
    }
    return 0;
}