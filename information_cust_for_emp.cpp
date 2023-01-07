#include "information_cust_for_emp.h"
#include "ui_information_cust_for_emp.h"
#include "emploee_page.h"
#include "ui_emploee_page.h"
#include "manager_page.h"
extern vector<int> exist;
information_cust_for_emp::information_cust_for_emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::information_cust_for_emp)
{
    ui->setupUi(this);
}

information_cust_for_emp::~information_cust_for_emp()
{
    delete ui;
}

void information_cust_for_emp::on_back_menu_pc_clicked()
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
