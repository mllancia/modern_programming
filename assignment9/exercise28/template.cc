// template.cc

template<typename T>  
T cubed(T x)
{
    if (x * x)
    {
        return x * x * x;
    }
    else
    {
        return x + x + x;
    }
}


int T

double T

complex<double>

string

main()
{
    int ix = 2;

    double dx = 2.2;

    complex<double> cx = 5.5 + 2.5i;

    string sx = "9";

    cout << cubed(ix) << endl;

    cout << cubed(dx) << endl;

    cout << cubed(cx) << endl;

    cout << cubed(sx) << endl;
}