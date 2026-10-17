#include <iostream>

using namespace std;

class Weather
{
private:
    string description;
    float temperature;
    float windspeed;
    int humidity;
public:
    float getWindChill();
    void print();

    // constructor
    Weather(string d, float t, float w, int h)
    {
        description = d;
        temperature = t;
        windspeed = w;
        humidity = h;
    }
};

float Weather::getWindChill()
{
    return 13.12 + 0.6215 * temperature + (0.3965 * temperature - 11.37) * pow(windspeed, 0.16);
}


void Weather::print()
{
    cout << "\nDescription: "<< description << "\nTemperature: " << temperature << 
          "\nWind Speed: " << windspeed << "\nHumidity: " << humidity << endl;
    if (temperature < 10.0)
    {
        cout << "Feels like " << getWindChill() << endl;
    }
}

int main()
{
    Weather wuppertal("Wuppertal, Germany", -10.0, 15.0, 20);
    Weather berlin("Berlin, Germany", 0.0, 6, 10);
    Weather quito("Quito, Ecuador", 40.0, 5.0, 70);
    
    berlin.print();
    quito.print();
    quito.getWindChill();
    wuppertal.print();
}