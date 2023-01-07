#include "opening_account.h"
#include "ui_opening_account.h"
#include "customer.h"
#include "account.h"
#include "bank.h"
#include "emploee_page.h"
#include "manager_page.h"
#include<iostream>
#include<stdlib.h>
#include<ctime>
#include<fstream>
using namespace std;
extern vector<int> exist;
opening_account::opening_account(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::opening_account)
{

    ui->setupUi(this);
    ui->accept->hide();
}

opening_account::~opening_account()
{
    delete ui;
}

void opening_account::on_chose_number_account_clicked()
{

    long long int max = 9999999999999999;
    long long int min = 1000000000000000;
    srand(time(0));
    bool flag=1;
    long long int number_account;
    while(1)
    {
        number_account=rand()%(max - min) + min ;

        for(int i=0;i<bank.Customers.size();i++)
        {
            for(int j=0;j<bank.Customers.at(i).Accounts.size();j++)
                if(bank.Customers.at(i).Accounts.at(j).get_num_account()==to_string(number_account))
                    flag=0;
        }
        if(flag)
        {
            string num_account=to_string(number_account);
            QString Num_Account=QString::fromStdString(num_account);
            ui->number_account->setText(Num_Account);
            break;
        }
    }



}

void opening_account::on_creat_account_clicked()
{
    bool flag=1;
    if(ui->name->text()==NULL)
    {
        ui->lbl_war_inf->setText("اسم را وارد کنید");
        flag=0;
    }
    else
        if(ui->last_name->text()==NULL)
        {
            ui->lbl_war_inf->setText("فامیل را وارد کنید");
            flag=0;
        }
        else
            if(ui->n_cod->text()==NULL)
            {
                ui->lbl_war_inf->setText("کد ملی را وارد کنید");
                flag=0;
            }
            else
                if(ui->birth_day->text()==NULL)
                {
                    ui->lbl_war_inf->setText("تاریخ تولد را وارد کنید");
                    flag=0;
                }
                else
                    if(ui->username->text()==NULL)
                    {
                        ui->lbl_war_inf->setText("نام کاربری را وارد کنید");
                        flag=0;
                    }
                    else
                        if(ui->password->text()==NULL)
                        {
                            ui->lbl_war_inf->setText("پسورد را وارد کنید");
                            flag=0;
                        }
                        else
                            if(ui->money_open->text()==NULL)
                            {
                                ui->lbl_war_inf->setText("مبلغ را وارد کنید");
                                flag=0;
                            }
                                else
                                    if(ui->name->text().toStdString().length()<3)
                                    {
                                        ui->lbl_war_inf->setText("اسم نا معتبر است");
                                        flag=0;
                                    }
                                    else
                                        if(ui->last_name->text().toStdString().length()<3)
                                        {
                                            ui->lbl_war_inf->setText("نام خانوادگی نا معتبر است");
                                            flag=0;
                                        }
                                        else
                                            if(ui->n_cod->text().toStdString().length()!=10)
                                            {
                                                ui->lbl_war_inf->setText("کد ملی نا معتبر است");
                                                flag=0;
                                            }else
                                                if(stod(ui->money_open->text().toStdString())<50000)
                                                {
                                                    ui->lbl_war_balanc->setText("مبلغ نا معتبر است");
                                                    ui->money_open->clear();
                                                    flag=0;
                                                }




   if(flag)
   {
       string date,Time;
       time_t T=time(0);
       tm *ltm = localtime(&T);
       date=to_string(1900 + ltm->tm_year)+"/"+to_string(1 + ltm->tm_mon)
           +"/"+to_string(ltm->tm_mday);
       Time=to_string(ltm->tm_hour)+':'+to_string(ltm->tm_min)+':'+to_string(ltm->tm_sec);
       Account ACCOUNT;
       string name;
       string last_name;
       string N_cod;
       string username;
       string pass;
       double balanc;
       bool condition;
       Date birth_date(ui->birth_day->text().toStdString());;
       name=ui->name->text().toStdString();
       last_name=ui->last_name->text().toStdString();
       N_cod=ui->n_cod->text().toStdString();
       bool exist_customer=0;
       int ind;
       for (int i=0;i<bank.Customers.size();i++)
       {
           if(bank.Customers.at(i).get_name()==name&&
                   bank.Customers.at(i).get_last_name()==last_name&&
                   bank.Customers.at(i).get_birth_day()==birth_date&&
                   bank.Customers.at(i).get_natioal_cod()==N_cod)
           {
               exist_customer=1;
               ind=i;
           }
       }
       if(exist_customer)
       {
           QString user=QString::fromStdString(bank.Customers.at(ind).get_username());
           ui->username->setText(user);
           QString pass=QString::fromStdString(bank.Customers.at(ind).get_password());
           ui->password->setText(pass);
           ui->username->setReadOnly(1);
           ui->password->setReadOnly(1);
           string acount=ui->number_account->text().toStdString();
           balanc=stod(ui->money_open->text().toStdString());
           if(ui->active->isChecked())
           {
               condition=1;
           }
           else
               {
                   condition=0;
               }
           ACCOUNT.set_num_account(acount);
           ACCOUNT.set_n_cod_owner_acount(N_cod);
           ACCOUNT.set_condition(condition);
           ACCOUNT.set_balanc(balanc);
           int accounts=bank.Customers.at(ind).get_Accounts().size();
           string inf="مشتری "+to_string(accounts)+" حساب دارد برای ایجاد حسای دیگر تایید کنید";
           ui->lbl_war_inf->setText(QString::fromStdString(inf));
           ui->accept->show();
           if(ui->accept->isChecked())
           {
               bank.Customers.at(ind).Accounts.push_back(ACCOUNT);
               ui->cond->setText("حساب ایجاد شد");
               string creat_cust="";
               creat_cust+=name+" with national cod "+
                       N_cod+" creat account in date: "+
                       date+"  time: "+Time+"\n";
               report<<creat_cust;
           }
           else
               ui->accept_creat->setText("برای ایجاد تایید کنید");
           
           
       }
       else
       {

           username=ui->username->text().toStdString();

           bool flag_user=0;
           for (int i=0;i<bank.Customers.size();i++)
           {
               if(username==bank.Customers.at(i).get_username())
                   flag_user=1;
           }
           if(flag_user)
           {
               ui->lbl_war_inf->setText("این نام کاربری قبلا انتخاب شده");
               ui->username->clear();
           }
           pass=ui->password->text().toStdString();
           string acount=ui->number_account->text().toStdString();
           balanc=stod(ui->money_open->text().toStdString());
           if(ui->active->isChecked())
           {
               condition=1;
           }
           else
               {
                   condition=0;
               }

           ACCOUNT.set_num_account(acount);
           ACCOUNT .set_n_cod_owner_acount(N_cod);
           ACCOUNT.set_balanc(balanc);
           ACCOUNT.set_condition(condition);
           ACCOUNT.set_opening_date(Date(date));
           ACCOUNT.set_time(Time);
           ui->accept->show();
           if(ui->accept->isChecked())
           {
               Customer c;
               c.name=name;
               c.last_name=last_name;
               c.national_cod=N_cod;
               c.birth_day=birth_date;
               c.username=username;
               c.password=pass;
               c.Accounts.push_back(ACCOUNT);
               bank.Customers.push_back(c);


               ui->cond->setText("مشتری جدید اضافه شد");
               string creat_cust="";
               creat_cust+=name+" with national cod "+
                       N_cod+" creat account in date: "+
                       date+"  time: "+Time+"\n";
               report<<creat_cust;
           }
           else
               ui->accept_creat->setText("برای ایجاد تایید کنید");

       }


   }
}

void opening_account::on_back_to_emploee_page_clicked()
{
    this->close();
    if(exist.at(1)==3)
    {
        emploee_page *ep=new emploee_page;
        ep->show();
    }
    else
    {
        manager_page *mg=new manager_page;
        mg->show();
    }

}
