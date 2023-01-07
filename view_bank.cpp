#include "view_bank.h"
#include "ui_view_bank.h"
#include "login.h"
#include "ui_login.h"
view_bank::view_bank(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::view_bank)
{
    ui->setupUi(this);
}

view_bank::~view_bank()
{
    delete ui;
}


void view_bank::on_exit_clicked()
{
    this->close();
}

void view_bank::on_Customer_clicked()
{
    this->close();
    login *log=new login();
    log->show();
}
