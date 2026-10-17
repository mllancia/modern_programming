// class date, both constructors combined
// author:  Holger Arndt
// version: 27.03.2023

#include <iostream>

using namespace std;

class Date
{
private:
  int day;
  int month;
  int year;
  static inline const int daysPerMonth[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30,
                                          31, 30, 31 };
  static const int stdYear{1970};
  static bool isLeapYear(int year)
  { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
  void checkDate();
public:
  explicit Date(int d = 1, int m = 1, int y = stdYear)
  {
    day = d;
    month = m;
    year = y;
    checkDate();
  }
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
  int dayInYear() const;
  Date& incMonth();
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

int Date::dayInYear() const
{
  int count = day;
  if (isLeapYear(year) && (month > 2))
  {
    count = count + 1;
  }
  for (int i = 0; i < month-1; i++)
  {
    count = count + daysPerMonth[i];
  }
  return count;
}

Date& Date::incMonth()
{
  if (month == 12)
  {
    month = 1;
    ++year;
  }

  month++;

  if (!((month == 2) && isLeapYear(year) && (day == 29)) && 
    (daysPerMonth[month-1] < day))
  {
    ++month;
    day = 1;
  } 
  return *this;

}

int main()
{
  Date d1;
  d1.print();
  Date d2{13, 7};
  d2.print();
  Date d3{13, 7, 1999};
  d3.print();

  cout << d3.dayInYear() << endl;

  // d3 = 4; // without explicit → 4.1.1970
}
