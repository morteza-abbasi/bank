#include "print_customer_with_ncod.h"
#include "ui_print_customer_with_ncod.h"
#include "information_cust_for_emp.h"
#include "ui_information_cust_for_emp.h"
#include "bank.h"
#include"manager_page.h"
#include"emploee_page.h"
#include <iostream>
using namespace std;

extern vector<int> exist;
print_customer_with_ncod::print_customer_with_ncod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::print_customer_with_ncod)
{
    ui->setupUi(this);
}

print_customer_with_ncod::~print_customer_with_ncod()
{
    delete ui;
}

void print_customer_with_ncod::on_print_information_clicked()
{

    QString N_Cod=this->ui->ncod->text();
    string n_cod=N_Cod.toStdString();
    int ind=-1;
    for (int i=0;i<bank.Customers.size();i++)
    {
        if(n_cod==bank.Customers.at(i).get_natioal_cod())
            ind=i;
    }
    if(ind!=-1)
    {
        this->close();
        information_cust_for_emp *c_page=new information_cust_for_emp;
        c_page->show();


        string name=bank.Customers.at(ind).get_name();
        QString Name=QString::fromStdString(name);
        c_page->ui->name_customer->setText(Name);

        string l_name=bank.Customers.at(ind).get_last_name();
        QString L_Name=QString::fromStdString(l_name);
        c_page->ui->last_name_customer->setText(L_Name);

        string n_code=bank.Customers.at(ind).get_natioal_cod();
        QString N_Code=QString::fromStdString(n_cod);
        c_page->ui->n_cod_customer->setText(N_Cod);

        string date=bank.Customers.at(ind).get_birth_day().print();
        QString Date=QString::fromStdString(date);
        c_page->ui->birth_day_customer->setText(Date);

        string user=bank.Customers.at(ind).get_username();
        QString User=QString::fromStdString(user);
        c_page->ui->username_customer->setText(User);

        string pass=bank.Customers.at(ind).get_password();
        QString Pass=QString::fromStdString(pass);
        c_page->ui->password_customer->setText(Pass);

        QString account_back=c_page->ui->accounts->text();
        for(int i=0;i<bank.Customers.at(ind).get_Accounts().size();i++)
        {
            string account=bank.Customers.at(ind).get_Accounts().at(i).print();
            QString Acount=QString::fromStdString(account);
            account_back+="\n\n"+Acount;
            c_page->ui->accounts->setText(account_back);
        }

    }
    else
    {
        ui->lbl_text->setText("کد ملی اشتباه است");
        ui->ncod->clear();
    }
}

void print_customer_with_ncod::on_back_clicked()
{
    this->close();
    if(exist.at(1)==2)
    {
        manager_page *m=new manager_page;
        m->show();
    }
    else
    {
        emploee_page *e=new emploee_page;
        e->show();
    }
}
