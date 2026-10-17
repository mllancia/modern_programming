#include <iostream>

using namespace std;

class Song
{
public:
    string title;
    string artist;
    int releaseYear;
    string recordLabel;
    void print();
    
    Song(string t, string a, int ry, string rl) {
        title = t;
        artist = a;
        releaseYear = ry;
        recordLabel = rl;
    }
};

void Song::print()
{
    cout << "\nTitle: "<< title << "\nArtist: " << artist << "\nRelease Year: " << 
    releaseYear << "\nRecord Label: " << recordLabel << endl;
}


int main()
{
    Song s1("Best Song Ever", "Hypeman", 2050, "BofB");
    s1.print();
    Song s2("Worst Song Ever", "Hypeman", 2010, "BofB");
    s2.print();
}