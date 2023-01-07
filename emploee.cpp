#include "emploee.h"
#include<ctime>
#define Deduction_salaries 100000
#define overtime_salaries 120000
Emploee::Emploee()
{

}

Emploee::Emploee(string n,string l_n,int p_cod,Date d,double bs,string u,string p,int v, int o)
{
    name=n;
    last_name=l_n;
    Personnel_Code=p_cod;
    birth_day=d;
    basic_salary=bs;
    username=u;
    password=p;
    Vacation_hours=v;
    Overtime=o;
}
string Emploee::get_name()
{
    return name;
}

string Emploee::get_last_name()
{
    return last_name;
}

int Emploee::get_Personnel_Code()
{
    return Personnel_Code;
}

Date Emploee::get_birth_day()
{
    return birth_day;
}

double Emploee::get_basic_salary()
{
    return basic_salary;
}

string Emploee::Emploee::get_username()
{
    return username;
}

string Emploee::get_password()
{
    return password;
}

int Emploee::get_Vacation_hours()
{
    return Vacation_hours;
}

int Emploee::get_Overtime_hours()
{
    return Overtime;
}

string Emploee::Record_leave(int Leave)
{

    Vacation_hours+=Leave;
    string date,Time;

    time_t T=time(0);
    tm *ltm = localtime(&T);
    date=to_string(1900 + ltm->tm_year)+"/"+to_string(1 + ltm->tm_mon)
            +"/"+to_string(ltm->tm_mday);

    Time=to_string(ltm->tm_hour)+":"+to_string(ltm->tm_min)+":"+to_string(ltm->tm_sec);
    string end="name: "+name+"\n"+"last name: "+last_name+"\n"+"personal cod:"+to_string(Personnel_Code)+"\n"+
            "Date: "+date+"\nTime: "+Time+"\nHour leave: "+to_string(Leave);
    this->Leave.push_back(end);
    return end;

}

string Emploee::operetion_salary_leave()
{
    double Amount;
    if(Vacation_hours>15)
    {
        Amount=(Vacation_hours-15)*Deduction_salaries;
        basic_salary-=Amount;
        return "هشدار: بیش از این مرخصی از حقوق شما کسر میشود"
                "\n"
                "حقوق کسر شده: "+to_string(Amount);
    }
    return "";
}

string Emploee::Record_overtime(int time_over)
{
    Overtime+=time_over;
    string date,Time;

    time_t T=time(0);
    tm *ltm = localtime(&T);
    date=to_string(1900 + ltm->tm_year)+"/"+to_string(1 + ltm->tm_mon)
            +"/"+to_string(ltm->tm_mday);

    Time=to_string(ltm->tm_hour)+":"+to_string(ltm->tm_min)+":"+to_string(ltm->tm_sec);
    string end="name: "+name+"\n"+"last name: "+last_name+"\n"+"personal cod:"+to_string(Personnel_Code)+"\n"+
                "Date: "+date+"\nTime: "+Time+"\nHour Overtime: "+to_string(time_over);
    this->Over.push_back(end);
    return end;

}

string Emploee::operetion_salary_overtime()
{

    double Amount=0;

    if(Overtime>=0&&Overtime<13)
    {
        Amount=Overtime*overtime_salaries;
        basic_salary+=Amount;
        return "حقوق اضافه کار: "+to_string(Amount);

    }
    else
        if(Overtime>=12)
        {
            return "هشدار: بیشه از اضافه کار ثبت نمی شود\n"
                    "حقوق اضافه کار: "+to_string(Amount);
        }
    return "";

}

bool Emploee::check_pesonal_cod(int p)
{

        if(p==Personnel_Code)
            return 0;
    return 1;

}

bool Emploee::check_username(string user)
{
        if(user==username)
            return 0;
    return 1;
}


Emploee Emploee:: load_file_information_emploee(string data)
{

    int ind1,ind2;
    ind1=data.find("name:");
    data=data.substr(ind1+5);
    ind2=data.find("last_name:");
    name=data.substr(0,ind2-1);
    data=data.substr(ind2);
    ind1=data.find("personal_cod:");
    ind2=data.find("birth_day:");
    last_name=data.substr(10,ind1-11);
    data=data.substr(ind1);
    Personnel_Code=stoi(data.substr(13,ind2-13));
    data=data.substr(ind2-ind1);
    ind1=data.find("username:");

    birth_day=data.substr(10,ind1-10);
    data=data.substr(ind1);
     ind2=data.find("password:");
    username=data.substr(9,ind2-10);
    data=data.substr(ind2);
    ind2=data.find("vacation_hours:");
    password=data.substr(9,ind2-10);
    ind1=data.find("overtime_hours:");
    Vacation_hours=stoi(data.substr(ind2+15,ind1));
    data=data.substr(ind1);
    Overtime=stoi(data.substr(15,data.size()-15));

    return *this;
}
