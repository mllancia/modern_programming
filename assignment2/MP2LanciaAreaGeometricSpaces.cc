#include <iostream>
#include <cmath>

using namespace std;

// The program repeatedly shows a menu of possible actions
// The program then reads in some necessary parameters, computes 
// the area, and prints the result

void rectangle()
{
    double length;
    double width;
    cout << "What's the length of the rectangle?";
    cin >> length;
    cout << "\nThe width?";
    cin >> width;
    double area = length * width;
    cout << "\nArea: " << area << "\n";
}

void ellipse()
{
    double a;
    double b;
    cout << "What's the first half axe of the ellipse?";
    cin >> a;
    cout << "\nThe other?";
    cin >> b;
    double area = M_PI * a * b; // value of PI
    cout << "\nArea: " << area << "\n";
}

void triangle()
{
    double side1;
    double side2;
    double side3;
    cout << "What's is the first side length of the triangle?";
    cin >> side1;
    cout << "\nThe next?";
    cin >> side2;
    cout << "\nThe last?";
    cin >> side3;
    double s = (side1 + side2 + side3) / 2.0;
    double area = sqrt(s*(s-side1) * (s-side2) * (s-side3));

    cout << "\nArea: " << area << "\n";
}

int main()
{
    // exercise 5
    // computation of different areas.
    // The program repeatedly shows a menu of possible actions (cf. example). 
    // The user chooses an item by entering one character. 
    // The program then reads in some necessary parameters, computes the area, 
    // and prints the result.
    bool running = true;

    while (running == true)
    {
        string in;
        cout << "(r) rectangle\n";
        cout << "parameters: side lengths 𝑎 and 𝑏 area: 𝑎 · 𝑏\n";
        cout << "(e) ellipse\n";
        cout << "parameters: half axes 𝑎 and 𝑏 area: 𝜋 · 𝑎 · 𝑏\n";
        cout << "(t) triangle\n";
        cout << "parameters: side lengths 𝑎, 𝑏, and 𝑐\n";
        cout << "area: √𝑠(𝑠 − 𝑎)(𝑠 − 𝑏)(𝑠 − 𝑐) with 𝑠 = 𝑎+𝑏+𝑐 (Heron’s formula) 2\n";
        cout << "(x) exittheprogram\n";
        cin >> in;

        if (in == "r")
        {
            rectangle();
        }
        else if (in == "e")
        {
            ellipse();
        }
        else if (in == "t")
        {
            triangle();
        }
        else if (in == "x")
        {
            cout << "Exitting Program...";
            break;
        } 
        else 
        {
            cout << "Error. Try Again.";
        }
    }
}
