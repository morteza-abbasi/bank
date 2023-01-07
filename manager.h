#ifndef MANAGER_H
#define MANAGER_H
#include<iostream>
#include"emploee.h"
using namespace std;

class Manager:public Emploee
{
public:
    Manager();
protected:

public:

    string find_emploee_with_pcod(int );
    void creat_new_emploee();
    bool check_pesonal_cod(int p);
    bool check_username(string user);
    //void  load_file_information_manager(string data);
    //friend class Bank;
};

#endif // MANAGER_H
