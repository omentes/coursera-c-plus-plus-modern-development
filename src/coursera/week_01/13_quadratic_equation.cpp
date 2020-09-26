/*
 * 03_quadratic_equation.cpp
 *
 *  Created on: 2:34:04 PM Sep 26, 2020
 *      Author: omentes
 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main_13() {
	int a, b ,c;
	double descriminant, scrt_result;
	vector<double> result;
	cin >> a >> b >> c;
	descriminant = (b * b) - 4 * a * c;
	scrt_result = sqrt(descriminant);
	if (descriminant < 0.0) {
		return 0;
	}
	if (0 == a) {
		result.push_back((double)(-c/b));
	} else if (0 == b) {
		result.push_back((double)(scrt_result / (2 * a)));
	}
	else {
		if (descriminant >= 0) {
			result.push_back((-b + scrt_result) / (2 * a));
			if (descriminant != 0) {
				result.push_back((-b - scrt_result) / (2 * a));
			}
		} else {
			result.push_back(-b / 2 * a);
		}
	}


	if (!result.empty()) {
		for (auto i : result) {
			cout <<	i << ' ' ;
		}
	}
	return 0;
}
