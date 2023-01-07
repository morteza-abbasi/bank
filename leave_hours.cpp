#include "leave_hours.h"
#include "ui_leave_hours.h"
#include "emploee_page.h"
#include "bank.h"
#include "list_leave.h"
#include "ui_list_leave.h"
#include"manager_page.h";
extern vector<int> exist;
leave_hours::leave_hours(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::leave_hours)
{
    ui->setupUi(this);
    if(exist.at(1)==3)
    {
        ui->hour->setText(QString::fromStdString(to_string(bank.Emploes.at(exist.at(2)).get_Vacation_hours())));
    }
    else
    {
        ui->hour->setText(QString::fromStdString(to_string(bank.Manag.get_Vacation_hours())));

    }

}

leave_hours::~leave_hours()
{
    delete ui;
}

void leave_hours::on_back_to_emploee_page_clicked()
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

void leave_hours::on_accept_clicked()
{

    int leave;
    string op_sa_leave;
    string rec_leave;
    if(ui->hour_leave->text()=="")
        ui->end->setText("ساعت را وارد کنید");
    else
    {
        leave=stoi(ui->hour_leave->text().toStdString());
        if(exist.at(1)==3)
        {
             rec_leave=bank.Emploes.at(exist.at(2)).Record_leave(leave);
             op_sa_leave=bank.Emploes.at(exist.at(2)).operetion_salary_leave();
        }
        else
        {
             rec_leave=bank.Manag.Record_leave(leave);
             op_sa_leave=bank.Manag.operetion_salary_leave();
        }

        if(op_sa_leave!="")
        {
            ui->warning->setText(QString::fromStdString(op_sa_leave));
        }
        else{
            ui->information->setText(QString::fromStdString(rec_leave));
            string date,Time;
            time_t T=time(0);
            tm *ltm = localtime(&T);
            date=to_string(1900 + ltm->tm_year)+"/"+to_string(1 + ltm->tm_mon)
                    +"/"+to_string(ltm->tm_mday);
            string emp_leave="";
            emp_leave+=bank.Emploes.at(exist.at(2)).get_name()+" with personal cod "+
                    to_string(bank.Emploes.at(exist.at(2)).get_Personnel_Code())+
                    " get "+ to_string(leave)+" hour rest "
                    +" in date: "+date+"  time: "+Time+"\n";
            report<<emp_leave;

        }
    }
}

void leave_hours::on_list_clicked()
{
    this->close();
    list_leave *ls_lv=new list_leave;
    ls_lv->show();
    string inf="";
    if(exist.at(1)==3)
    {
        for(int i=0;i<bank.Emploes.at(exist.at(2)).Leave.size();i++)
        {
            inf+="\n\n";
            inf+=bank.Emploes.at(exist.at(2)).Leave.at(i);
        }
    }
    else
    {
        for(int i=0;i<bank.Manag.Leave.size();i++)
        {
            inf+="\n\n";
            inf+=bank.Manag.Leave.at(i);
        }
    }


    ls_lv->ui->warning->setText(QString::fromStdString(inf));
}


