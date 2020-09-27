/*
 * 19_even_numbers.cpp
 *
 *  Created on: 3:13:17 AM Sep 27, 2020
 *      Author: omentes
 */

#include <iostream>

using namespace std;

/*
 * Дано два целых числа A и B (A <= B, A >= 1, B <= 30000).
 * Выведите через пробел все чётные числа от A до B (включительно).
 * */
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


