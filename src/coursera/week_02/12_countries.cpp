#include <iostream>
#include <string>
#include <map>

using namespace std;

void changeCapital(
        map<string, string>& countries,
        const string& country,
        const string& capital
) {

    if (capital == countries[country]) {
        cout << "Country "<< country << " hasn't changed its capital" << endl;
        return;
    }

    if (countries[country].empty()) {
        cout << "Introduce new country "<< country << " with capital "  << capital << endl;
    } else {
        cout << "Country " << country << " has changed its capital from " << countries[country];
        cout << " to " << capital << endl;
    }
    countries[country] = capital;
}

void renameCountry(
        map<string, string>& countries,
        const string& old_country_name,
        const string& new_country_name
) {

    if (!countries[new_country_name].empty() ||
        old_country_name == new_country_name ||
        countries[old_country_name].empty()
            ) {
        cout << "Incorrect rename, skip" << endl;
        if (countries[old_country_name].empty()) {
            countries.erase(old_country_name);
        }
        if (countries[new_country_name].empty()) {
            countries.erase(new_country_name);
        }
        return ;
    }
    cout << "Country " << old_country_name << " with capital " << countries[old_country_name];
    cout << " has been renamed to " << new_country_name << endl;
    countries[new_country_name] = countries[old_country_name];
    countries.erase(old_country_name);

}

void aboutCountry(map<string, string>& countries, string country) {
    if(countries[country].empty()) {
        cout << "Country " << country  << " doesn't exist" << endl;
        countries.erase(country);
    } else {
        cout << "Country " << country  << " has capital " << countries[country] << endl;
    }
}

void dumpCountries(map<string, string>& countries) {
    if (countries.empty()) {
        cout << "There are no countries in the world" << endl;
    } else {
        for (const auto& [country, capital]: countries) {
            cout << country << "/" << capital << " ";
        }
        cout << endl;
    }
}

int main() {
    int line;
    string command, first, second;
    map<string, string> countries;

    cin >> line;
    while (line--) {
        cin >> command;
        if (command == "CHANGE_CAPITAL" || command == "RENAME") {
            cin >> first >> second;
            command == "CHANGE_CAPITAL" ?
            changeCapital(countries, first, second) :
            renameCountry(countries, first, second);
        } else if (command == "ABOUT") {
            cin >> first;
            aboutCountry(countries, first);
        } else if(command == "DUMP") {
            dumpCountries(countries);
        }
    }

    return 0;
}