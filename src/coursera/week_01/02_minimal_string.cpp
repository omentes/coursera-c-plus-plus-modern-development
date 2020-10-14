#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	string a, b ,c;
	vector<string> v;
	cin >> a >> b >> c;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);
	for (auto element : v) {
		if (element.length() > 30) {
			return 1;
		}
		for (auto c : element) {
			if (!islower(c) || !isalpha(c)) {
				return 1;
			}
		}
	}
	sort(begin(v), end(v));
	cout << v[0];
	return 0;
}
