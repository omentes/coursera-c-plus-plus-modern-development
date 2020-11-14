#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
       os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void Assert(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

void TestExp00() {
  Rational num;
  if (num.Numerator() != 0 || num.Denominator() != 1) {
    throw runtime_error("error:" + to_string(num.Numerator()) + "/" + to_string(num.Denominator()));
  }
}

void TestExp01() {
  Rational num(2, 6);
  if (num.Numerator() != 1 || num.Denominator() != 3) {
    throw runtime_error("error:" + to_string(num.Numerator()) + "/" + to_string(num.Denominator()));
  }
}

void TestExp02() {
  Rational num(-2, 6);
  if (num.Numerator() != -1 || num.Denominator() != 3) {
    throw runtime_error("error:" + to_string(num.Numerator()) + "/" + to_string(num.Denominator()));
  }
}

void TestExp03() {
  Rational num(-2, -6);
  if (num.Numerator() != 1 || num.Denominator() != 3) {
    throw runtime_error("error:" + to_string(num.Numerator()) + "/" + to_string(num.Denominator()));
  }
}

void TestExp04() {
  Rational num(2, -6);
  if (num.Numerator() != -1 || num.Denominator() != 3) {
    throw runtime_error("error:" + to_string(num.Numerator()) + "/" + to_string(num.Denominator()));
  }
}

void TestExp05() {
  Rational num(0, 2);
  if (num.Numerator() != 0 || num.Denominator() != 1) {
    throw runtime_error("error:" + to_string(num.Numerator()) + "/" + to_string(num.Denominator()));
  }
}

void TestExp06() {
  Rational num(17, 21);
  if (num.Numerator() != 17 || num.Denominator() != 21) {
    throw runtime_error("error:" + to_string(num.Numerator()) + "/" + to_string(num.Denominator()));
  }
}

void TestExp07() {
  Rational num(3, 5);
  if (num.Numerator() != 3 || num.Denominator() != 5) {
    throw runtime_error("error:" + to_string(num.Numerator()) + "/" + to_string(num.Denominator()));
  }
}

int main() {
  TestRunner runner;
  runner.RunTest(TestExp00, "TestExp00");
  runner.RunTest(TestExp01, "TestExp01");
  runner.RunTest(TestExp02, "TestExp02");
  runner.RunTest(TestExp03, "TestExp03");
  runner.RunTest(TestExp04, "TestExp04");
  runner.RunTest(TestExp05, "TestExp05");
  runner.RunTest(TestExp06, "TestExp06");
  runner.RunTest(TestExp07, "TestExp07");
  return 0;
}