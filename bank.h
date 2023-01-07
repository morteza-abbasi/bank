#ifndef BANK_H
#define BANK_H

#include<iostream>
#include<vector>
#include"emploee.h"
#include"customer.h"
#include"manager.h"
#include"login.h"
#include"fstream"
using namespace std;

class Bank
{
public:
    //Bank();
protected:

    vector<Emploee> Emploes;
    vector<Customer> Customers;
    Manager Manag;

public:
    void load_information_as_file(string);
    vector<int> find_person(string u,string p);
    bool check_all_username(string );
    friend class login;
    friend class customer_page;
    friend class information_customer;
    friend class accounts_customer;
    friend class print_customer_with_ncod;
    friend class opening_account;
    friend class emploee_page;
    friend class leave_hours;
    friend class list_leave;
    friend class overtime_hour;
    friend class overtime_hour;
    friend class set_cond_by_emp;
    friend class delete_customer;
    friend class manager_page;
    friend class print_emp_with_pcod;
    friend class inf_emp_for_manag;
    friend class del_emp;
    friend class add_emp;
};
inline Bank bank;
inline ofstream report("C:/Users/red   pc/Desktop/report.txt",ios::out|ios::ate);


#endif // BANK_H
