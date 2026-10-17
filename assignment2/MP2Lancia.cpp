#include <iostream>
#include <cmath>
using namespace std;


// exercise 1
// compute distance and velocity after time

// distance formula 
double distance(int t)
{
    double d = .5 * 9.81 * pow(t,2); 
    return d;
}

double velocity(int t)
{
    double d = 3.6 * .5 * 9.81 * pow(t,2);
    return d;
}

double convertMetersPerSecondToKilosPerHour(double v)
{
    return 3.6 * v;
}

// computes the distance and velocity after a certain amount of time for a free fall in a vacuum. 
// The computation is to be repeated for different entered time values until a negative number is entered.

void freeFallVac()
{
    double t = 1;
    double d, v, vk;

    while (t>0) // the loop will end with break command (when a negative value is entered)
    {
        cout << "Let's compute the distance and velocity after a certain amount of time for a free fall in a vacuum.\nHow much time in seconds? ";
        cin >> t; // Get user input from the keyboard

         cout << "\n";

        if (t<0) // end loop if negative value
        {
            cout << "can't calculate negatives. Ending program..."
            break;
        }

        d = distance (t);
        v = velocity (t);
        vk = convertMetersPerSecondToKilosPerHour(t);

        cout << "Distance in meters: " << d << "\n";
        cout << "Velocity in meters per second: " << v << "\n";
        cout << "Velocity in kilometers per hour: " << vk << "\n";
    }
}

int main()
{
    // exercise 1
    // compute distance and velocity after time

    freeFallVac();

}
