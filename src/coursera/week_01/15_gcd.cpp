/*
 * 05_gcd.cpp
 *
 *  Created on: 4:42:22 PM Sep 26, 2020
 *      Author: omentes
 */

#include <iostream>
using namespace std;

/*
 * Recursive Euclidean algo
 */
int gcd(int a, int b) {
    if (a == 0)
        return b;
    return gcd(b % a, a);
}

int main() {
	int a, b, result;
	cin >> a >> b;
	if (cin.fail()) {
	    cout << "Please use numbers";
	    return 1;
	}
	result = gcd(a, b);
	cout << result;
	return 0;
}
