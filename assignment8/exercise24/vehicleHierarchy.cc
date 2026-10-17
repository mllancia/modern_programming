// Exercise 24 Hierarchy for Vehicles
// author:  Frederick Lancia
// version: 13.12.2025
// sheet 8, exercise 24

#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// Vehicle 
// year of manufacture, number of seats

// class named with capital letter
class Vehicle
{
protected:
    // protected are like private but allow for editting in child class
    // define attributes
    int manufactureYear;
    int numberOfSeats;
public:
    // define methods
    // constructor  so that these parementers can be initialized by
    // constructors of child classes
    Vehicle(int my, int ns): manufactureYear(my) , numberOfSeats(ns) {}
    friend ostream& operator<<(ostream& os, const Vehicle& v);
};

// Outside the class:
ostream& operator<<(ostream& os, const Vehicle& v) {
    os << "Manufactured: " << v.manufactureYear << ", Seats: " << v.numberOfSeats;
    return os;
}


// train 
// year of manufacture, number of seats, number of coaches, track gauge

class Train: public Vehicle {
private:
    int numberOfCoaches;
    double trackGauge; 
public:
    Train(int my, int ns, int nc, double tg)
        : Vehicle(my, ns), numberOfCoaches(nc), trackGauge(tg){}
    friend ostream& operator<<(ostream& os, const Train& t);
};

ostream& operator<<(ostream& os, const Train& t)
{
    // Call base class operator
    os << static_cast<const Vehicle&>(t);
    os << ", Coaches: " << t.numberOfCoaches 
       << ", Track Gauge: " << t.trackGauge << "mm";
    return os;
}

// Motor Vehicle
// year of manufacture, license plate number, number of seats, engine power

class MotorVehicle: public Vehicle {
protected:
    string licensePlateNumber;
    double enginePower;
public:
    MotorVehicle(int my, int ns, string lpn, double ep)
            : Vehicle(my, ns), licensePlateNumber(lpn), enginePower(ep) {}
    
    friend ostream& operator<<(ostream& os, const MotorVehicle& mv);
};

ostream& operator<<(ostream& os, const MotorVehicle& mv) {
    os << static_cast<const Vehicle&>(mv);
    os << ", License: " << mv.licensePlateNumber 
       << ", Engine Power: " << mv.enginePower << "kW";
    return os;
}

// car
// year of manufacture, licence plate number, number of seats, engine power, kind of usage - private, company car, taxi

enum class KindOfUsage {
    PRIVATE,
    COMPANYCAR,
    TAXI
};

// Helper function to convert enum to string
string usageToString(KindOfUsage usage) {
    switch(usage) {
        case KindOfUsage::PRIVATE: return "Private";
        case KindOfUsage::COMPANYCAR: return "Company Car";
        case KindOfUsage::TAXI: return "Taxi";
        default: return "Unknown";
    }
}

class Car: public MotorVehicle {
private:
    KindOfUsage usage;
public:
    Car(int my, int ns, string lpn, double ep, KindOfUsage u)
        : MotorVehicle(my, ns, lpn, ep), usage(u){}

           friend ostream& operator<<(ostream& os, const Car& c);
};

ostream& operator<<(ostream& os, const Car& c) {
    os << static_cast<const MotorVehicle&>(c);
    os << ", Usage: " << usageToString(c.usage);
    return os;
}

// bus
// year of manufacture, licence plate number, number of seats, maximum number of standing room passengers, engine power

class Bus: public MotorVehicle {
private:
    int numberOfStandingRoomPassengers;
public:
    Bus(int my, int ns, string lpn, double ep, int nsrp)
        : MotorVehicle(my, ns, lpn, ep), numberOfStandingRoomPassengers(nsrp){}
    friend ostream& operator<<(ostream& os, const Bus& b);
};

ostream& operator<<(ostream& os, const Bus& b) {
    os << static_cast<const MotorVehicle&>(b);
    os << ", Standing Room: " << b.numberOfStandingRoomPassengers << " passengers";
    return os;
}

int main()
{
  Car audiR8 = Car(1999, 20, "58GH25", 50.0, KindOfUsage::TAXI);
    cout << "Car: " << audiR8 << endl;
    
    Bus cityBus(2015, 40, "BUS123", 250.0, 30);
    cout << "Bus: " << cityBus << endl;
    
    Train expressTrain(2020, 300, 8, 1435.0);
    cout << "Train: " << expressTrain << endl;
}