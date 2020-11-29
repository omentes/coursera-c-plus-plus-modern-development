#include <map>
#include <string>
#include <algorithm>

class Person {
 public:
  void ChangeFirstName(int year, const string& first_name) {
    date_to_first_name[year] = first_name;
  }
  void ChangeLastName(int year, const string& last_name) {
    date_to_last_name[year] = last_name;
  }
  string GetFullName(int year) {
    string first = getName(year, date_to_first_name);
    string last = getName(year, date_to_last_name);
    if (last == "unknown" || first == "unknown") {
      if (last == first) {
        return "Incognito";
      }
      return (last == "unknown") ? first + " with unknown last name" : last + " with unknown first name";
    }
    return first + " " + last;
  }

 private:
  map <int, string> date_to_first_name;
  map <int, string> date_to_last_name;

  string getName(int year, map <int, string>& store) {
    string result = "unknown";
    auto iter_after = store.upper_bound(year);
    if (iter_after != store.begin()) {
      result = (--iter_after)->second;
    }
    return result;
  }
};
