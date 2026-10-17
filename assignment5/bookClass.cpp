#include <iostream>

using namespace std;

class Book
{
private:


public:
    string title;
    string author;
    string borrower;

    void SetBook();
    void borrowed();
    void returned();
    void print();
}

void Book::setBook(string t, string a)
{
    title = t;
    author = a;
    borrower = "";
}

void Book::borrowed(string b)
{
    if (title & author ) // has the book been initialized?
    {
        print(borrower)
    }
    else
    {
        print("Error. Book has not been specified.")
    }

    borrower = "";
}

void Book::setBook(string t, string a)
{
    title = t;
    author = a;
    borrower = "";
}

void Book::setBook(string t, string a)
{
    title = t;
    author = a;
    borrower = "";
}