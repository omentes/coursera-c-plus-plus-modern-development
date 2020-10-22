#include <iostream>
#include <exception>
#include <string>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
using namespace std;

class Date {
 public:
  Date(int new_day, int new_month, int new_year) {
    if (new_month < 1 || new_month > 12) {
      throw runtime_error("Month value is invalid: " + to_string(new_month));
    }
    if (new_day < 1 || new_day > 31) {
      throw runtime_error("Day value is invalid: " + to_string(new_day));
    }
    year = new_year;
    month = new_month;
    day = new_day;
  }
  int GetYear() const {
    return year;
  }
  int GetMonth() const {
    return month;
  }
  int GetDay() const {
    return day;
  }
 private:
  int year;
  int month;
  int day;
};

bool operator<(const Date& lhs, const Date& rhs) {
  return lhs.GetYear() * lhs.GetMonth() * lhs.GetDay() <
      rhs.GetYear() * rhs.GetMonth() * rhs.GetDay();
}

ostream& operator<<(ostream& stream, const Date& date) {
  stream << setw(4) << setfill('0') << date.GetYear() << "-"
         << setw(2) << setfill('0')<< date.GetMonth() << "-"
         << setw(2) << setfill('0')<< date.GetDay();
  return stream;
}

class Event {
 public:
  Event(const string& new_event) {
    event = new_event;
  }
  string GetEvent() const {
    return event;
  }
 private:
  string event;
};

bool operator<(const Event& lhs, const Event& rhs) {
  return lhs.GetEvent() < rhs.GetEvent();
}

ostream& operator<<(ostream& stream, const Event& event) {
  stream << event.GetEvent();
  return stream;
}

class Database {
 public:
  void AddEvent(const Date& date, Event event) {
    db[date].insert(Event(event));
  }
  bool DeleteEvent(const Date& date, Event event) {
    return db[date].erase(Event(event));

  }
  int DeleteDate(const Date& date) {
    int i = db[date].size();
    db.erase(date);
    return i;
  }

  void Print() const {
    for (const auto& [date, events] : db) {
      PrintDate(date);
    }
  }
  void PrintDate(const Date& date, bool print_date = true) const {
    set<Event> date_db;
    if (db.count(date) > 0) {
      date_db = db.at(date);  // теперь всё хорошо
    }
    for (const auto& event : date_db) {
      if (print_date) {
        cout << date << " " << event << endl;
        continue;
      }
      cout << event << endl;
    }
  }
 private:
  map<Date, set<Event>> db;
};

string GetSecondPartOfCommand(istream& iss) {
  string first;
  iss >> first >> first;
  return first;
}

Date getDateFromInput(istream& first, istream& second) {
  int year, month, day;
  char delim1, delim2;
  first >> year >> delim1 >> month >> delim2 >> day;
  if (first.fail() || delim1 != '-' || delim2 != '-' || first.peek() != -1 && first.peek() != 32) {
    string tmp = GetSecondPartOfCommand(second);
    cout << "Wrong date format: " << tmp << endl;
    throw invalid_argument("");
  }
  return Date(day, month, year);
}
/**
 *  void Find(const Date& date) const;
 */


int main() {
  Database db;

  string command;
  while (getline(cin, command)) {
    if (command == "") {
      continue;
    }
    stringstream ss(command), ss_copy(command);
    string first;
    ss >> first;
    try {
      if ("Add" == first) {
        Date date = getDateFromInput(ss, ss_copy);
        ss >> command;
        db.AddEvent(date, Event(command));
      } else if ("Del" == first) {
//        cout << "DEBUG: " << command << endl;
        Date date = getDateFromInput(ss, ss_copy);
        if (ss.eof()) {
          cout << "Deleted " << db.DeleteDate(date) << " events" << endl;
          continue;
        }
        string tmp;
        ss >> tmp;

        bool s = db.DeleteEvent(date, Event(tmp));
        tmp = (s) ? "Deleted successfully" : "Event not found";
        cout << tmp << endl;
      } else if ("Find" == first) {
        Date date = getDateFromInput(ss, ss_copy);
        db.PrintDate(date, false);
      } else if ("Print" == first) {
        db.Print();
      } else {
        cout << "Unknown command: " << command << endl;
      }
    } catch (exception& e) {
      string tmp = e.what();
      if (!tmp.empty()) {
        cout << e.what() << endl;
      }
    }
  }

  return 0;
}


