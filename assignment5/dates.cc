// class date, delegating constructors and other details
// author:  Holger Arndt
// version: 27.03.2023

#include <iostream>

using namespace std;

class Date
{
private:
  int day{1};
  int month{1};
  int year{stdYear};
  static inline const int daysPerMonth[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30,
                                          31, 30, 31 };
  static const int stdYear{1970};
  static bool isLeapYear(int year)
  { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
  void checkDate();
public:
  Date(int d, int m, int y) : day{d}, month{m}, year{y}
  { checkDate(); }
  Date(int d, int m) : Date{d, m, stdYear} {}
  Date() = default;
  Date(const Date& d2) = delete;
  int getDay() const { return day; }
  int getMonth() const { return month; }
  int getYear() const { return year; }
  void setDate(int d, int m, int y)
  {
    day = d;
    month = m;
    year = y;
    checkDate();
  }
  Date& incDay();
  void print() const { cout << day << '.' << month << '.' << year << endl; }
};

void Date::checkDate()
{
  if (year < 1 || month < 1 || month > 12 || day < 1
      || (day > daysPerMonth[month - 1]
          && !(day == 29 && month == 2 && isLeapYear(year))))
    {
      day = month = 1;
      year = stdYear;
    }
}

Date& Date::incDay()
{
  ++day;
  if (day > daysPerMonth[month - 1]
      && !(day == 29 && month == 2 && isLeapYear(year)))
    {
      day = 1;
      if (++month == 13)
        {
          month = 1;
          ++year;
        }
    }
  return *this;
}

int main()
{
  Date d1{23, 6, 2002};
  d1.print();
  Date d2{23, 6};
  d2.print();
  Date d3;
  d3.print();
  // Date d4{d3}; // not allowed, copy constructor is deleted
}
