#include "inf_emp_for_manag.h"
#include "ui_inf_emp_for_manag.h"
#include "bank.h"
#include"manager_page.h"
inf_emp_for_manag::inf_emp_for_manag(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::inf_emp_for_manag)
{
    ui->setupUi(this);
    ui->lbl_ind->hide();
}

inf_emp_for_manag::~inf_emp_for_manag()
{
    delete ui;
}

void inf_emp_for_manag::on_overtime_clicked()
{
    int ind=stoi(ui->lbl_ind->text().toStdString());
    string inf="";
    for(int i=0;i<bank.Emploes.at(ind).Over.size();i++)
    {
        inf+="\n\n"+bank.Emploes.at(ind).Over.at(i);
    }
    ui->inf->setText(QString::fromStdString(inf));
}

void inf_emp_for_manag::on_vacation_clicked()
{
    int ind=stoi(ui->lbl_ind->text().toStdString());
    string inf="";
    for(int i=0;i<bank.Emploes.at(ind).Leave.size();i++)
    {
        inf+="\n\n"+bank.Emploes.at(ind).Leave.at(i);
    }
    ui->inf->setText(QString::fromStdString(inf));
}

void inf_emp_for_manag::on_back_menu_pc_clicked()
{
    this->close();
    manager_page *mp=new manager_page;
    mp->show();
}
