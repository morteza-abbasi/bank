#ifndef EMPLOEE_PAGE_H
#define EMPLOEE_PAGE_H

#include <QWidget>
#include<iostream>
using namespace std;
namespace Ui {
class emploee_page;
}

class emploee_page : public QWidget
{
    Q_OBJECT

public:
    explicit emploee_page(QWidget *parent = nullptr);
    ~emploee_page();
    friend class login;
private slots:
    void on_print_information_clicked();

    void on_open_account_clicked();

    void on_overtime_clicked();

    void on_vacation_clicked();


    void on_overtime_2_clicked();

    void on_overtime_3_clicked();

    void on_delete_customer_clicked();

    void on_back_menu_pc_clicked();

    void on_back_login_clicked();

    void on_delete_cust_clicked();

private:
    Ui::emploee_page *ui;

};

#endif // EMPLOEE_PAGE_H
