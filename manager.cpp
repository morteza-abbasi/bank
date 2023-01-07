#include "manager.h"

Manager::Manager()
{

}

bool Manager::check_pesonal_cod(int p)
{

        if(p==get_Personnel_Code())
            return 0;
    return 1;

}

bool Manager::check_username(string user)
{
        if(user==get_username())
            return 0;
    return 1;
}


//void Manager:: load_file_information_manager(string data)
//{



//    int ind1,ind2;
//    ind1=data.find(':');
//    data=data.substr(ind1+1);
//    ind1=data.find("name:");
//    ind2=data.find("last_name:");
//    name=data.substr(ind1+5,ind2-1);
//    data=data.substr(ind2);
//    ind1=data.find("personal_cod:");
//    ind2=data.find("birth_day:");
//   last_name=data.substr(10,ind1-1);
//    data=data.substr(ind1);
//    Personnel_Code=stoi(data.substr(14,ind2-1));
//    data=data.substr(ind2);
//    ind1=data.find("username:");
//    ind2=data.find("password:");
//    birth_day=data.substr(10,ind1-1);
//    data=data.substr(ind1);
//    username=data.substr(9,ind2-1);
//    data=data.substr(ind2);
//    ind2=data.find("vacation_hours:");
//    password=data.substr(9,ind2-1);
//    ind1=data.find("overtime_hours:");
//    Vacation_hours=stoi(data.substr(ind2+15,ind1));
//    Overtime=stoi(data.substr(15,data.size()));

//}
