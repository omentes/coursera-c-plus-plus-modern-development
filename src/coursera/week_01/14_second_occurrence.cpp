/*
 * 04_second_occurrence.cpp
 *
 *  Created on: 4:08:20 PM Sep 26, 2020
 *      Author: omentes
 */

#include <iostream>
using namespace std;

int main() {
	string in;
	int result, len;
	cin >> in;
	if (cin.fail()) {
	    cout << "Please use string";
	    return 1;
	}
	result = -2;
	len = (int)in.length();
	for (int i = 0; i < len; ++i) {
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
