#include "emploee_page.h"
#include "ui_emploee_page.h"
#include "print_customer_with_ncod.h"
#include "ui_print_customer_with_ncod.h"
#include "opening_account.h"
#include "ui_opening_account.h"
#include "leave_hours.h"
#include "ui_leave_hours.h"
#include "bank.h"
#include "overtime_hour.h"
#include "set_cond_by_emp.h"
#include "delete_customer.h"
#include "login.h"

//extern Bank bank;
extern vector<int> exist;
emploee_page::emploee_page(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::emploee_page)
{
    ui->setupUi(this);
    string name=bank.Emploes.at(exist.at(2)).get_name()+" "+bank.Emploes.at(exist.at(2)).get_last_name();
    QString qstr = QString::fromStdString(name);
    ui->name_lastname->setText(qstr);

}

emploee_page::~emploee_page()
{
    delete ui;
}

void emploee_page::on_print_information_clicked()
{
    this->close();
    print_customer_with_ncod *window=new print_customer_with_ncod;
    window->show();
}

void emploee_page::on_open_account_clicked()
{
    this->close();
    opening_account *account=new opening_account;
    account->show();

}

void emploee_page::on_overtime_clicked()
{
    this->close();
    leave_hours *l=new leave_hours;
    l->show();

}

void emploee_page::on_vacation_clicked()
{
    this->close();
    overtime_hour *l=new overtime_hour;
    l->show();
}

void emploee_page::on_overtime_2_clicked()
{
    this->close();
    set_cond_by_emp *cond= new set_cond_by_emp;
    cond->show();

}


void emploee_page::on_back_login_clicked()
{
    this->close();
    login *l=new login;
    l->show();
}

void emploee_page::on_delete_cust_clicked()
{
    this->close();
    delete_customer *dl= new delete_customer;
    dl->show();
}
