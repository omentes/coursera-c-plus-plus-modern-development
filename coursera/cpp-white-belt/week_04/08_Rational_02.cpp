#include <iostream>
#include <numeric>
using namespace std;

class Rational {
 public:
  Rational() {
    a = 0;
    b = 1;
  }

  Rational(int numerator, int denominator) {
    int div = gcd(numerator, denominator);
    a = numerator/div;
    b = denominator/div;
    if (denominator < 0 && numerator < 0 && a < 0 && b < 0) {
      a = a * -1;
      b = b * -1;
    } else if (numerator > 0 && denominator < 0 && a > 0 && b < 0) {
      a = a * -1;
      b = b * -1;
    } else if (numerator == 0 && denominator < 0 && b < 0) {
      b = b * -1;
    }
  }

  int Numerator() const {
    return a;
  }

  int Denominator() const {
    return b;
  }
 private:
  int a;
  int b;
};

bool operator==(const Rational& left, const Rational& right) {
  return left.Numerator() == right.Numerator() && left.Denominator() == right.Denominator();
}

Rational operator+(const Rational& left, const Rational& right) {
  if (left.Denominator() == right.Denominator()) {
    return Rational(left.Numerator() + right.Numerator(), right.Denominator());
  } else {
    int lcm_value = lcm(left.Denominator(), right.Denominator());
    int new_left = (lcm_value/left.Denominator()) * left.Numerator();
    int new_right = (lcm_value/right.Denominator()) * right.Numerator();
    return Rational(new_left + new_right, lcm_value);
  }
}

Rational operator-(const Rational& left, const Rational& right) {
  if (left.Denominator() == right.Denominator()) {
    return Rational(left.Numerator() - right.Numerator(), right.Denominator());
  } else {
    int lcm_value = lcm(left.Denominator(), right.Denominator());
    int new_left = (lcm_value/left.Denominator()) * left.Numerator();
    int new_right = (lcm_value/right.Denominator()) * right.Numerator();
    return Rational(new_left - new_right, lcm_value);
  }
}

int main() {
  {
    Rational r1(4, 6);
    Rational r2(2, 3);
    bool equal = r1 == r2;
    if (!equal) {
      cout << "4/6 != 2/3" << endl;
      return 1;
    }
  }

  {
    Rational a(2, 3);
    Rational b(4, 3);
    Rational c = a + b;
    bool equal = c == Rational(2, 1);
    if (!equal) {
      cout << "2/3 + 4/3 != 2" << endl;
      return 2;
    }
  }

  {
    Rational a(5, 7);
    Rational b(2, 9);
    Rational c = a - b;
    bool equal = c == Rational(31, 63);
    if (!equal) {
      cout << "5/7 - 2/9 != 31/63" << endl;
      return 3;
    }
  }

  cout << "OK" << endl;
  return 0;
}
