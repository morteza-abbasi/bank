#include "add_emp.h"
#include "ui_add_emp.h"
#include "bank.h"
#include"manager_page.h"
#include<cstdlib>
#include<ctime>
const char password[]="0123456789!@#$%&*()_qwertyuioplkjhgfdsazxcvbnm"
                      "QWERTYUIOPLKJHGFDSAZXCVBNM";
int pass_len=sizeof (password)-1;
const char username[]="0123456789_qwertyuioplkjhgfdsazxcvbnm"
                      "QWERTYUIOPLKJHGFDSAZXCVBNM";
int user_len=sizeof (username)-1;
add_emp::add_emp(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::add_emp)
{
    ui->setupUi(this);
    ui->username->setReadOnly(1);
    ui->password->setReadOnly(1);
    ui->p_cod->setReadOnly(1);
    ui->accept->hide();
}

add_emp::~add_emp()
{
    delete ui;
}

void add_emp::on_add_emploee_clicked()
{
    bool flag=1;
    if(ui->name->text()==NULL)
    {
        ui->lbl_war->setText("اسم را وارد کنید");
        flag=0;
    }
    else
        if(ui->last_name->text()==NULL)
        {
            ui->lbl_war->setText("فامیل را وارد کنید");
            flag=0;
        }
        else
            if(ui->birth_day->text()==NULL)
            {
                ui->lbl_war->setText("تاریخ تولد را وارد کنید");
                flag=0;
            }
            else
                if(ui->basic_salari->text()==NULL)
                {
                    ui->lbl_war->setText("حقوق را وارد کنید");
                    flag=0;
                }
                else
                    if(ui->p_cod->text()==NULL)
                    {
                        ui->lbl_war->setText("کلید انتخاب کد را بزنید");
                        flag=0;
                    }

                    else
                        if(ui->username->text()==NULL)
                        {
                            ui->lbl_war->setText("کلید انتخاب نام کاربری را بزنید");
                            flag=0;
                        }
                        else
                            if(ui->password->text()==NULL)
                            {
                                ui->lbl_war->setText("کلید انتخاب پسورد را بزنید");
                                flag=0;
                            }

                            else
                                if(ui->name->text().toStdString().length()<3)
                                {
                                    ui->lbl_war->setText("اسم نا معتبر است");
                                    ui->name->clear();
                                    flag=0;
                                }
                                else
                                    if(ui->last_name->text().toStdString().length()<3)
                                    {
                                        ui->lbl_war->setText("نام خانوادگی نا معتبر است");
                                        ui->last_name->clear();
                                        flag=0;
                                    }
                                    else
                                        if(stoi(ui->basic_salari->text().toStdString())<0)
                                        {
                                            ui->lbl_war->setText("مقدار حقوق نا معتبر است");
                                            ui->basic_salari->clear();
                                            flag=0;
                                        }
    if(flag)
    {

        string name;
        string last_name;
        int p_cod;
        string username;
        string pass;
        double basic_salary;
        Date birth_date(ui->birth_day->text().toStdString());;
        name=ui->name->text().toStdString();
        last_name=ui->last_name->text().toStdString();
        p_cod=stoi(ui->p_cod->text().toStdString());
        basic_salary=stod(ui->basic_salari->text().toStdString());
        username=ui->username->text().toStdString();
        pass=ui->password->text().toStdString();
        Emploee e(name, last_name,p_cod,birth_date,basic_salary,username,pass,0,0);
        bank.Emploes.push_back(e);
        ui->lbl_war->setText("استخدام انجام شد");

    }

}

void add_emp::on_p_cod_chose_clicked()
{
    int max = 999;
    int min = 100;
    srand(time(0));
    bool flag=1;
    int p_cod;
    while(1)
    {
        p_cod=rand()%(max - min) + min ;

        for(int i=0;i<bank.Emploes.size();i++)
        {

            if(bank.Emploes.at(i).get_Personnel_Code()==p_cod)
                flag=0;
        }
        if(flag)
        {
            string num_account=to_string(p_cod);
            QString Num_Account=QString::fromStdString(num_account);
            ui->p_cod->setText(Num_Account);
            break;
        }
    }
}

void add_emp::on_p_cod_chose_2_clicked()
{
    string pass="";
    bool flag=0;
    while(1)
    {
        for(int i=0;i<8;i++)
        {
            pass+=password[rand()%pass_len];
        }
        int i=0;
        while(1)
        {
            if(i<bank.Emploes.size())
            {
                if(pass==bank.Emploes.at(i).get_password())
                    flag=1;
            }
            else
            {
                if(i<bank.Customers.size())
                {
                    if(pass==bank.Customers.at(i).get_password())
                        flag=1;
                }
                else
                {
                    if(pass==bank.Manag.get_password())
                        flag=1;
                    break;
                }
            }
            i++;

        }
        if(!flag)
            break;

    }
    ui->password->setText(QString::fromStdString(pass));


}

void add_emp::on_user_chose_clicked()
{
    string user="";
    bool flag=0;
    while(1)
    {
        for(int i=0;i<8;i++)
        {
            user+=username[rand()%user_len];
        }
        int i=0;
        while(1)
        {
            if(i<bank.Emploes.size())
            {
                if(user==bank.Emploes.at(i).get_username())
                    flag=1;
            }
            else
            {
                if(i<bank.Customers.size())
                {
                    if(user==bank.Customers.at(i).get_username())
                        flag=1;
                }
                else
                {
                    if(user==bank.Manag.get_username())
                        flag=1;
                    break;
                }
            }
            i++;

        }
        if(!flag)
            break;

    }
    ui->username->setText(QString::fromStdString(user));
}

void add_emp::on_back_clicked()
{
    this->close();
    manager_page *mp=new manager_page;
    mp->show();
}
