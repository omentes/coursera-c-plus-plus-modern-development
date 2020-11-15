#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <exception>
#include <iomanip>
#include "test_runner.h"
#include "coursera/cpp-yellow-belt/week03/02_phone_number/phone_number.h"
using namespace std;

void Test00() {
  try {
    PhoneNumber phone("");
  } catch (invalid_argument& e) {
    string tmp = e.what();
    if (tmp != "First character was not a plus") {
      throw exception();
    }
  }
}

void Test01() {
  try {
    PhoneNumber phone("+7-1111");
  } catch (invalid_argument& e) {
    string tmp = e.what();
    if (tmp != "Number was contains min 3 parts") {
      throw exception();
    }
  }
}

void Test02() {
  try {
    PhoneNumber phone("+7-1111----");
  } catch (invalid_argument& e) {
    string tmp = e.what();
    if (tmp != "Local number was contains not empty") {
      throw exception();
    }
  }
}

void Test03() {
  PhoneNumber phone("+7-495-111-22-33");
  AssertEqual(phone.GetInternationalNumber(), "+7-495-111-22-33", "GetInternationalNumber");
  AssertEqual(phone.GetLocalNumber(), "111-22-33", "GetLocalNumber");
  AssertEqual(phone.GetCityCode(), "495", "GetCityCode");
  AssertEqual(phone.GetCountryCode(), "7", "GetCountryCode");
}

int main() {
  TestRunner tr;
  tr.RunTest(Test00, "Test00");
  tr.RunTest(Test01, "Test01");
  tr.RunTest(Test02, "Test02");
  tr.RunTest(Test03, "Test03");
  return 0;
}