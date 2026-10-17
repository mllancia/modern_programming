// three different programs in one
// author:  Holger Arndt
// version: 25.11.2025
// program for sheet 7, exercise 22

#include <algorithm>
#include <chrono>
#include <ctime>
#include <iostream>
#include <iterator>
#include <locale>
#include <thread>

using namespace std;
using namespace std::chrono;

int main()
{
#if NUM == 1
  cout << "Hi! You compiled the first version." << endl;
#elif NUM == 2
  const auto now{system_clock::to_time_t(system_clock::now())};
  cout << "Current date and time: " << ctime(&now);
#else
  locale::global(locale{""});
  wstring s1, s2;
  wcout << L"enter a string (non-latin characters allowed): ";
  wcin >> s1;
  wcout << L"I will reverse it: ";
  for (int i{0}; i < 60; ++i)
    {
      this_thread::sleep_for(milliseconds{50});
      wcout << L'·' << flush;
    }
  ranges::reverse_copy(s1, back_inserter(s2));
  wcout << endl << s2 << endl;
#endif
}
