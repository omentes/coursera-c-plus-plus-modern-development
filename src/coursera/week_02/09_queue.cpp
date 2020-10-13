#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    vector<bool> people = {};
    int line, i;
    string command;

    cin >> line;
    while (line--) {
        cin >> command;
        if (command == "COME") {
            cin >> i;
            people.resize(people.size() + i, false);
        } else if (command == "WORRY" || command == "QUIET") {
            cin >> i;
            people[i] = (command == "WORRY");
        } else if (command == "WORRY_COUNT") {
            i = count(people.begin(), people.end(), true);
            cout << i << endl;
        }

    }

    return 0;
}
