#include "list_leave.h"
#include "ui_list_leave.h"
#include "leave_hours.h"
#include "ui_leave_hours.h"
#include "bank.h"
extern Bank bank;
extern vector<int>exist;
list_leave::list_leave(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::list_leave)
{
    ui->setupUi(this);
}

list_leave::~list_leave()
{
    delete ui;
}

void list_leave::on_back_to_emploee_page_clicked()
{
    this->close();
    leave_hours *l =new leave_hours;
    l->show();

}
