#include <vector>
#include <iostream>
#include <sstream>
#include "phone_number.h"

/* Принимает строку в формате +XXX-YYY-ZZZZZZ
   Часть от '+' до первого '-' - это код страны.
   Часть между первым и вторым символами '-' - код города
   Всё, что идёт после второго символа '-' - местный номер.
   Код страны, код города и местный номер не должны быть пустыми.
   Если строка не соответствует этому формату, нужно выбросить исключение invalid_argument. Проверять, что номер содержит только цифры, не нужно.

   Примеры:
   * +7-495-111-22-33
   * +7-495-1112233
   * +323-22-460002
   * +1-2-coursera-cpp
   * 1-2-333 - некорректный номер - не начинается на '+'
   * +7-1233 - некорректный номер - есть только код страны и города
*/
PhoneNumber::PhoneNumber(const string &international_number) {
  if (international_number[0] != '+') {
    throw invalid_argument("First character was not a plus");
  }
  vector<string> result;
  stringstream ss(international_number);
  string item;

  while (getline(ss, item, '-')) {
    result.push_back(item);
  }
  if (result.size() < 3 ) {
    throw invalid_argument("Number was contains min 3 parts");
  }
  country_code_ = string(result[0].begin() + 1, result[0].end());;
  city_code_ = result[1];
  for (int i = 2; i < static_cast<int>(result.size()); ++i) {
    if (!local_number_.empty()) {
      local_number_ += "-";
    }
    local_number_ += result[i];
  }
  if (local_number_.empty()) {
    throw invalid_argument("Local number was contains not empty");
  }
}

string PhoneNumber::GetCountryCode() const {
  return country_code_;
}
string PhoneNumber::GetCityCode() const {
  return city_code_;
}
string PhoneNumber::GetLocalNumber() const {
  return local_number_;
}
string PhoneNumber::GetInternationalNumber() const {
  return "+" + country_code_ + "-" + city_code_ + "-" + local_number_;
}
