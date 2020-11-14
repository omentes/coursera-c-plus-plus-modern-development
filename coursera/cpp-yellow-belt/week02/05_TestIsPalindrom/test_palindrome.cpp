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
  Assert(IsPalindrom(""), "TestExp00");
}

void TestExp01() {
  Assert(IsPalindrom(" "), "TestExp01");
}

void TestExp02() {
  Assert(IsPalindrom("  "), "TestExp02");
}

void TestExp03() {
  Assert(IsPalindrom(" . "), "TestExp03");
}

void TestExp04() {
  Assert(IsPalindrom(" \n "), "TestExp04");
}

void TestExp05() {
  Assert(IsPalindrom(" \t "), "TestExp05");
}

void TestExp06() {
  Assert(!IsPalindrom(" a"), "TestExp06");
}

void TestExp07() {
  Assert(!IsPalindrom(" abcbba "), "TestExp07");
}

void TestExp08() {
  Assert(!IsPalindrom(" abcbba "), "TestExp08");
}

void TestExp09() {
  Assert(!IsPalindrom(" abcba"), "TestExp09");
}

void TestExp10() {
  Assert(!IsPalindrom(" .!l\t\n \tl!. "), "TestExp10");
}

void TestExp11() {
  Assert(!IsPalindrom("\t \v"), "TestExp11");
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
  runner.RunTest(TestExp08, "TestExp08");
  runner.RunTest(TestExp09, "TestExp09");
  runner.RunTest(TestExp10, "TestExp10");
  runner.RunTest(TestExp11, "TestExp11");
  return 0;
}
