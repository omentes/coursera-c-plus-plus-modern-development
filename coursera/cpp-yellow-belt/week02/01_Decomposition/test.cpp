#include <string>
#include <iostream>
#include <cassert>
#include <utility>
#include <vector>
#include <map>
#include "reload.h"

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
      is >> stop;
    }
  } else if (operation_code == "BUSES_FOR_STOP") {
    q.type = QueryType::BusesForStop;
    is >> q.stop;
  } else if (operation_code == "STOPS_FOR_BUS") {
    q.type = QueryType::StopsForBus;
    is >> q.bus;
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
  vector<string> stopsForBus = {};
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  for (const auto& line : r.stopsForBus) {
    os << line << endl;
  }
  return os;
}

struct AllBusesResponse {
  vector<string> allBuses = {};
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  for (const auto& line : r.allBuses) {
    os << line << endl;
  }
  return os;
}

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

  void AddBus(const string& bus, const vector<string>& stops) {
    vector<string> saveStops;
    for (const auto& stop : stops) {
      saveStops.push_back(stop);
      stops_to_buses[stop].push_back(bus);
    }
    buses_to_stops[bus] = saveStops;
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

  AllBusesResponse GetAllBuses() const {
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
};

// Не меняя тела функции main, реализуйте функции и классы выше

//int main() {
//  int query_count;
//  Query q;
//
//  cin >> query_count;
//
//  BusManager bm;
//  for (int i = 0; i < query_count; ++i) {
//    cin >> q;
//    switch (q.type) {
//      case QueryType::NewBus:
//        bm.AddBus(q.bus, q.stops);
//        break;
//      case QueryType::BusesForStop:
//        cout << bm.GetBusesForStop(q.stop) << endl;
//        break;
//      case QueryType::StopsForBus:
//        cout << bm.GetStopsForBus(q.bus) << endl;
//        break;
//      case QueryType::AllBuses:
//        cout << bm.GetAllBuses() << endl;
//        break;
//    }
//  }
//
//  return 0;
//}

void assertQuery(const Query &fromStream, const Query &expected) {
  assert(expected.type == fromStream.type);
  assert(expected.bus == fromStream.bus);
  assert(expected.stop == fromStream.stop);
  assert(expected.stops == fromStream.stops);
}
void TestQueryStopsForBus() {
  Query fromStream;
  stringstream s("STOPS_FOR_BUS 32K");
  s >> fromStream;
  const Query expexted = {
      QueryType::StopsForBus,
      "32K",
      "",
      {},
  };

  assertQuery(fromStream, expexted);
}
void TestQueryBusesForStop() {
  Query fromStream;
  stringstream s("BUSES_FOR_STOP Vnukovo");
  s >> fromStream;
  const Query expexted = {
      QueryType::BusesForStop,
      "",
      "Vnukovo",
      {},
  };

  assertQuery(fromStream, expexted);
}
void TestQueryNewBus() {
  Query fromStream;
  stringstream s("NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo");
  s >> fromStream;
  const Query expexted = {
      QueryType::NewBus,
      "32",
      "",
      {"Tolstopaltsevo", "Marushkino", "Vnukovo"},
  };

  assertQuery(fromStream, expexted);
}
void TestQueryAllBuses() {
  Query fromStream;
  stringstream s("ALL_BUSES");
  s >> fromStream;
  const Query expexted = {
      QueryType::AllBuses,
      "",
      "",
      {},
  };

  assertQuery(fromStream, expexted);
}

void TestAddOneBus() {
  BusManager bm;
  bm.AddBus("32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"});

  const BusManager expected(
      Mapping{{"32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"}}},
      Mapping{{"Tolstopaltsevo", {"32"}},{"Marushkino", {"32"}},{"Vnukovo", {"32"}}}
  );
  assert(bm.buses_to_stops == expected.buses_to_stops);
  assert(bm.stops_to_buses == expected.stops_to_buses);
}
void TestAddTwoBuses() {
  BusManager bm;
  bm.AddBus("32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"});
  bm.AddBus("32K", {"Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Skolkovo"});

  const BusManager expected(
      Mapping{
          {"32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"}},
          {"32K", {"Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Skolkovo"}},
      },
      Mapping{
          {"Tolstopaltsevo", {"32", "32K"}},
          {"Marushkino", {"32", "32K"}},
          {"Vnukovo", {"32", "32K"}},
          {"Peredelkino", {"32K"}},
          {"Solntsevo", {"32K"}},
          {"Skolkovo", {"32K"}},
      }
  );
  assert(bm.buses_to_stops == expected.buses_to_stops);
  assert(bm.stops_to_buses == expected.stops_to_buses);
}

void TestBusesForStopCanEmpty() {
  BusManager bm;
  BusesForStopResponse res = bm.GetBusesForStop("Marushkino");
  assert(res.stops == vector<string>{});
  assert(res.empty == true);
}
void TestBusesForStopCanEmptyAndCanPrintCorrectly() {
  BusManager bm;
  BusesForStopResponse response = bm.GetBusesForStop("Marushkino");
  stringstream s;
  s << response;
  string first, second;
  s >> first >> second;
  assert(first + " " + second == "No stop");
}
void TestBusesForStopCanNotEmpty() {
  BusManager bm = {
      Mapping{
          {"32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"}},
          {"32K", {"Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Skolkovo"}},
      },
      Mapping{
          {"Tolstopaltsevo", {"32", "32K"}},
          {"Marushkino", {"32", "32K"}},
          {"Vnukovo", {"32", "32K"}},
          {"Peredelkino", {"32K"}},
          {"Solntsevo", {"32K"}},
          {"Skolkovo", {"32K"}},}
  };
  BusesForStopResponse response = bm.GetBusesForStop("Vnukovo");
  vector<string> test = {"32", "32K"};
  assert(response.stops == test);
  assert(response.empty == false);
  BusesForStopResponse response2 = bm.GetBusesForStop("Peredelkino");
  vector<string> test2 = {"32K"};
  assert(response2.stops == test2);
  assert(response2.empty == false);
}
void TestBusesForStopCanNotEmptyAndCanPrintCorrectly() {
  BusManager bm = {
      Mapping{
          {"32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"}},
          {"32K", {"Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Skolkovo"}},
      },
      Mapping{
          {"Tolstopaltsevo", {"32", "32K"}},
          {"Marushkino", {"32", "32K"}},
          {"Vnukovo", {"32", "32K"}},
          {"Peredelkino", {"32K"}},
          {"Solntsevo", {"32K"}},
          {"Skolkovo", {"32K"}},}
  };
  BusesForStopResponse response = bm.GetBusesForStop("Vnukovo");
  stringstream s;
  s << response;
  string first, second;
  s >> first >> second;
  assert(first + " " + second == "32 32K");
}

void TestStopsForBusCanEmpty() {
  BusManager bm;
  StopsForBusResponse res = bm.GetStopsForBus("32");
  assert(res.stopsForBus == vector<string>{"No bus"});
}
void TestStopsForBusCanEmptyAndCanPrintCorrectly() {
  BusManager bm;
  StopsForBusResponse response = bm.GetStopsForBus("32");
  stringstream s;
  s << response;
  string first, second;
  s >> first >> second;
  assert(first + " " + second == "No bus");
}
void TestStopsForBusCanNotEmpty() {
  BusManager bm = {
      Mapping{
          {"32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"}},
          {"32K", {"Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Skolkovo"}},
      },
      Mapping{
          {"Tolstopaltsevo", {"32", "32K"}},
          {"Marushkino", {"32", "32K"}},
          {"Vnukovo", {"32", "32K"}},
          {"Peredelkino", {"32K"}},
          {"Solntsevo", {"32K"}},
          {"Skolkovo", {"32K"}},}
  };
  StopsForBusResponse res = bm.GetStopsForBus("32K");
  const vector<string> result = {
      "Stop Tolstopaltsevo: 32",
      "Stop Marushkino: 32",
      "Stop Vnukovo: 32",
      "Stop Peredelkino: no interchange",
      "Stop Solntsevo: no interchange",
      "Stop Skolkovo: no interchange",
  };
  assert(result == res.stopsForBus);
}
void TestStopsForBusCanNotEmptyAndCanPrintCorrectly() {
  BusManager bm = {
      Mapping{
          {"32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"}},
          {"32K", {"Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Skolkovo"}},
      },
      Mapping{
          {"Tolstopaltsevo", {"32", "32K"}},
          {"Marushkino", {"32", "32K"}},
          {"Vnukovo", {"32", "32K"}},
          {"Peredelkino", {"32K"}},
          {"Solntsevo", {"32K"}},
          {"Skolkovo", {"32K"}},}
  };
  StopsForBusResponse response = bm.GetStopsForBus("32K");
  const vector<string> result = {
      "Stop", "Tolstopaltsevo:", "32",
      "Stop", "Marushkino:", "32",
      "Stop", "Vnukovo:", "32",
      "Stop", "Peredelkino:", "no", "interchange",
      "Stop", "Solntsevo:", "no", "interchange",
      "Stop", "Skolkovo:", "no", "interchange",
  };
  stringstream s;
  s << response;
  string word;
  for (const auto& current : result) {
    s >> word;
    assert(word == current);
  }
}

void TestAllBusesCanEmpty() {
  BusManager bm;
  AllBusesResponse res = bm.GetAllBuses();
  assert(res.allBuses == vector<string>{"No buses"});
}
void TestAllBusesCanEmptyAndCanPrintCorrectly() {
  BusManager bm;
  AllBusesResponse response = bm.GetAllBuses();
  stringstream s;
  s << response;
  string first, second;
  s >> first >> second;
  assert(first + " " + second == "No buses");
}
void TestAllBusesCanNotEmpty() {
  BusManager bm = {
      Mapping{
          {"32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"}},
          {"32K", {"Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Skolkovo"}},
      },
      Mapping{
          {"Tolstopaltsevo", {"32", "32K"}},
          {"Marushkino", {"32", "32K"}},
          {"Vnukovo", {"32", "32K"}},
          {"Peredelkino", {"32K"}},
          {"Solntsevo", {"32K"}},
          {"Skolkovo", {"32K"}},}
  };
  AllBusesResponse response = bm.GetAllBuses();
  const vector<string> result = {
      "Bus 32: Tolstopaltsevo Marushkino Vnukovo",
      "Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo",
  };
  assert(result == response.allBuses);
}
void TestAllBusesCanNotEmptyAndCanPrintCorrectly() {
  BusManager bm = {
      Mapping{
          {"32", {"Tolstopaltsevo", "Marushkino", "Vnukovo"}},
          {"32K", {"Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Skolkovo"}},
      },
      Mapping{
          {"Tolstopaltsevo", {"32", "32K"}},
          {"Marushkino", {"32", "32K"}},
          {"Vnukovo", {"32", "32K"}},
          {"Peredelkino", {"32K"}},
          {"Solntsevo", {"32K"}},
          {"Skolkovo", {"32K"}},}
  };
  AllBusesResponse response = bm.GetAllBuses();
  const vector<string> result = {
      "Bus", "32:", "Tolstopaltsevo", "Marushkino", "Vnukovo",
      "Bus", "32K:", "Tolstopaltsevo", "Marushkino", "Vnukovo", "Peredelkino", "Solntsevo", "Skolkovo",
  };
  stringstream s;
  s << response;
  string word;
  for (const auto& current : result) {
    s >> word;
    assert(word == current);
  }
}
int main() {

  TestQueryAllBuses();
  TestQueryNewBus();
  TestQueryBusesForStop();
  TestQueryStopsForBus();

  TestAddOneBus();
  TestAddTwoBuses();

  TestBusesForStopCanEmpty();
  TestBusesForStopCanNotEmpty();
  TestBusesForStopCanEmptyAndCanPrintCorrectly();
  TestBusesForStopCanNotEmptyAndCanPrintCorrectly();

  TestStopsForBusCanEmpty();
  TestStopsForBusCanEmptyAndCanPrintCorrectly();
  TestStopsForBusCanNotEmpty();
  TestStopsForBusCanNotEmptyAndCanPrintCorrectly();

  TestAllBusesCanEmpty();
  TestAllBusesCanEmptyAndCanPrintCorrectly();
  TestAllBusesCanNotEmpty();
  TestAllBusesCanNotEmptyAndCanPrintCorrectly();
  return 0;
}
