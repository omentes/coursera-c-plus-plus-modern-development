#include <iostream>

using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (cin.fail()) {
	    cout << "Please use numbers";
	    return 1;
	}
	cout << a + b;
	return 0;
}
