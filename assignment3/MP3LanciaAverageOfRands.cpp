#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    srand(time(0));
    int in;
    double av = 0;


    cout << "Please enter a natural number (an integer 1 or greater): ";
    cin >> in;
    int arr[in];

    for (int i = 0; i < in; i++)
    {
        arr[i] =  (rand() % 6)+1;
    }

    for (int i = 0; i < in; i++)
    {
        cout << arr[i];
        av = av + arr[i];
    }
    av = av / in;

    cout << "Here's the average of the numbers generated: " << av;
}