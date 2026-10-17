#include <iostream>
#include <cmath>

using namespace std;

class Complex{
private:
    double re;
    double im;
    Complex inverse() const;
public:
    Complex(double rei = 0.0, double imi = 0.0){
        re = rei;
        im = imi;
    }

    double real() const;
    double imag() const;

    double abs() const;

    friend Complex operator+(const Complex& co1, const Complex& co2);
    friend Complex operator-(const Complex& co1, const Complex& co2);
    friend Complex operator*(const Complex& co1, const Complex& co2);
    friend Complex operator/(const Complex& co1, const Complex& co2);

    friend bool operator==(const Complex& co1, const Complex& co2);
    friend bool operator!=(const Complex& co1, const Complex& co2);

    friend Complex& operator+=(Complex& co1, const Complex& co2);
    friend Complex& operator-=(Complex& co1, const Complex& co2);
    friend Complex& operator/=(Complex& co1, const Complex& co2);
    friend Complex& operator*=(Complex& co1, const Complex& co2);

    friend ostream& operator<<(ostream& os, const Complex& C);
};

double Complex::real() const{
    return re;
}

double Complex::imag() const{
    return im;
}

double Complex::abs() const{
    return sqrt(pow(re,2) + pow(im,2));
}

Complex operator+(const Complex& co1, const Complex& co2){
    return Complex(co1.re + co2.re, co1.im + co2.im);
}

Complex operator-(const Complex& co1, const Complex& co2){
    return Complex(co1.re - co2.re, co1.im - co2.im);
}

Complex operator*(const Complex& co1, const Complex& co2){
    return Complex((co1.re * co2.re) - (co1.im * co2.im), (co1.re * co2.im) + (co1.im*co2.re));
}

Complex Complex::inverse() const{
    return Complex(re/(pow(re,2) + pow(im,2)),-im/(pow(re,2) + pow(im,2)) );
}

Complex operator/(const Complex& co1, const Complex& co2){
    return co1 * co2.inverse();
}

bool operator==(const Complex& co1, const Complex& co2){
    return ((co1.re == co2.re) && (co1.im == co2.im));
}

bool operator!=(const Complex& co1, const Complex& co2){
    return ((co1.re != co2.re) || (co1.im != co2.im));
}

Complex& operator+=(Complex& co1, const Complex& co2){
    co1.re += co2.re;
    co1.im += co2.im;
    return co1;
}

Complex& operator-=(Complex& co1, const Complex& co2){
    co1.re -= co2.re;
    co1.im -= co2.im;
    return co1;
}

Complex& operator*=(Complex& co1, const Complex& co2){
    co1 = co1 * co2;
    return co1;
}

Complex& operator/=(Complex& co1, const Complex& co2){
    co1 = co1 / co2;
    return co1;
}

ostream& operator<<(ostream& os, const Complex& co){
    os << co.re;
    if (co.im >= 0)
        os << "+" << co.im << "i";
    else
        os << co.im << "i";
    return os;
}

int main() {
    Complex c1(1.0, 2.0);
    Complex c2(1.0, 2.0);
    Complex c3(2.0, 1.0);
    Complex c4(1.5, 2.5);
    Complex c5(1.0, 3.0);

    cout << "co 1: " << c1 << endl;
    cout << "co 2: " << c2 << endl;
    cout << "co 3: " << c3 << endl;
    cout << "co 4: " << c4 << endl;


    cout << "Does co 1 == co 2? " << (c1 == c2 ? "True" : "False") << endl;
    cout << "Does co 1 == co 4? " << (c1 == c4 ? "True" : "False") << endl;
    cout << "Does co 1 != co 2? " << (c1 != c2 ? "True" : "False") << endl;

    cout << "Co 1 + Co 2: " << (c1 + c2) << endl;
    cout << "Co - Co 3: " << (c1 - c2) << endl;
    cout << "Co 1 * Co 2: " << (c1 * c2) << endl;
    cout << "Co 1 / Co 2: " << (c1 / c2) << endl;

    Complex c11(1.0, 2.0);
    Complex c31(2.0, 1.0);
    Complex c12(1.0, 2.0);
    Complex c32(2.0, 1.0);
    Complex c13(1.0, 2.0);
    Complex c33(2.0, 1.0);
    Complex c14(1.0, 2.0);
    Complex c34(2.0, 1.0);

    cout << "Co 1 += Co 3: "  << (c11 += c31) << endl;
    cout << "Co 1 -= Co 3: " << (c12 -= c32) << endl;
    cout << "Co 1 *= Co 3: " << (c13 *= c33) << endl;
    cout << "Co 1 /= Co 3: " << (c14 /= c34) << endl;

    cout << "Absolute value Co 1: " << c1.abs() << endl;
    cout << "Absolute value Co 3: " << c3.abs() << endl;
    cout << "The real part Co 1: " << c1.real() << endl;
    cout << "The real part Co 3: " << c3.real() << endl;
    cout << "The Imaginary part Co 1: " << c1.imag() << endl;
    cout << "The Imaginary part Co 3: " << c3.imag() << endl;
    return 0;
}