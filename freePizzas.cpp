#include <iostream>
using namespace std;

int main()
{
    string freePizzas[2] = {"pizza1", "pizza2"};

    string *pFreePizzas = freePizzas;

    cout << pFreePizzas[1] << endl;

}