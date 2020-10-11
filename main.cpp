#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    double a, b ,c, d, scrt_result;
    vector<double> result;
    cin >> a >> b >> c;
    d = (b * b) - 4 * a * c;
    scrt_result = sqrt(d);
    if (d < 0.0) {
        return 0;
    }
    if (0 == a && b != 0) {
        result.push_back((double)(-c / b));
    } else if (d > 0 && a != 0) {
        result.push_back((double)((-b + scrt_result) / (2 * a)));
        result.push_back((double)((-b - scrt_result) / (2 * a)));
    } else if (a != 0) {
        result.push_back(-b / (2 * a));
    }



    if (!result.empty()) {
        for (double i : result) {
            if (i == 0.0 && signbit(i)) {
                i = 0;
            }
            cout <<	i << ' ' ;
        }
    }
    return 0;
}