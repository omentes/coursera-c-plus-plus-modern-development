struct Specialization {
 public:
  explicit Specialization(const string& value) {
    name = value;

  }
  string name;
};
struct Course {
 public:
  explicit Course(const string& value) {
    name = value;

  }
  string name;
};
struct Week {
 public:
  explicit Week(const string& value) {
    name = value;

  }
  string name;
};
struct LectureTitle {
 public:
  explicit LectureTitle (
      Specialization specialization_value,
      Course course_value,
      Week week_value
  ) {
    specialization = specialization_value.name;
    course = course_value.name;
    week = week_value.name;
  }
  string specialization;
  string course;
  string week;
};
