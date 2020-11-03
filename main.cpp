//#include <iostream>
//#include <vector>
//#include <map>
//#include <sstream>
//#include <utility>
//#include <string>
//#include <math.h>
//#include "reload.h"
//using namespace std;
//
//int main() {
//  Solution sol;
//  cout << sol.addTwoNumbers(left1, right1) << endl;
//
//  return 0;
//}
//

#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;
using Mapping = map<string, vector<string>>;
enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
  string operation_code;
  is >> operation_code;
  if (operation_code == "NEW_BUS") {
    q.type = QueryType::NewBus;
    is >> q.bus;
    int stop_count;
    is >> stop_count;
    vector<string>& stops = q.stops;
    stops.resize(stop_count);
    for (string& stop : stops) {
      cin >> stop;
      stops.push_back(q.bus);
    }
  } else if (operation_code == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    cin >> q.stop;
  } else if (operation_code == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
  } else if (operation_code == "ALL_BUSES") {
    q.type = QueryType::AllBuses;
  }
  return is;
}

struct BusesForStopResponse {
  bool empty = true;
  vector<string> stops = {};
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
  if (r.empty) {
    os << "No stop";
  } else {
    for (const auto& stop : r.stops) {
      os << stop << " ";
    }
    os << endl;
  }
  return os;
}

struct StopsForBusResponse {
  vector<string> res = {};
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  for (const auto& line : r.res) {
    os << line << endl;
  }
  return os;
}

struct AllBusesResponse {
  vector<string> res = {};
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  for (const auto& line : r.res) {
    os << line << endl;
  }
  return os;
}

class BusManager {
 public:
  void AddBus(const string& bus, const vector<string>& stops) {
    vector<string>& _st = buses_to_stops[bus];
    _st.resize(stops.size());
    for (const auto& stop : stops) {
      stops_to_buses[stop].push_back(bus);
    }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
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

  StopsForBusResponse GetStopsForBus(const string& bus) const {
    StopsForBusResponse r = {};
    r.res = vector<string>();
    if (buses_to_stops.count(bus) == 0) {
      r.res.push_back("No bus");
    } else {
      for (const string& stop : buses_to_stops.at(bus)) {
        string current = "";
        current += "Stop : ";
        if (stops_to_buses.at(stop).size() == 1) {
          current += "no interchange";
        } else {
          for (const string& other_bus : stops_to_buses.at(stop)) {
            if (bus != other_bus) {
              current += other_bus + " ";
            }
          }
        }
        r.res.push_back(current);
      }
    }
    return r;
  }

  AllBusesResponse GetAllBuses() const {
    AllBusesResponse r = {};
    r.res = vector<string>();
    if (buses_to_stops.empty()) {
      r.res.push_back("No buses");
    } else {
      string current = "";
      for (const auto& bus_item : buses_to_stops) {
        current += "Bus " + bus_item.first + ": ";
        for (const string& stop : bus_item.second) {
          current += stop + " ";
        }
        r.res.push_back(current);
      }
    }
  }
 private:
  Mapping buses_to_stops, stops_to_buses;

};

// Не меняя тела функции main, реализуйте функции и классы выше

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
      case QueryType::NewBus:
        bm.AddBus(q.bus, q.stops);
        break;
      case QueryType::BusesForStop:
        cout << bm.GetBusesForStop(q.stop) << endl;
        break;
      case QueryType::StopsForBus:
        cout << bm.GetStopsForBus(q.bus) << endl;
        break;
      case QueryType::AllBuses:
        cout << bm.GetAllBuses() << endl;
        break;
    }
  }

  return 0;
}

