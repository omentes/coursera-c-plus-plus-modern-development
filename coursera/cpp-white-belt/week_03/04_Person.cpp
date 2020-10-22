#include <map>
#include <string>

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
    for (const auto& [current, first_name] : store) {
      if (current > year) {
        break;
      } else if (current == year) {
        result = first_name;
        break ;
      }
      result = first_name;
    }
    return result;
  }
};
