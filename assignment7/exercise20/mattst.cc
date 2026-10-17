// class matrix, test program
// author:  Holger Arndt
// version: 17.12.2019

#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
  Matrix m1;
  cout << "m1: " << m1;

  Matrix m2{3, 2};
  cout << "m2: " << m2;

  Matrix m3{3};
  cout << "m3: " << m3;

  Matrix m4{3, 3, 127};
  cout << "m4: " << m4;

  Matrix m5{m4};
  cout << "m5: " << m5;

  m5(0, 2) = 123;
  cout << "m5: " << m5;

  cout << "m2.numrows: " << m2.numrows() << endl;
  cout << "m2.numcols: " << m2.numcols() << endl;
  cout << "m2.numelems: " << m2.numelems() << endl;

  m2 = m5;
  cout << "m2: " << m2;

  double m6arr[]{ 1, 2, 3, 4 };
  Matrix m6{2, 2, m6arr};
  cout << "m6: " << m6;

  cout << "trace m6: " << trace(m6) << endl;

  m6 *= m6;
  cout << "m6 * m6: " << m6;

  cout << "trace m6: " << trace(m6) << endl;

   m6 *= 5;
  cout << "5 * m6: " << m6;

  m5 = 99;
  cout << "m5: " << m5;

  m6.setall(4, 5.0, 6.0, 7.0, 8.0);  // NOT setall(4, 5, 6, 7, 8) !!
  cout << "m6: " << m6;

  m3 = 1;
  cout << "m3 + m5: " << m3 + m5;

  cout << "m3 - m5: " << m3 - m5;

  cout << "2 * m5: " << 2 * m5;
  m4 = 2 * m5;
  cout << "m4 = 2 * m5: " << m4;

  cout << "m3 * m2: " << m3 * m2;

  cout << "m3 == m5: " << (m3 == m5 ? "yes" : "no") << endl;
  m3 = m5;
  cout << "m3 == m5: " << (m3 == m5 ? "yes" : "no") << endl;

  cout << "identity matrix size 4: " << m1.identity(4);

  cout << "trace m3: " << m1.identity(4);

#ifdef DEBUG
  // this last line should give an error message in the debug version
  m3(1, 6) = 9;
#endif
}
