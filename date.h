#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
using namespace std;
class bad_date{};
class Date
{

public:
    Date(int d, int m, int y);
    Date();
    Date(string date);
    void set_date(int d, int m, int y);
    friend ostream& operator<<(ostream& out,Date& );
    int operator-(Date &);
    Date operator++(int);
    Date operator=(int);
    Date operator=(Date &);
    Date operator=(string);
    bool operator==(Date&);
    void equals(Date d);
    void day_of_week();
    int get_day() { return day; }
    int get_month() { return month; }
    int get_year() { return year; }
    int daynumber();
    int compare();
    string print();
private:
    int day;
    int month;
    int year;
};

#endif // DATE_H
