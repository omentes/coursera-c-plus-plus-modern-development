#include <map>
#include <string>
#include <vector>
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

  string GetFullNameWithHistory(int year) {
    string first = getName(year, date_to_first_name);
    string last = getName(year, date_to_last_name);
    if (last == "unknown" || first == "unknown") {
      if (last == first) {
        return "Incognito";
      }
      string tmp = getPrevName(year, date_to_first_name);
      string tmp2 = getPrevName(year, date_to_last_name);
      tmp = tmp.empty() ? tmp : " " + tmp;
      tmp2 = tmp2.empty() ? tmp2 : " " + tmp2;
      return (last == "unknown") ?
             first + tmp + " with unknown last name" :
             last + tmp2 + " with unknown first name";
    }
    string tmp = getPrevName(year, date_to_first_name);
    string tmp2 = getPrevName(year, date_to_last_name);
    tmp = tmp.empty() ? tmp : tmp + " ";
    tmp2 = tmp2.empty() ? tmp2 : " " + tmp2;
    return first + " " + tmp
        + last  + tmp2;
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

  string getPrevName(int year, map <int, string>& store) {
    string result = "";
    vector<string> prev;
    for (const auto& [current, first_name] : store) {
      if (current > year) {
        break;
      } else if (current == year) {
        prev.push_back(first_name);
        break ;
      }
      prev.push_back(first_name);
    }
    if (!prev.empty()) {
      reverse(prev.begin(), prev.end());
      string prevName = prev[0];
      for (const auto& item : prev) {
        if (prevName != item) {
          result = (!result.empty()) ? result += ", ": result;
          result += item;
        }
        prevName = item;
      }

      if (!result.empty()) {
        result = "(" + result + ")";
      }
    }
    return result;
  }
};
