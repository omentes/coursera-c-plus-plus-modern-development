#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string busesForStop(map<string, vector<string>> routes, const map <int, string>& bus_list, string stop) {
    string result = "";

    for (const auto& [bus_num, bus_name] : bus_list) {
        if (find(routes[bus_name].begin(), routes[bus_name].end(), stop) != routes[bus_name].end()) {
            result += bus_name + " ";
        }
    }

    for (const auto& [bus, bus_route] : routes) {

    }
    if (result.empty()) {
        result = "No stop";
    }
    return result;
}


bool busExist(const map<string, vector<string>>& routes, string bus) {
    for (const auto& [exist_bus, bus_route] : routes) {
        if (bus == exist_bus) {
            return true;
        }
    }
    return false;
}

string busesByStop(map<string, vector<string>> routes, const map <int, string>& bus_list, string stop, string skip) {

    string result = "";
    for (const auto& [bus_num, bus_name] : bus_list) {
        if (busExist(routes, bus_name)) {
            if (find(routes[bus_name].begin(), routes[bus_name].end(), stop) != routes[bus_name].end() && skip != bus_name) {
                result += bus_name + " ";
            }
        }
    }

    if (result.empty()) {
        result = "no interchange";
    }
    return result;
}

int main() {
    int line, buses, it = 0;
    string command, bus;
    map<string, vector<string>> routes;
    map <int, string> bus_list;

    cin >> line;
    while (line--) {
        cin >> command;
        if (command == "DUMP") {
            for (auto [bus, bus_route] : routes) {
                cout << bus << endl;
            }
        }
        if (command == "BUSES_FOR_STOP") {
            cin >> command;
            cout << busesForStop(routes, bus_list, command) << endl;
        } else if (command == "STOPS_FOR_BUS") {
            cin >> command;
            if (busExist(routes, command)) {
                for (const auto& stop : routes[command]) {
                    cout << "Stop " << stop << ": " << busesByStop(routes, bus_list, stop, command) << endl;
                }

            } else {
                cout << "No bus" << endl;
            }

        } else if (command == "NEW_BUS") {
            cin >> bus >> buses;
            while (buses--) {
                cin >> command;
                routes[bus].push_back(command);
            }
            bus_list[it] = bus;
            it++;
        } else if(command == "ALL_BUSES") {
            if (routes.empty()) {
                cout << "No buses" << endl;
            } else {
                for (const auto& [bus, bus_route] : routes) {
                    cout << "Bus " << bus << ": ";
                    for (const auto& stops : bus_route) {
                        cout << stops << " ";
                    }
                    cout << endl;
                }
            }
        }
    }

    return 0;
}