#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (cin.fail()) {
	    return 1;
	}
	if (a < 1 || a > b || b > 30000) {
		return 1;
	}
	if (a % 2 != 0) {
		a++;
	}
	while (a <= b) {
		cout << a << ' ';
		a += 2;
	}
	return 0;
}


