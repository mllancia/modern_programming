#include <iostream>

using namespace std;

class Book
{
private:
    string title;
    string author;
    string borrower;
public:
    void borrowed(string b);
    void returned();
    void print();

    // constructor
    Book(string t, string a)
    {
        title = t;
        author = a;
        borrower = "";
    }
};

void Book::borrowed(string b)
{
    // ask if it is already borrowed
    // if so, return error message
    // if not, set new borrower
    if (borrower == "")
    {
        borrower = b;
    }   
    else
    {
        cout << "\nError: Book already borrowed." << endl;
    }
}

void Book::returned()
{
    // ask if it is already borrowed
    // if so, remove borrower
    // if not, return error message
    if (borrower == "")
    {
        cout << "\nError: Book is not yet borrowed." << endl;
    }   
    else
    {
        borrower = "";
    }
}



void Book::print()
{
    cout << "\nTitle: "<< title << "\nAuthor: " << author << "\nBorrower:: " << 
      borrower << endl;
}

int main()
{
    Book hp("Harry Potter", "JK");
    hp.print();
    Book pp("Peter Pan", "JM");
    pp.print();
    pp.borrowed("Fred");
    pp.print();
    pp.borrowed("Welli");
    pp.returned();
    pp.print();
    pp.returned();
}