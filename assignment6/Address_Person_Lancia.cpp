#include <iostream>
using namespace std;

// UML class diagram

class Address
{
private:
    string street;
    string housenumber;
    string postcode;
    string city;
    string country;

public:
    // constructor
    Address(string str = "", string house = "", string post = "", 
            string cty = "", string ctry = "") {
            street = str;
            housenumber = house;
            postcode = post;
            country = ctry;
            city = cty;
    }
        
    friend ostream& operator<<(ostream& os, const Address& addr)
    {
        os << addr.housenumber << " " << addr.street << "\n"
           << addr.postcode << " " << addr.city << "\n"
           << addr.country;
        return os;
    }
};

class Person
{
private:
    string givenname;
    string familyname;
    Address address;
public:
    void moveTo(Address address);

    // constructor
    Person(string g, string f, Address& A) : givenname(g), 
            familyname(f), address(A) {}

    friend ostream& operator<<(ostream& os, const Person& p)
    {
        os << p.givenname << " " << p.familyname << "\n"
           << "Address: " << p.address;
        return os;
    } 

};

void Person::moveTo(Address addr)
{
    address = addr;
}

int main() {
    Address home = Address("Geil Straße", "99", "55555", "Köln", "Deutschland");

    Address home_2 = Address("Über Straße", "10000", "33333", "Wolkendörf", "Die Himmel");

    Person me = Person("Fred", "L.", home);

    cout << me << endl;

    me.moveTo(home_2);

    cout << me;

    return 0;
}