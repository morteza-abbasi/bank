#include "information_customer.h"
#include "ui_information_customer.h"
#include "customer_page.h"
#include "ui_customer_page.h"
#include "bank.h"
#include<iostream>
using namespace std;
extern Bank bank;
extern vector<int> exist;
information_customer::information_customer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::information_customer)
{
    ui->setupUi(this);
}

information_customer::~information_customer()
{
    delete ui;
}

void information_customer::on_back_menu_pc_clicked()
{
    this->close();
    customer_page *c_page=new customer_page;
    c_page->show();
    string name=bank.Customers.at(exist.at(2)).get_name()+" "+bank.Customers.at(exist.at(2)).get_last_name();
    QString qstr = QString::fromStdString(name);
    c_page->ui->name_lastname->setText(qstr);
}
