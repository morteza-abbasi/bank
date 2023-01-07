#include "manager_page.h"
#include "ui_manager_page.h"
#include"bank.h"
#include"opening_account.h"
#include"print_customer_with_ncod.h"
#include"delete_customer.h"
#include"leave_hours.h"
#include"set_cond_by_emp.h"
#include"print_emp_with_pcod.h"
#include"overtime_hour.h"
#include"del_emp.h"
#include"add_emp.h"

//using namespace std;
extern vector<int>exist;
manager_page::manager_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::manager_page)
{
    ui->setupUi(this);
    string name=bank.Manag.get_name()+"  "+bank.Manag.get_last_name();
    QString qstr = QString::fromStdString(name);
    ui->name_lastname->setText(qstr);
}

manager_page::~manager_page()
{
    delete ui;
}

void manager_page::on_open_account_clicked()
{
    this->close();
    opening_account *account=new opening_account;
    account->show();

}

void manager_page::on_print_inf_cust_clicked()
{
    this->close();
    print_customer_with_ncod *window=new print_customer_with_ncod;
    window->show();
}

void manager_page::on_delete_cust_clicked()
{
    this->close();
    delete_customer *dl= new delete_customer;
    dl->show();
}

void manager_page::on_vacation_clicked()
{
    this->close();
    leave_hours *l=new leave_hours;
    l->show();
}



void manager_page::on_cond_clicked()
{
    this->close();
    set_cond_by_emp *cond= new set_cond_by_emp;
    cond->show();
}

void manager_page::on_back_login_clicked()
{
    this->close();
    this->~manager_page();
    login *l=new login;
    l->show();
}

void manager_page::on_print_inf_emp_clicked()
{
    this->close();
    print_emp_with_pcod *p=new print_emp_with_pcod;
    p->show();
}

void manager_page::on_delete_emp_clicked()
{
    this->close();
    del_emp *de=new del_emp;
    de->show();
}

void manager_page::on_add_emp_clicked()
{
    this->close();
    add_emp *add=new add_emp;
    add->show();
}

void manager_page::on_over_clicked()
{
    this->close();
    overtime_hour *over=new overtime_hour;
    over->show();
}
