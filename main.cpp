#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include "test_runner.h"
using namespace std;

void TestWorks() {
  AssertEqual(1, 1, "Just to check that Assert works");
}

int main() {
  TestRunner tr;
  tr.RunTest(TestWorks, "TestWorks");
  return 0;
}