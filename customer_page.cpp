#include "customer_page.h"
#include "ui_customer_page.h"
#include "view_bank.h"
#include"information_customer.h"
#include"ui_information_customer.h"
#include"accounts_customer.h"
#include "ui_accounts_customer.h"
#include"login.h"
#include"bank.h"
#include<vector>
using namespace std;
extern vector<int> exist;
customer_page::customer_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::customer_page)
{
    ui->setupUi(this);
    string name=bank.Customers.at(exist.at(2)).get_name()+" "+bank.Customers.at(exist.at(2)).get_last_name();
    QString qstr = QString::fromStdString(name);
    ui->name_lastname->setText(qstr);
}

customer_page::~customer_page()
{
    delete ui;
}

void customer_page::on_back_menu_pc_clicked()
{
    this->close();
    view_bank *view=new view_bank;
    view->show();
}

void customer_page::on_print_information_clicked()
{
    this->close();
    information_customer *inf_cust=new information_customer;
    inf_cust->show();

    string name=bank.Customers.at(exist.at(2)).get_name();
    QString Name=QString::fromStdString(name);
    inf_cust->ui->name_customer->setText(Name);

    string l_name=bank.Customers.at(exist.at(2)).get_last_name();
    QString L_Name=QString::fromStdString(l_name);
    inf_cust->ui->last_name_customer->setText(L_Name);

    string n_cod=bank.Customers.at(exist.at(2)).get_natioal_cod();
    QString N_Cod=QString::fromStdString(n_cod);
    inf_cust->ui->n_cod_customer->setText(N_Cod);

    string date=bank.Customers.at(exist.at(2)).get_birth_day().print();
    QString Date=QString::fromStdString(date);
    inf_cust->ui->birth_day_customer->setText(Date);

    string user=bank.Customers.at(exist.at(2)).get_username();
    QString User=QString::fromStdString(user);
    inf_cust->ui->username_customer->setText(User);

    string pass=bank.Customers.at(exist.at(2)).get_password();
    QString Pass=QString::fromStdString(pass);
    inf_cust->ui->password_customer->setText(Pass);

    QString account_back=inf_cust->ui->accounts->text();
    for(int i=0;i<bank.Customers.at(exist.at(2)).get_Accounts().size();i++)
    {
        string account=bank.Customers.at(exist.at(2)).get_Accounts().at(i).print();
        QString Acount=QString::fromStdString(account);
        account_back+="\n\n"+Acount;
        inf_cust->ui->accounts->setText(account_back);
    }
}

void customer_page::on_btt_account_clicked()
{
    this->close();
    accounts_customer *account_c=new accounts_customer;
    account_c->show();
    QString account_back=account_c->ui->accounts->text();
    for(int i=0;i<bank.Customers.at(exist.at(2)).get_Accounts().size();i++)
    {
        string account=bank.Customers.at(exist.at(2)).get_Accounts().at(i).print();
        QString Acount=QString::fromStdString(account);
        account_back+="\n\n"+Acount;
        account_c->ui->accounts->setText(account_back);
    }
}
