#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<sstream>
using namespace std;

class Date{
private:
    int day;
    int month;
    int year;
    bool valid;
    static inline const int daysPerMonth[]{ 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    static const int stdYear{1970};
    static bool isLeapYear(int year)
        { return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0; }
    bool check_validity();
public:
    Date(int d, int m, int y);
    bool isValid() const { return valid; };
    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }
};

bool Date::check_validity(){
    if (year < 1 || month < 1 || month > 12 || day < 1
        || (day > daysPerMonth[month - 1]
        && !(day == 29 && month == 2 && isLeapYear(year))))
    {
        return false;
    }
    return true;
}

Date::Date(int d, int m, int y){
    year = y;
    month = m;
    day = d;
    valid = check_validity();
}

int main(int argc, char* argv[]){
    // Check if correct number of arguments provided
    if(argc != 3){
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }
    
    // Open input file
    ifstream inputFile(argv[1]);
    if(!inputFile){
        cerr << "Error: Could not open input file " << argv[1] << endl;
        return 1;
    }
    
    // Open output file
    ofstream outputFile(argv[2]);
    if(!outputFile){
        cerr << "Error: Could not open output file " << argv[2] << endl;
        inputFile.close();
        return 1;
    }
    
    int totalDates = 0;
    int invalidDates = 0;
    string line;
    
    // Process each line from input file
    while(getline(inputFile, line)){
        int day, month, year;
        char dot1, dot2;
        
        // Parse the date format DD.MM.YYYY
        stringstream ss(line);
        ss >> day >> dot1 >> month >> dot2 >> year;
        
        // Create Date object
        Date date(day, month, year);
        totalDates++;
        
        // Write to output file with status
        outputFile << line;
        if(date.isValid()){
            outputFile << " ok" << endl;
        } else {
            outputFile << " invalid date" << endl;
            invalidDates++;
        }
    }
    
    // Close files
    inputFile.close();
    outputFile.close();
    
    // Print summary to screen
    cout << "Total dates copied: " << totalDates << endl;
    cout << "Invalid dates: " << invalidDates << endl;
    
    return 0;
}