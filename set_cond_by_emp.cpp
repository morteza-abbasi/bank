#include "set_cond_by_emp.h"
#include "ui_set_cond_by_emp.h"
#include <iostream>
#include "bank.h"
#include "emploee_page.h"
#include"manager_page.h"
extern vector<int> exist;
using namespace std;
//extern Bank bank;
set_cond_by_emp::set_cond_by_emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::set_cond_by_emp)
{
    ui->setupUi(this);
    ui->lbl_ind->hide();
    ui->label_6->hide();
    ui->num_account->hide();
    ui->print_information_2->hide();
}

set_cond_by_emp::~set_cond_by_emp()
{
    delete ui;
}

void set_cond_by_emp::on_print_information_clicked()
{
    if(ui->ncod->text()=="")
        ui->lbl_text->setText("کد ملی را وارد کنید");
    else
    {
        string n_cod=ui->ncod->text().toStdString();
        int ind=-1;
        for(int i=0;i<bank.Customers.size();i++)
        {
            if(bank.Customers.at(i).get_natioal_cod()==n_cod)
                ind=i;
        }
        if(ind!=-1)
        {
            string inf="";
            for(int i=0;i<bank.Customers.at(ind).get_Accounts().size();i++)
            {
                inf+=bank.Customers.at(ind).get_Accounts().at(i).print()+"\n\n";
            }
            ui->information->setText(QString::fromStdString(inf));
            ui->lbl_ind->setText(QString::fromStdString(to_string(ind)));
            ui->label_6->show();
            ui->num_account->show();
            ui->print_information_2->show();
            ui->lbl_text->clear();
        }
        else
        {
            ui->lbl_text->setText("کد ملی نا معتبر است");
        }
    }

}

void set_cond_by_emp::on_print_information_2_clicked()
{
    int ind=stoi(ui->lbl_ind->text().toStdString());

    if(ui->lbl_ind->text()=="")
        ui->result->setText("شماره حساب خالی است");
    else
    {

        string Num_account=ui->num_account->text().toStdString();
        int f=-1;
        for(int i=0;i<bank.Customers.at(ind).get_Accounts().size();i++)
        {
            if(bank.Customers.at(ind).get_Accounts().at(i).get_num_account()==Num_account)
            {
                f=i;
            }
        }
        if(f!=-1)

        {
            string date,Time;
            time_t T=time(0);
            tm *ltm = localtime(&T);
            date=to_string(1900 + ltm->tm_year)+"/"+to_string(1 + ltm->tm_mon)
                    +"/"+to_string(ltm->tm_mday);
            bool flag=bank.Customers.at(ind).get_Accounts().at(f).get_condition();
            bank.Customers.at(ind).Accounts.at(f).set_condition(!flag);
            ui->result->setText("وضعیت حساب تغییر کرد");
            string off_on="";
            off_on+=bank.Customers.at(exist.at(2)).get_name()+" with national cod "+
                    bank.Customers.at(exist.at(2)).get_natioal_cod()+" banned in date: "+
                    date+"  time: "+Time+"\n";
            report<<off_on;
            string inf="";
            for(int i=0;i<bank.Customers.at(ind).get_Accounts().size();i++)
            {
                inf+=bank.Customers.at(ind).get_Accounts().at(i).print()+"\n\n";
            }
            ui->information->clear();
            ui->information->setText(QString::fromStdString(inf));

        }
        else
            ui->result->setText("شماره حساب نا معتبر است");

    }
}

void set_cond_by_emp::on_back_to_emploee_page_clicked()
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
