#include "accounts_customer.h"
#include "ui_accounts_customer.h"
#include "bank.h"
#include "customer_page.h"
#include "ui_customer_page.h"
#include<iostream>
#include<fstream>
using namespace std;
extern vector<int> exist;


accounts_customer::accounts_customer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::accounts_customer)
{
    ui->setupUi(this);
}

accounts_customer::~accounts_customer()
{
    delete ui;
}

void accounts_customer::on_charg_clicked()
{
    if(ui->number_account_c->text()==NULL&&ui->money_charg->text()==NULL)
    {
        ui->inf_charg->setText("شماره حساب و مبلغ را وارد کنید");
    }
    else
        if(ui->number_account_c->text()!=NULL&&ui->money_charg->text()==NULL)
        {
            ui->inf_charg->setText("مبلغ را وارد کنید");
        }
    else
            if(ui->number_account_c->text()==NULL&&ui->money_charg->text()!=NULL)
            {
                ui->inf_charg->setText("شماره حساب را وارد کنید");

            }
    else
            {
                QString Num_Account=ui->number_account_c->text();
                string num_account=Num_Account.toStdString();
                bool flag=1;
                int indi;
                for (int i=0;i<bank.Customers.at(exist.at(2)).get_Accounts().size();i++)
                {
                        if(bank.Customers.at(exist.at(2)).Accounts.at(i).get_num_account()==num_account)
                        {
                            flag=0;
                            indi=i;
                        }
                }
                QString money=ui->money_charg->text();
                double Money=stod(money.toStdString());
                if(flag||Money<0)
                {
                    ui->inf_charg->setText("شماره حساب یا مبلغ نامعتبر است") ;
                }
                else
                {
                    bank.Customers.at(exist.at(2)).Accounts.at(indi).charge_account(Money);
                    ui->inf_charg->setText("شارژ انجام شد") ;
                    string date,Time;
                    time_t T=time(0);
                    tm *ltm = localtime(&T);
                    date=to_string(1900 + ltm->tm_year)+"/"+to_string(1 + ltm->tm_mon)
                            +"/"+to_string(ltm->tm_mday);
                    Time=to_string(ltm->tm_hour)+':'+to_string(ltm->tm_min)+':'+to_string(ltm->tm_sec);
                    string charg="";
                    charg+=bank.Customers.at(exist.at(2)).get_name()+" with national cod "+
                            bank.Customers.at(exist.at(2)).get_natioal_cod()+" charg account  "+
                            bank.Customers.at(exist.at(2)).get_Accounts().at(indi).get_num_account()+
                            "   with amount "+to_string(Money)+
                            "  in date: "+date+"  time: "+Time+"\n";

                    report<<charg;
                    ui->money_charg->clear();
                    ui->number_account_c->clear();
                    ui->accounts->clear();
                    QString account_back="";
                    for(int i=0;i<bank.Customers.at(exist.at(2)).get_Accounts().size();i++)
                    {
                        string account=bank.Customers.at(exist.at(2)).get_Accounts().at(i).print();
                        QString Acount=QString::fromStdString(account);
                        account_back+=Acount+"\n\n";

                    }
                    ui->accounts->setText(account_back);
                }

            }
}

void accounts_customer::on_bardasht_clicked()
{
    if(ui->number_account_b->text()==NULL&&ui->subtract_money->text()==NULL)
    {
        ui->inf_bardasht->setText("شماره حساب و مبلغ را وارد کنید");
    }
    else
        if(ui->number_account_b->text()!=NULL&&ui->subtract_money->text()==NULL)
        {
            ui->inf_bardasht->setText("مبلغ را وارد کنید");
        }
    else
            if(ui->number_account_b->text()==NULL&&ui->subtract_money->text()!=NULL)
            {
                ui->inf_bardasht->setText("شماره حساب را وارد کنید");

            }
    else
            {

                QString Num_Account=ui->number_account_b->text();
                string num_account=Num_Account.toStdString();
                bool flag=1;
                int indi;
                for (int i=0;i<bank.Customers.at(exist.at(2)).Accounts.size();i++)
                {
                        if(bank.Customers.at(exist.at(2)).Accounts.at(i).get_num_account()==num_account)
                        {
                            flag=0;
                            indi=i;
                        }
                }
                QString money=ui->subtract_money->text();
                double Money=stod(money.toStdString());
                if(bank.Customers.at(exist.at(2)).Accounts.at(indi).get_condition())
                {
                    if(flag||Money<0)
                    {
                        ui->inf_bardasht->setText("شماره حساب یا مبلغ نامعتبر است") ;
                    }
                    else
                    {
                        if(bank.Customers.at(exist.at(2)).Accounts.at(indi).get_balanc()<Money)
                            ui->inf_bardasht->setText("موجودی کافی نمی باشد");
                        else
                        {
                            bank.Customers.at(exist.at(2)).Accounts.at(indi).Withdraw_from_account(Money);
                            ui->inf_bardasht->setText("برداشت انجام شد") ;
                            ui->subtract_money->clear();
                            ui->number_account_b->clear();
                            ui->accounts->clear();
                            QString account_back="";
                            for(int i=0;i<bank.Customers.at(exist.at(2)).get_Accounts().size();i++)
                            {
                                string account=bank.Customers.at(exist.at(2)).get_Accounts().at(i).print();
                                QString Acount=QString::fromStdString(account);
                                account_back+=Acount+"\n\n";

                            }
                            ui->accounts->setText(account_back);
                        }

                    }
                }
                else
                    ui->inf_bardasht->setText("حساب شما غیر فعال است");

            }
}

void accounts_customer::on_back_menu_pc_clicked()
{
    this->close();
    customer_page *c_page=new customer_page;
    c_page->show();

}
