/*
 * 04_second_occurrence.cpp
 *
 *  Created on: 4:08:20 PM Sep 26, 2020
 *      Author: omentes
 */

#include <iostream>
using namespace std;

int main_14() {
	string in;
	int result;
	cin >> in;
	if (cin.fail()) {
	    cout << "Please use string";
	    return 1;
	}
	result = -2;
	for (int i = 0; i < in.length(); ++i) {
		if ('f' == in[i] && -2 == result) {
			result++;
		} else if ('f' == in[i] && -1 == result) {
			result = i;
			break ;
		}
	}
	cout << result;
	return 0;
}
