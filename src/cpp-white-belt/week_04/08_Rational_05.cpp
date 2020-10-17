#include <iostream>
#include <numeric>
#include <sstream>
#include <set>
#include <map>

using namespace std;

class Rational {
 public:
  Rational() {
    a = 0;
    b = 1;
  }

  Rational(int numerator, int denominator) {
    UpdateNums(numerator, denominator);
  }
  void UpdateNums(int numerator, int denominator) {
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
  set<Rational> rationals;
  rationals.insert(Rational(1, 2));
  rationals.insert(Rational(1, 3));
  for (const auto& i : rationals) {
    cout << i << endl;
  }
  map<Rational, string> name;
  name[Rational(1, 2)] = "одна вторая";
  cout << name[Rational(1, 2)] << endl;
  cout << "OK" << endl;
  return 0;
}
