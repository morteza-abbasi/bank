#include "bank.h"
#include<string>
#include<fstream>

//Bank::Bank()
//{

//}


bool Bank::check_all_username(string user)
{

    for(int i=0;i<Emploes.size();i++)
    {
        if(!Emploes.at(i).check_username(user))
            return 0;
    }
    for(int i=0;i<Customers.size();i++)
    {
        if(!Customers.at(i).check_username(user))
            return 0;
    }

        if(!Manag.check_username(user))
            return 0;

    return 1;
}

void Bank:: load_information_as_file(string address)
{

    string data , m_or_c;
    int ind;;
    ifstream file(address,ios::in);
    while(!file.eof())
    {

        getline(file,data);
        if(data=="") break;
        ind=data.find(":");
        m_or_c=data.substr(0,ind);
        if(m_or_c=="manager")
        {
            data=data.substr(ind+1);
            //load_file_information_manager(data,bank.Manag);
            Manag.load_file_information_emploee(data);
        }
        else
            if(m_or_c=="customer")
            {
                Customer c;
                data=data.substr(ind+1);
                Customers.push_back( c.load_file_information_customer(data));


            }
        else
                if(m_or_c=="emploee")
                {
                    Emploee e;
                    data=data.substr(ind+1);
                    Emploes.push_back(e.load_file_information_emploee(data));
                }

    }
}

vector<int> Bank::find_person(string u, string p)
//person[3] 2->manager  or emploee or customer 2 - 3 - 4
//1--> exist 1 else 0
//3--> index home
{
    vector<int> person;
    for(int i=0;i<Customers.size();i++)
    {
        if(Customers.at(i).get_username()==u&&Customers.at(i).get_password()==p)
        {
            person.push_back(1);
            person.push_back(4);
            person.push_back(i);
            return person;
        }

    }
    for(int i=0;i<Emploes.size();i++)
    {
        if(Emploes.at(i).get_username()==u&&Emploes.at(i).get_password()==p)
        {
            person.push_back(1);
            person.push_back(3);
            person.push_back(i);
            return person;
        }

    }

        if(Manag.get_username()==u&&Manag.get_password()==p)
        {
            person.push_back(1);
            person.push_back(2);
            person.push_back(-1);
            return person;


        }
        if(person.size()==0)
        {
            person.push_back(0);
            person.push_back(-1);
            person.push_back(-1);
        }

    return person;
}

