#ifndef ACCOUNT_H
#define ACCOUNT_H
#include<iostream>
#include"date.h"
using namespace std;

class Account
{
public:
  //  Account();

private:
    string number_account;
    string n_cod_owner_account;
    Date Opening_date;
    string Time;
    double Balance;
    bool Condition;


public:
    void charge_account(double);
    void Withdraw_from_account(double);
    string print();
    string get_num_account();
    string get_n_cod_owner_acount();
    Date get_opening_date();
    double get_balanc();
    bool get_condition();
     void set_num_account(string);
     void set_n_cod_owner_acount(string);
     void set_opening_date(Date);
     void set_balanc(double);
     void set_condition(bool);
     void set_time(string);
    //friend void load_file_information_customer(string,vector<Customer>&);
//    friend class Emploee;
    //friend class Customer;
};

#endif // ACCOUNT_H
