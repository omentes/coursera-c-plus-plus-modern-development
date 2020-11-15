#include "bus_manager.h"

void BusManager::AddBus(const string& bus, const vector<string>& stops) {
  vector<string> saveStops;
  for (const auto& stop : stops) {
    saveStops.push_back(stop);
    stops_to_buses[stop].push_back(bus);
  }
  buses_to_stops[bus] = saveStops;
}

BusesForStopResponse BusManager::GetBusesForStop(const string& stop) const {
  BusesForStopResponse result;
  result.stops = {};
  if (stops_to_buses.count(stop) != 0) {
    for (const string& bus : stops_to_buses.at(stop)) {
      result.stops.push_back(bus);
    }
    result.empty = false;
  }
  return result;
}

StopsForBusResponse BusManager::GetStopsForBus(const string& bus) const {
  StopsForBusResponse r = {};
  r.stopsForBus = vector<string>();
  if (buses_to_stops.count(bus) == 0) {
    r.stopsForBus.push_back("No bus");
  } else {
    for (const string& stop : buses_to_stops.at(bus)) {
      string current = "Stop " + stop + ": ";
      if (stops_to_buses.at(stop).size() == 1) {
        current += "no interchange";
      } else {
        bool trailingSpace = false;
        for (const string& other_bus : stops_to_buses.at(stop)) {
          if (bus != other_bus) {
            if (trailingSpace) {
              current += " ";
            }
            trailingSpace = true;
            current += other_bus;
          }
        }
      }
      r.stopsForBus.push_back(current);
    }
  }
  return r;
}

AllBusesResponse BusManager::GetAllBuses() const {
  AllBusesResponse r = {};
  r.allBuses = vector<string>();
  if (buses_to_stops.empty()) {
    r.allBuses.push_back("No buses");
  } else {
    for (const auto& bus_item : buses_to_stops) {
      string current;
      current += "Bus " + bus_item.first + ": ";
      bool trailingSpace = false;
      for (const string& stop : bus_item.second) {
        if (trailingSpace) {
          current += " ";
        }
        trailingSpace = true;
        current += stop;
      }
      r.allBuses.push_back(current);
    }
  }
  return r;
}

