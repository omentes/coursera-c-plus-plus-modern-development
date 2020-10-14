#include <iostream>

using namespace std;

/*
 * 100 80 100 5 10
 * */
int main_18() {
	double price, discont, needDiscontX, needDiscontY, x, y;
	cin >> price >> needDiscontX >> needDiscontY >> x >> y;
	if (cin.fail()) {
	    return 1;
	}
	if (price < 0 ||
		x < 0 ||
		y < 0
		) {
		return 1;
	}
	if (needDiscontX >= needDiscontY) {
		cout << "Impossible" << endl;
	} else {
		if (price <= needDiscontX) {
			cout << price << endl;
		} else if (price <= needDiscontY) {
			discont = (price / 100) * x;
			cout << price - discont << endl;
		} else {
			discont = (price / 100) * y;
			cout << price - discont << endl;
		}
	}
	return 0;
}
