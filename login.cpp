#include "login.h"
#include "ui_login.h"
#include<ui_view_bank.h>
#include<view_bank.h>
#include"customer_page.h"
#include"ui_customer_page.h"
#include"emploee_page.h"
#include"ui_emploee_page.h"
#include"bank.h"
#include "manager_page.h"
#include<QString>
#include<iostream>
#include<vector>
#include<fstream>
vector<int> exist;
using namespace std;
login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_back_menu_login_clicked()
{
    this->close();
    view_bank *view=new view_bank;
    view->show();
}

void login::on_login_page_customer_clicked()
{
    if(ui->user->text()==NULL&&ui->pass->text()!=NULL)
    {
        ui->lbl_Condition->setText("نام کاربری را وارد کنید ");
    }
    else
        if(ui->user->text()!=NULL&&ui->pass->text()==NULL)
        {
            ui->lbl_Condition->setText("پسورد را وارد کنید ");

        }
    else
            if(ui->user->text()==NULL&&ui->pass->text()==NULL)
            {
                ui->lbl_Condition->setText("نام کاربری و پسورد را وارد کنید ");

            }
    else
            {
                //vector<int> exist;
                exist=bank.find_person(ui->user->text().toStdString(),ui->pass->text().toStdString());
                if(!exist.at(0))
                {
                    ui->lbl_Condition->setText("نام کاربری یا رمز عبور اشتباه است");
                }
                else
                {
                    string date,Time;
                    time_t T=time(0);
                    tm *ltm = localtime(&T);
                    date=to_string(1900 + ltm->tm_year)+"/"+to_string(1 + ltm->tm_mon)
                            +"/"+to_string(ltm->tm_mday);
                    Time=to_string(ltm->tm_hour)+':'+to_string(ltm->tm_min)+':'+to_string(ltm->tm_sec);
                    if(exist.at(1)==4)
                    {
                        this->close();
                        customer_page *c_page=new customer_page;
                        string log_cust="";
                        log_cust+=bank.Customers.at(exist.at(2)).get_name()+" with national cod "+
                                bank.Customers.at(exist.at(2)).get_natioal_cod()+" login in date: "+
                                date+"  time: "+Time+"\n";
                        report<<log_cust;
                        c_page->show();
                    }
                    else
                        if(exist.at(1)==3)
                        {
                            this->close();
                            emploee_page *e_page=new emploee_page;
                            string log_emp="";
                            log_emp+=bank.Emploes.at(exist.at(2)).get_name()+" with personal cod "+
                                    to_string(bank.Emploes.at(exist.at(2)).get_Personnel_Code())+" login in date: "+
                                    date+"  time: "+Time+"\n";
                            report<<log_emp;
                            e_page->show();
                        }
                    else
                            if(exist.at(1)==2)
                            {
                                this->close();
                                manager_page *mg=new manager_page;
                                mg->show();
                            }
                }

            }
}
