#include <iostream>
#include <cmath>

using namespace std;

// 10-digit odometer-like counter for a base 𝑏
// base b and n number of digits of counter are entered by user

void increment(int b, int n, int* cnt)
{
    
    cout << "\n";

    // check all n values of number
    // we are looking for the first number which is less than b-1
    // this should be increased by 1
    // all numbers we passed on the way should be changed to 0
    // if all numbers are b-1, then terminate

    for (int i = 1; i <= n; i++) // check all n values of number
    {
        int dig = cnt[n-i];
        if (dig == b-1) // the value is as high as possible
        {
            cnt[n-i] = 0; // set equal to 0 and loop to next digit
        }
        else
        {
            cnt[n-i] = dig+1; // found a digit to simply raise
            break; // end loop
        }
    }
}

void reset(int n, int* cnt)
{
    for (int i=0; i<10; ++i) 
    {  
        cnt[i] = 0; // set all values back to 0
    }
}

void print(int n, int* cnt)
{
    cout << "\n";

    for (int i = 0; i < n; i++) // loop n times
    {
        cout << cnt[i]; // print each n element in cnt
    }
}

bool isNull(int n, int* cnt)
{
    for (int i=0; i<10; ++i) 
    {   // Set the first 6 elements in the array
        if (cnt[i] != 0) // found a non-zero value
        {
            return false;
        }
    }
    return true; // all values 0
}

int main()
{
    int b;
    int n;
    int z[10];

    cout << "Please enter base 2 ≤ b ≤ 10: ";
    cin >> b;
    cout << "\nPlease enter number of digits of counter 1 ≤ n ≤ 10: ";
    cin >> n;

    reset(n, z); // set all 10 values to 0

    for (int i = 0; i < n; i++) // loop n times
    {
        cout << z[i]; // print each n element in cnt
    }
    cout << "\n";

    // for each value in z, at space i, where 1 is the first spot, 
    // multiply it by the base b^i and add this to the count
    print(n, z); // but z needs to point to z
    increment(b, n, z);

    while (!isNull(n, z))
    {
        print(n, z); // but z needs to point to z
        increment(b, n, z);
    }
    print(n, z);
    
}
