// class date, type conversion operators
// Frederick Lancia 
// Sheet 8 exercise 23

#include <cstddef>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include "dates.h"

using namespace std;

namespace mydate {

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

    Date& Date::operator++()
    {
    incDay();
    return *this;
    }

    Date Date::operator++(int)
    {
    Date temp{*this};
    incDay();
    return temp;
    }

    auto Date::operator<=>(const Date& d) const
    {
    if (auto ycmp{year <=> d.year}; ycmp == 0)
        if (auto mcmp{month <=> d.month}; mcmp == 0)
        return day <=> d.day;
        else
        return mcmp;
    else
        return ycmp;
    }

    Date operator""_ymd(unsigned long long int n)
    {
    return Date(n % 100, n % 10000 / 100, n / 10000);
    }

    Date operator""_ymd(const char* s, size_t)
    {
    return operator""_ymd(atoll(s));
    }

    ostream& operator<<(ostream& os, const Date& d)
    {
    os << setw(2) << setfill('0') << d.getDay() << '.'
        << setw(2) << d.getMonth() << '.'
        << d.getYear() << setfill(' ');
    return os;
    }

    istream& operator>>(istream& is, Date& d)
    {
    int dd, mm, yy;
    is >> dd;
    is.ignore(1, '.');
    is >> mm;
    is.ignore(1, '.');
    is >> yy;
    d.setDate(dd, mm, yy);
    return is;
    }

    Date::Date(const string& s)
    {
    istringstream{s} >> *this;
    }

    Date::operator string() const
    {
    return (ostringstream{} << *this).str();
    }
}