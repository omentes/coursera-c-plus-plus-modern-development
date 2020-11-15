#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

struct BusesForStopResponse {
  bool empty = true;
  vector<string> stops = {};
};

ostream& operator << (ostream& os, const BusesForStopResponse& r);

struct StopsForBusResponse {
  vector<string> stopsForBus = {};
};

ostream& operator << (ostream& os, const StopsForBusResponse& r);

struct AllBusesResponse {
  vector<string> allBuses = {};
};

ostream& operator << (ostream& os, const AllBusesResponse& r);
