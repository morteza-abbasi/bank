#include "customer.h"
#include"account.h"
#include"date.h"

string Customer::get_name()
{
    return name;
}

string Customer::get_last_name()
{
    return last_name;
}

string Customer::get_natioal_cod()
{
    return national_cod;
}

Date Customer::get_birth_day()
{
    return birth_day;
}

string Customer::get_username()
{
    return username;
}

string Customer::get_password()
{
    return password;
}

vector<class Account> Customer:: get_Accounts()
{
    return Accounts;
}
string Customer::print_customer()
{
    string data= "name: "+name+"\nlast name: "+last_name+
            "\nnational cood: "+national_cod+
            "\nbirth day: "+birth_day.print()+
            "\nusername: "+username+
            "\npassword: "+password;
    for(int i=0;i<Accounts.size();i++)
    {
        data+="\n account "+to_string(i+1)+" : "+Accounts.at(i).print();
    }

    return  data;
}

bool Customer::check_num_account(string num_acount)
{
    for(int i=0;i<Accounts.size();i++)
    {

        if(this->Accounts.at(i).get_num_account()==num_acount)
            return 0;
    }

    return 1;
}

bool Customer::check_national_cod(string n)
{

        if(n==national_cod)
            return 0;
    return 1;

}

bool Customer::check_username(string user)
{
        if(user==username)
            return 0;
    return 1;
}


Customer Customer:: load_file_information_customer(string data)
{

    int ind1,ind2;
    string account;
    ind1=data.find("name:");
    data=data.substr(ind1+5);
    ind2=data.find("last_name:");
    name=data.substr(0,ind2-1);
    data=data.substr(ind2);
    ind1=data.find("national_cod:");

    last_name=data.substr(10,ind1-11);
    data=data.substr(ind1);
    ind2=data.find("birth_day:");
    national_cod=data.substr(13,ind2-14);
    data=data.substr(ind2);
    ind1=data.find("username:");

    birth_day=data.substr(10,ind1-11);
    data=data.substr(ind1);
     ind2=data.find("password:");
    username=data.substr(9,ind2-10);
    data=data.substr(ind2);
    ind2=data.find("account");
    password=data.substr(9,ind2-10);
    account=data.substr(ind2);



    int end;
    Account Acount;
    while (account.size()>0)
    {
        ind2=account.find("opening_date:");
        Acount.set_num_account(account.substr(9,ind2-10));
        account=account.substr(ind2);
        ind1=account.find("balans:");
        ind2=account.find("condition:");
        int ind=account.find("Time:");
        Acount.set_opening_date(Date(account.substr(13,ind1-2)));
        Acount.set_time(account.substr(ind+5,ind1-ind-6));
        Acount.set_balanc(stod(account.substr(ind1+7,ind2-2)));
        account=account.substr(ind2);

        end=account.find("account");
        if(end==-1)
        {
            string condition;
            condition=account.substr(10,account.size()-11);
            if(condition=="active")
                Acount.set_condition(1);
            else
               Acount.set_condition(0);
            Acount.set_n_cod_owner_acount(national_cod);
            Accounts.push_back(Acount);

            break;
        }
        else
        {
            ind1=account.find("account");
            string condition;
            condition=account.substr(10,ind1-11);
            if(condition=="active")
                Acount.set_condition(1);
            else
                Acount.set_condition(0);
            Acount.set_n_cod_owner_acount(national_cod);
            Accounts.push_back(Acount);
            account=account.substr(ind1);
            continue;
        }

    }//end while
    return  *this;

}
