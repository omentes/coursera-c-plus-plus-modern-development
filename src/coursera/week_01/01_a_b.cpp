/*
 * 01_a_b.cpp
 *
 *  Created on: 12:52:46 PM Sep 26, 2020
 *      Author: omentes
 */

#include <iostream>
using namespace std;

int main_01() {
	int a, b;
	cin >> a >> b;
	if (cin.fail()) {
	    cout << "Please use numbers";
	    return 1;
	}
	cout << a + b;
	return 0;
}
