#include <iostream>

using namespace std;

class Car
{
private:
    string type;
    double mileage;
public:
    void drive(double distance);
    void tow(Car& towed, double distance);
    string getType();
    double getMileage();
    void print();

    // constructor
    Car(string t = "unknown", double m = 0.0)
    {
        type = t;
        mileage = m;
    }
};

void Car::drive(double d)
{
    mileage = mileage + d;
}

void Car::tow(Car& c, double d)
{
    drive(d);
    c.drive(d);
}

string Car::getType()
{
    return type;
}

double Car::getMileage()
{
    return mileage;
}

void Car::print()
{
    cout << "\nType: "<< type << "\nMileage: " << mileage << endl;
}

int main()
{
    Car lambo("Lamborghini", 50.0);
    Car ghost;

    lambo.print();
    ghost.print();

    lambo.drive(35.0);

    lambo.tow(ghost, 20.0);

    cout << "\nLambo should now have 50+20+35 = 105 miles on it." << endl;

    lambo.print();
    ghost.print();

    cout << "\nGet type: "<< lambo.getType() << 
      "\nGet Mileage: " << lambo.getMileage() << endl;
}