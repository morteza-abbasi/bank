#include "del_emp.h"
#include "ui_del_emp.h"
#include"bank.h"
#include"manager_page.h"
del_emp::del_emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::del_emp)
{
    ui->setupUi(this);
}

del_emp::~del_emp()
{
    delete ui;
}

void del_emp::on_print_information_clicked()
{
    if(ui->ncod->text()=="")
        ui->lbl_text->setText("کد پرسنلی را وارد کنید");
    else

    {
        QString p_Cod=this->ui->ncod->text();
        int p_cod=stoi(p_Cod.toStdString());
        int ind=-1;
        for (int i=0;i<bank.Emploes.size();i++)
        {
            if(p_cod==bank.Emploes.at(i).get_Personnel_Code())
                ind=i;
        }

        if(ind!=-1)
        {
            vector<Emploee> result;
            for(int i=0;i<bank.Emploes.size();i++)
            {
                if(i!=ind)
                    result.push_back(bank.Emploes.at(i));
            }

            bank.Emploes.clear();
            for(int i=0;i<result.size();i++)
            {
                bank.Emploes.push_back(result.at(i));
            }
            ui->lbl_text->setText("کارمند اخراج شد");
        }
        else
        {
            ui->lbl_text->setText("کد پرسنلی اشتباه است");
            ui->ncod->clear();
        }
    }
}

void del_emp::on_print_information_2_clicked()
{
    this->close();
    manager_page *mp=new manager_page;
    mp->show();
}
