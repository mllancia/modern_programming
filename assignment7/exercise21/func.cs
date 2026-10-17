// author:  Holger Arndt
// version: 25.11.2025
// functions in C# (mono)
// needed for sheet 7, exercise 21

using static System.Math;

public class Functions
{
    public static double f(double x, double y)
    {
        return Sqrt(x * x + y * y);
    }

    public static double g(double x)
    {
        return 1 / (x * x);
    }
}
