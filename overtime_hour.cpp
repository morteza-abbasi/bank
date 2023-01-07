#include "overtime_hour.h"
#include "ui_overtime_hour.h"
#include "emploee_page.h"
#include "bank.h"
#include "list_overtime.h"
#include "ui_list_overtime.h"
#include"manager_page.h"
extern vector<int> exist;
overtime_hour::overtime_hour(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::overtime_hour)
{
    ui->setupUi(this);
    QString h;
    if(exist.at(1)==3)
         h=QString::fromStdString(to_string( bank.Emploes.at(exist.at(2)).get_Overtime_hours()));
    else
         h=QString::fromStdString(to_string( bank.Manag.get_Overtime_hours()));
    ui->hour->setText(h);
}

overtime_hour::~overtime_hour()
{
    delete ui;
}

void overtime_hour::on_back_to_emploee_page_clicked()
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

void overtime_hour::on_accept_clicked()
{
    int overtime;
    int OVER;
    string op_sa_overtime;
    string rec_overtime;
    if(ui->hour_overtime->text()==NULL)
        ui->end->setText("ساعت را وارد کنید");
    else
    {
        overtime=stoi(ui->hour_overtime->text().toStdString());
        if(exist.at(1)==3)
        {
             OVER=overtime+bank.Emploes.at(exist.at(2)).get_Overtime_hours();
        }
        else
        {
             OVER=overtime+bank.Manag.get_Overtime_hours();

        }
        if(OVER>12)
            ui->end->setText("اضافه کار پر شده ");
        else
        {
            if(exist.at(1)==3)
            {
                 rec_overtime=bank.Emploes.at(exist.at(2)).Record_overtime(overtime);
                 op_sa_overtime=bank.Emploes.at(exist.at(2)).operetion_salary_overtime();
            }
            else
            {
                 rec_overtime=bank.Manag.Record_overtime(overtime);
                 op_sa_overtime=bank.Manag.operetion_salary_overtime();
            }
            ui->information->setText(QString::fromStdString(rec_overtime));
            ui->warning->setText(QString::fromStdString(op_sa_overtime));


        }

    }
}

void overtime_hour::on_list_clicked()
{
    this->close();
    list_overtime *ls_lv=new list_overtime;
    ls_lv->show();
    string inf="";
    if(exist.at(1)==3)
    {
        for(int i=0;i<bank.Emploes.at(exist.at(2)).Over.size();i++)
        {
            inf+="\n\n";
            inf+=bank.Emploes.at(exist.at(2)).Over.at(i);
        }
    }
    else
    {
        for(int i=0;i<bank.Manag.Over.size();i++)
        {
            inf+="\n\n";
            inf+=bank.Manag.Over.at(i);
        }
    }

    ls_lv->ui->warning->setText(QString::fromStdString(inf));
}
