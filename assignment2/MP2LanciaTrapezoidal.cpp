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
    // exercise 4
    // reads in a number 𝑛 of intervals and computes integral using the trapezoidal rule
    int n;
    double f = 0.0;

    cout << "How many intervals? ";
    cin >> n;
    cout << "\n";

    if (n > 0)
    {
        for (int i = 0; i <= n; i++) 
        {
            double x = (double)i / n;
            if (i == 0 or i==n)
            {
                f = f + 4.0/(1+pow(x,2));     
            }
            else
            {
                f = f + 2 * 4/(1+pow(x,2));
            }
        }
        f = f  / (2 * n);
    }

    cout << "Pi approximated with the trapezoidal rule is " << f;
}