#include <iostream>
#include <cmath>

using namespace std;

// 10-digit odometer-like counter for a base 𝑏
// base b and n number of digits of counter are entered by user

int sum_digits(int s, int in)
{
    if (in == 0)
    {
        return s;
    }
    else
    {
        int first = in % 10;
        int newin = (in - first) / 10;
        return sum_digits(first+s, newin);
    }
}



int main()
{
    int in;

    cout << "Please enter an integer: ";
    cin >> in;

    int sum = sum_digits(0, in); // returns sum of integers in string in

    cout << "Here's the sum of it's digits: " << sum;
}
