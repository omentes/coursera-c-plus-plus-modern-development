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
	int tmp = a;

    if (a == b) {
        return a;
    }
    if (a > b) {
        a = b;
        b = tmp;
    }
    return gcd(a, b - a);
}

int main_05() {
	int a, b;
	cin >> a >> b;
	if (cin.fail()) {
	    cout << "Please use numbers";
	    return 1;
	}
	while (a != b) {
        if (a > b) {
        	// move less number to a varaible
        	a = a + b;
        	b = a - b;
        	a = a - b;
        }
        b = b - a;
	}
	cout << a;
	return 0;
}
