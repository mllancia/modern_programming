// class date, type conversion operators
// Frederick Lancia 
// Sheet 8 exercise 23

#ifndef DATE_H
#define DATE_H

#include <cstddef>
#include <string>
#include <iostream>
using namespace std;

namespace mydate {
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
        explicit Date(int d = 1, int m = 1, int y = stdYear) : day{d}, month{m},
                                                                year{y}
        {
            checkDate();
        }
        explicit Date(const string& s);
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
        Date& operator++();
        Date operator++(int);
        auto operator<=>(const Date& d) const;
        explicit operator string() const;
        void print() const { cout << day << '.' << month << '.' << year << endl; }

    };

    istream& operator>>(istream& is, Date& d);
    ostream& operator<<(ostream& os, const Date& d);
}
#endif