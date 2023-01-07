#include "delete_customer.h"
#include "ui_delete_customer.h"
#include "bank.h"
#include "account.h"
#include"emploee_page.h"
#include"manager_page.h"
extern vector<int>exist;
delete_customer::delete_customer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::delete_customer)
{
    ui->setupUi(this);
    ui->label_6->hide();
    ui->num_account->hide();
    ui->print_information_2->hide();
    ui->lbl_ind->hide();
}

delete_customer::~delete_customer()
{
    delete ui;
}

void delete_customer::on_print_information_clicked()
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
            int count_account=bank.Customers.at(ind).get_Accounts().size();
            for(int i=0;i<count_account;i++)
            {
                inf+=bank.Customers.at(ind).get_Accounts().at(i).print()+"\n\n";
            }
            ui->information->setText(QString::fromStdString(inf));
            ui->lbl_ind->setText(QString::fromStdString(to_string(ind)));
            if(count_account>1)
            {
                ui->label_6->show();
                ui->num_account->show();
                ui->print_information_2->show();
                ui->lbl_text->clear();
            }
            else
            {
                vector<Customer> result;
                for(int i=0;i<bank.Customers.size();i++)
                {
                    if(i!=ind)
                        result.push_back(bank.Customers.at(i));
                }
                bank.Customers.clear();
                for(int i=0;i<result.size();i++)
                {
                    bank.Customers.push_back(result.at(i));
                }
                ui->result->setText("مشتری حذف شد");
            }
        }
        else
        {
            ui->lbl_text->setText("کد ملی نا معتبر است");

        }
    }
}

void delete_customer::on_print_information_2_clicked()
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
            vector<class Account> result;
            for (int i=0;i<bank.Customers.at(ind).get_Accounts().size();i++)
            {
                if(i!=f)
                    result.push_back(bank.Customers.at(ind).get_Accounts().at(i));
            }
            bank.Customers.at(ind).Accounts.clear();
            for (int i=0;i<result.size();i++)
            {
                bank.Customers.at(ind).Accounts.push_back(result.at(i));
            }
            string inf="";
            int count_account=bank.Customers.at(ind).get_Accounts().size();
            for(int i=0;i<count_account;i++)
            {
                inf+=bank.Customers.at(ind).get_Accounts().at(i).print()+"\n\n";
            }
            ui->information->setText(QString::fromStdString(inf));
            ui->result->setText("حساب مشتری حذف شد");
        }
        else
            ui->result->setText("شماره حساب نا معتبر است");

    }
}

void delete_customer::on_back_to_emploee_page_clicked()
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
