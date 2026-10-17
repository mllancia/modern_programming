#include <iostream>
#include <cmath>

using namespace std;

// take integer and sum it's digits

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
