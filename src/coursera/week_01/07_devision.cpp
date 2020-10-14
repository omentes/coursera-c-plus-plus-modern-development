#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (cin.fail()) {
	    cout << "Please use numbers";
	    return 1;
	}
	if (a < 0 || b < 0 || a > 1000000 || b > 1000000 || 0 == b) {
		cout << "Impossible";
	} else {
		cout << a / b << endl;
	}
	return 0;
}
