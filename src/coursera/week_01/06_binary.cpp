#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
	int a;
	vector<int> v;
	cin >> a ;
	if (cin.fail()) {
	    cout << "Please use numbers";
	    return 1;
	}
	while (a) {
		v.push_back(a % 2);
		a >>= 1;
	}
	reverse(v.begin(), v.end());
	for (auto e : v) {
		cout << e;
	}
	return 0;
}
