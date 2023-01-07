#include "print_emp_with_pcod.h"
#include "ui_print_emp_with_pcod.h"
#include "bank.h"
#include"inf_emp_for_manag.h"
#include"ui_inf_emp_for_manag.h"
#include"manager_page.h"
print_emp_with_pcod::print_emp_with_pcod(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::print_emp_with_pcod)
{
    ui->setupUi(this);
}

print_emp_with_pcod::~print_emp_with_pcod()
{
    delete ui;
}

void print_emp_with_pcod::on_print_information_clicked()
{
    if(ui->ncod->text()=="" )
        ui->lbl_text->setText("کد پرسنلی خالی است");
    else

    {
        QString N_Cod=this->ui->ncod->text();
        int n_cod=stoi(N_Cod.toStdString());
        int ind=-1;
        for (int i=0;i<bank.Emploes.size();i++)
        {
            if(n_cod==bank.Emploes.at(i).get_Personnel_Code())
                ind=i;
        }
        if(ind!=-1)
        {
            this->close();
            inf_emp_for_manag *e_page=new inf_emp_for_manag;
            e_page->show();
            e_page->ui->lbl_ind->setText(QString::fromStdString(to_string(ind)));

            string name=bank.Emploes.at(ind).get_name();
            QString Name=QString::fromStdString(name);
            e_page->ui->name_emp->setText(Name);

            string l_name=bank.Emploes.at(ind).get_last_name();
            QString L_Name=QString::fromStdString(l_name);
            e_page->ui->last_name_emp->setText(L_Name);

            string date=bank.Emploes.at(ind).get_birth_day().print();
            QString Date=QString::fromStdString(date);
            e_page->ui->birth_day_emp->setText(Date);

            string user=bank.Emploes.at(ind).get_username();
            QString User=QString::fromStdString(user);
            e_page->ui->username_emp->setText(User);

            string pass=bank.Emploes.at(ind).get_password();
            QString Pass=QString::fromStdString(pass);
            e_page->ui->password_emp->setText(Pass);

            int p_code=bank.Emploes.at(ind).get_Personnel_Code();
            QString p_Code=QString::fromStdString(to_string(p_code));
            e_page->ui->p_cod->setText(p_Code);

            int o_h=bank.Emploes.at(ind).get_Overtime_hours();
            QString O_h=QString::fromStdString(to_string(o_h));
            e_page->ui->over->setText(O_h);

            int v_h=bank.Emploes.at(ind).get_Vacation_hours();
            QString V_h=QString::fromStdString(to_string(v_h));
            e_page->ui->vacat->setText(V_h);

        }
        else
        {
            ui->lbl_text->setText("کد پرسنلی اشتباه است");
            ui->ncod->clear();
        }
    }
}

void print_emp_with_pcod::on_BACK_clicked()
{
    this->close();
    manager_page *mp=new manager_page;
    mp->show();
}
