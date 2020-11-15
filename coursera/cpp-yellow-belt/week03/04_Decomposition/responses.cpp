
#include "responses.h"

using namespace std;

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

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
  for (const auto& line : r.stopsForBus) {
    os << line << endl;
  }
  return os;
}

ostream& operator << (ostream& os, const AllBusesResponse& r) {
  for (const auto& line : r.allBuses) {
    os << line << endl;
  }
  return os;
}