#include <iostream>
#include <numeric>
#include <stdexcept>
#include <sstream>

using namespace std;

class Rational {
 public:
  Rational() {
    a = 1;
    b = 1;
  }

  Rational(int numerator, int denominator) {
    UpdateNums(numerator, denominator);
  }
  void UpdateNums(int numerator, int denominator) {
    if (denominator == 0) {
      throw invalid_argument("invalid_argument");
    }
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

bool operator<(const Rational& left, const Rational& right) {
  if (left.Denominator() == right.Denominator()) {
    return left.Numerator() < right.Numerator();
  } else {
    int lcm_value = lcm(left.Denominator(), right.Denominator());
    int new_left = (lcm_value/left.Denominator()) * left.Numerator();
    int new_right = (lcm_value/right.Denominator()) * right.Numerator();
    return new_left < new_right;
  }
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

Rational operator*(const Rational& left, const Rational& right) {
  return Rational(
      left.Numerator() * right.Numerator(),
      left.Denominator() * right.Denominator()
  );
}

Rational operator/(const Rational& left, const Rational& right) {
  if (right.Numerator() == 0) {
    throw domain_error("");
  }
  return Rational(
      left.Numerator() * right.Denominator(),
      left.Denominator() * right.Numerator()
  );
}

ostream& operator<<(ostream& stream, const Rational& rational) {
  stream << rational.Numerator() << "/" << rational.Denominator();
  return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
  int a, b;
  char c;
  stream >> a;
  stream >> c;
  stream >> b;
  if (stream.fail() || c != '/') {
    return stream;
  }
  rational.UpdateNums(a, b);
  return stream;
}

int main() {
  try {
    Rational r(1, 0);
    cout << "Doesn't throw in case of zero denominator" << endl;
    return 1;
  } catch (invalid_argument&) {
  }

  try {
    auto x = Rational(1, 2) / Rational(0, 1);
    cout << "Doesn't throw in case of division by zero" << endl;
    return 2;
  } catch (domain_error&) {
  }

  string line;
  getline(cin, line);
  try {
    stringstream ss(line);
    char o;
    Rational r1, r2;
    ss >> r1;
    ss >> o;
    ss >> r2;
    if (o == '+') {
      cout << r1 + r2 << endl;
    } else if (o == '-') {
      cout << r1 - r2 << endl;
    } else if (o == '*') {
      cout << r1 * r2 << endl;
    } else if (o == '/') {
      cout << r1 / r2 << endl;
    }
  } catch (invalid_argument& ex) {
    cout << "Invalid argument" << endl;
  } catch (domain_error& ex) {
    cout << "Division by zero" << endl;
  }
  return 0;
}