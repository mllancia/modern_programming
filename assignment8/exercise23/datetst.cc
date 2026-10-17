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

using namespace mydate;
using namespace std;

int main()
{
  string s;
  cout << "Enter a date string: ";
  cin >> s;
  Date d{s};
  cout << "as date: " << d << endl;
  string s2{d};
  cout << "back as string: " << s2 << endl;
}
