#include <iostream>
#include <vector>

using namespace std;

class Student {
 public:
  Student(
      const string& new_first_name,
      const string& new_last_name,
      const int& new_day,
      const int& new_month,
      const int& new_year
  ) {
    first_name = new_first_name;
    last_name = new_last_name;
    day = new_day;
    month = new_month;
    year = new_year;
  }
  int getDay() const {
    return day;
  }
  int getMonth() const {
    return month;
  }
  int getYear() const {
    return year;
  }
  string getName() const {
    return first_name + " " + last_name;
  }
 private:
  string first_name;
  string last_name;
  int day;
  int month;
  int year;
};
;
void PrintStudentById(Student student, string command) {
  if (command == "name") {
    cout << student.getName() << endl;
  } else if (command == "date") {
    cout << student.getDay() << "." << student.getMonth() << "." << student.getYear() << endl;
  } else {
    cout << "bad request" << endl;
  }

}
int main() {
  int lines, day, month, year, it;
  string first_name,last_name, command;
  vector<Student> students;
  cin >> lines;
  while (lines--) {
    cin >> first_name >> last_name >> day >> month >> year;
    students.push_back(Student(first_name, last_name, day, month, year));
  }
  cin >> lines;
  while (lines--) {
    cin >> command;
    cin >> it;
    if (students.size() >= it && it > 0) {
      PrintStudentById(students[it-1], command);
    } else {
      cout << "bad request" << endl;
    }
  }
  return 0;
}

