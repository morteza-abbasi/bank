#include "list_overtime.h"
#include "ui_list_overtime.h"
#include "overtime_hour.h"

list_overtime::list_overtime(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_overtime)
{
    ui->setupUi(this);
}

list_overtime::~list_overtime()
{
    delete ui;
}

void list_overtime::on_back_to_emploee_page_clicked()
{
    this->close();
    overtime_hour *l =new overtime_hour;
    l->show();
}
