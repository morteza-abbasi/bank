#include "date.h"
#include"string"

Date::Date(int d, int m, int y)
{
    //constructor
    set_date(d, m, y);
}
Date::Date()
{
    //default constructor
    set_date(2, 2, 1390);
}

Date ::Date(string date)
{
    int ind;
    ind =date.find('/');
    year=stoi(date.substr(0,ind));
    date=date.substr(ind+1);
    ind=date.find('/');
    month=stoi(date.substr(0,ind));
    day=stoi(date.substr(ind+1,date.size()));
    set_date(day,month,year);
}


bool is_leap_year(int year)
{
    int r = year % 33;
    return r==1 || r==5 || r==9 || r==13 || r==17 || r==22 || r==26 || r==30;
}

int max_day_for_month(int m, int y)
{
    if (m < 7)
        return 31;
    else if (m < 12)
        return 30;
    else if (m == 12)
        return is_leap_year(y) ? 30 : 29;
    else
        throw bad_date();
}


Date Date::operator++(int)   ///operaror overloading  kardan  tabe inc_one_day (1)
{
    day++;
    if (day > max_day_for_month(month, year)) {
        day = 1;
        month++;
        if (month > 12) {
            month = 1;
            year++;
        }
    }
    return *this;
}
ostream& operator<<(ostream& out,Date &D)
{
    out<<D.day<<'/'<<D.month<<'/'<<D.year<<endl;

    return out;
}

int Date::operator-(Date &d)
{
    if(daynumber()>d.daynumber()) return (daynumber()-d.daynumber());
    else
        return( d.daynumber()-daynumber());



}
Date Date:: operator=(Date &s)
{
  day=s.day;
  month=s.month;
  year=s.year;
  return *this;
}

Date Date::operator=(string date)
{
    int ind;
    ind=date.find('/');
    year=stoi(date.substr(0,ind));
    date=date.substr(ind+1);
    ind=date.find('/');
    month=stoi(date.substr(0,ind));
    day=stoi(date.substr(ind+1,date.size()));
    return  *this;
}
bool Date::operator==(Date &d)
{
    if(year==d.year&&month==d.month&&day==d.day)
        return 1;
    return 0;
}

int Date :: daynumber()
 {
    int sum =0;
   int b=year;
   sum +=(b-1)*365 + b/4;
   if(month==12)
   {if(is_leap_year(b)) {sum+=31*6 +5*30 +30;}
    else sum+=31*6 +5*30 +29;
   }
   else
       if(month>6)
           sum+=6*31 +(month-7)*30+day;
   else
           if(month<7)
               sum+=(month-1)*31+day;




    return sum;
}
void Date::set_date(int d, int m, int y)
{
    if (y < 0 || m < 1 || m > 12 || d < 1 || d > max_day_for_month(m, y))
        throw bad_date();

    day = d;
    month = m;
    year = y;
}



void  Date::equals(Date d) {
    //moghaieseye 2 tarikh
    if(day == d.day && month == d.month && year == d.year)
         cout<<"0";
    else
    if( year < d.year)
            cout<<"-1";
    else
            if(month<d.month)
                cout<<"-1";
    else
                if(day<d.day)
                    cout<<"-1";

    else
    {cout<<"1";}
}



Date str_to_date(string s) {
    //TODO: Handle formatting errors
    int slash_pos = s.find('/');
    int d = stoi(s.substr(0, slash_pos));
    s = s.substr(slash_pos + 1);
    slash_pos = s.find('/');
    int m = stoi(s.substr(0, slash_pos));
    int y = stoi(s.substr(slash_pos + 1));

    return Date(d, m, y);
}


void Date::day_of_week()
{
    int o=(daynumber()-396)%7;
    switch (o)
    {
       case 0: cout<<"\nThurs.\n"; break;
       case 1: cout<<"\nFri.\n";   break;
       case 2: cout<<"\nSat.\n";   break;
       case 3: cout<<"\nSun.\n";   break;
       case 4: cout<<"\nMon.\n";   break;
       case 5: cout<<"\nTues.\n";  break;
       case 6: cout<<"\nWen.\n";
    }


}

string Date::print()
{
    string date;
    date=to_string(year)+'/'+to_string(month)+'/'+to_string(day);
    return date;
}
