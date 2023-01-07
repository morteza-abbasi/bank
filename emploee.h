#ifndef EMPLOEE_H
#define EMPLOEE_H
#include<iostream>
#include"date.h"
#include<vector>

using namespace std;

class Emploee
{
public:
    Emploee();
    Emploee(string n,string l_n,int,Date d,double bs,string u,string p,int v, int o);
private:
    string name;
    string last_name;
    int Personnel_Code;
    Date birth_day;
    double basic_salary;
    string username;
    string password;
    int Vacation_hours=0;
    int Overtime=0;
    vector<string> Leave;
    vector<string> Over;


public:
    string get_name();
    string get_last_name();
    int get_Personnel_Code();
    Date get_birth_day();
    double get_basic_salary();
    string get_username();
    string get_password();
    int get_Vacation_hours();
    int get_Overtime_hours();

    string Record_leave(int);
    string operetion_salary_leave();
    string Record_overtime(int);
    string operetion_salary_overtime();
    bool check_pesonal_cod(int p);
    bool check_username(string user);
    Emploee load_file_information_emploee(string data);
    string print();
    friend class leave_hours;
    friend class overtime_hour;
    friend class inf_emp_for_manag;

};

#endif // EMPLOEE_H
