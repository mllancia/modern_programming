#include <iostream>
#include <cmath>

using namespace std;


// distance formula 
int calc(int hour, int min, int sec, string period)
{
    if (period == "pm" && hour != 12)
    {
        hour = hour+12;
    }
    else if (period == "am" && hour == 12)
    {
        hour = 0; // after midnight
    }

    int d = hour*60*60 + min*60 + sec;
    return d;
}

int main()
{
    // exercise 3
    // Get user input from the keyboard1 30 0 am Since 0:00 5400 seconds have elapsed.
    int hour, min, sec;
    string period;

    cout << "Enter a time (format: hh mm ss am/pm): ";
    cin >> hour >> min >> sec >> period;
    cout << "\n";

    int seconds = calc(hour, min, sec, period);

    cout << "Since 0:00 " << seconds << " seconds have elapsed.";
}
