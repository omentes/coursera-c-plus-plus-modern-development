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

void TestExp1() {
  Person person;
  string result = person.GetFullName(1);
  if ("Incognito" != result) {
    throw runtime_error("TestExp1: " +  result);
  }
}

void TestExp2() {
  Person person;
  person.ChangeFirstName(1965, "Polina");
  string result = person.GetFullName(1);
  if ("Incognito" != result) {
    throw runtime_error("TestExp2: " +  result);
  }
}

void TestExp3() {
  Person person;
  person.ChangeFirstName(1965, "Polina");
  string result = person.GetFullName(1965);
  if ("Polina with unknown last name" != result) {
    throw runtime_error("TestExp3: " +  result);
  }
}

void TestExp4() {
  Person person;
  person.ChangeLastName(1965, "Sergeeva");
  string result = person.GetFullName(1965);
  if ("Sergeeva with unknown first name" != result) {
    throw runtime_error("TestExp4: " +  result);
  }
}

void TestExp5() {
  Person person;
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  string result = person.GetFullName(1968);
  if ("Polina Sergeeva" != result) {
    throw runtime_error("TestExp5: " +  result);
  }
}

void TestExp6() {
  Person person;
  person.ChangeFirstName(1967, "Polina");
  person.ChangeLastName(1965, "Sergeeva");
  string result = person.GetFullName(1965);
  if ("Sergeeva with unknown first name" != result) {
    throw runtime_error("TestExp6: " +  result);
  }
}

void TestExp7() {
  Person person;
  person.ChangeLastName(1967, "Polina");
  person.ChangeLastName(1965, "Sergeeva");
  string result = person.GetFullName(0);
  if ("Incognito" != result) {
    throw runtime_error("TestExp7: " +  result);
  }
}

void TestExp8() {
  Person person;
  person.ChangeFirstName(1965, "Polina");
  person.ChangeFirstName(1966, "Polina66");
  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1967, "Sergeeva67");
  string result = person.GetFullName(1966);
  if ("Polina66 Sergeeva" != result) {
    throw runtime_error("TestExp8: " +  result);
  }
}

void TestExp9() {
  Person person;
  person.ChangeFirstName(1965, "Polina");
  person.ChangeFirstName(1966, "Polina66");
  person.ChangeLastName(1965, "Sergeeva");
  person.ChangeLastName(1967, "Sergeeva67");
  string result = person.GetFullName(1967);
  if ("Polina66 Sergeeva67" != result) {
    throw runtime_error("TestExp9: " +  result);
  }
}


int main() {
  TestRunner runner;
  runner.RunTest(TestExp1, "TestExp1");
  runner.RunTest(TestExp2, "TestExp2");
  runner.RunTest(TestExp3, "TestExp3");
  runner.RunTest(TestExp4, "TestExp4");
  runner.RunTest(TestExp5, "TestExp5");
  runner.RunTest(TestExp6, "TestExp6");
  runner.RunTest(TestExp7, "TestExp7");
  runner.RunTest(TestExp8, "TestExp8");
  runner.RunTest(TestExp9, "TestExp9");
  return 0;
}
