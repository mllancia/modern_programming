// author:  Holger Arndt
// version: 25.11.2025
// main program in C# (mono)
// needed for sheet 7, exercise 21

using System;
using static System.Console;

class MainProgram
{
    static void Main()
    {
        double x, y;

        Write("x = ");
        x = Double.Parse(ReadLine());
        Write("y = ");
        y = Double.Parse(ReadLine());
        WriteLine("f(x, y) = " + Functions.f(x, y));
        WriteLine("g(x)    = " + Functions.g(x));
    }
}
