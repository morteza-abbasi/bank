#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<vector>
#include"date.h"
#include"account.h"
#include"information_customer.h"
using namespace std;

class Customer
{
public:
   // Customer();
private:

    string name;
    string last_name;
    string national_cod;
    Date birth_day;
    string username;
    string password;
    vector<class Account> Accounts;
public:
    string get_name();
    string get_last_name();
    string get_natioal_cod();
    Date get_birth_day();
    string get_username();
    string get_password();
    string print_customer();
    vector<class Account> get_Accounts();
    bool check_num_account(string num_acount);
    bool check_national_cod(string n);
    bool check_username(string user);
    Customer load_file_information_customer(string data);
    friend class accounts_customer;
    friend class opening_account;
    friend class set_cond_by_emp;
    friend class delete_customer;
};

#endif // CUSTOMER_H
