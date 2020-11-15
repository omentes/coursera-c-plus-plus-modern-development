#pragma once
#include <string>
#include <map>
#include <vector>
#include "responses.h"

using namespace std;

using Mapping = map<string, vector<string>>;

class BusManager {
 public:
  BusManager() {
    buses_to_stops = {};
    stops_to_buses = {};
  }
  BusManager(Mapping buses, Mapping stops) {
    buses_to_stops = std::move(buses);
    stops_to_buses = std::move(stops);
  }
  Mapping buses_to_stops;
  Mapping stops_to_buses;

  void AddBus(const string& bus, const vector<string>& stops);

  BusesForStopResponse GetBusesForStop(const string& stop) const;

  StopsForBusResponse GetStopsForBus(const string& bus) const;

  AllBusesResponse GetAllBuses() const;
};
