#include "Headers/account.h"
class error{};

void Account::charge_account(double money)
{
        Balance+=money;
}

void Account::Withdraw_from_account(double money)
{
    if(Condition)
        Balance-=money;
    else
        throw error();
}

string  Account::print()
{
    string data;

    data="number account :"+number_account+
            "\nnatioanl cod owner account: "+n_cod_owner_account+
            "\nopening date: "+Opening_date.print()+
            "\nTime open account: "+Time+
            "\nBalance: "+to_string(Balance);
    if(Condition)
        data+="\nCondition: active";
    else
        data+="\nCondition: Inactive";

    return data;
}

string Account::get_num_account()
{
    return number_account;
}

string Account::get_n_cod_owner_acount()
{
    return n_cod_owner_account;
}

Date Account::get_opening_date()
{
    return Opening_date;
}

double Account::get_balanc()
{
    return Balance;
}

bool Account::get_condition()
{
 return Condition;
}

void Account::set_num_account(string na)
{
    number_account=na;
}

void Account::set_n_cod_owner_acount(string ncoa)
{
    n_cod_owner_account=ncoa;
}

void Account::set_opening_date(Date d)
{
    Opening_date=d;
}

void Account::set_balanc(double b)
{
    Balance=b;
}

void Account::set_condition(bool c)
{
    this->Condition=c;;
}

void Account::set_time(string t)
{
    Time=t;
}
