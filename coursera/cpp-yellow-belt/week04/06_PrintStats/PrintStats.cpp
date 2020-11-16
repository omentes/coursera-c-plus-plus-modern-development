
void PrintStats(vector<Person> persons) {
  cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
  auto women = partition(persons.begin(), persons.end(), [](Person current) { return current.gender == Gender::FEMALE; } );
  cout << "Median age for females = " << ComputeMedianAge(persons.begin(), women) << endl;
  auto men = partition(persons.begin(), persons.end(), [](Person current) { return current.gender == Gender::MALE; } );
  cout << "Median age for males = " << ComputeMedianAge(persons.begin(), men) << endl;
  auto women_is_employed = partition(persons.begin(), persons.end(), [](Person current) { return current.gender == Gender::FEMALE && current.is_employed; } );
  cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), women_is_employed) << endl;
  auto women_is_not_employed = partition(persons.begin(), persons.end(), [](Person current) { return current.gender == Gender::FEMALE && !current.is_employed; } );
  cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), women_is_not_employed) << endl;
  auto men_is_employed = partition(persons.begin(), persons.end(), [](Person current) { return current.gender == Gender::MALE && current.is_employed; } );
  cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), men_is_employed) << endl;
  auto men_is_not_employed = partition(persons.begin(), persons.end(), [](Person current) { return current.gender == Gender::MALE && !current.is_employed; } );
  cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), men_is_not_employed) << endl;
}

