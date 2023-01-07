#ifndef MANAGER_PAGE_H
#define MANAGER_PAGE_H

#include <QWidget>

namespace Ui {
class manager_page;
}

class manager_page : public QWidget
{
    Q_OBJECT

public:
    explicit manager_page(QWidget *parent = nullptr);
    ~manager_page();

private slots:
    void on_open_account_clicked();

    void on_print_inf_cust_clicked();

    void on_delete_cust_clicked();

    void on_overtime_clicked();

    void on_vacation_clicked();

    void on_cond_clicked();

    void on_back_login_clicked();

    void on_print_inf_emp_clicked();

    void on_delete_emp_clicked();

    void on_add_emp_clicked();

    void on_over_clicked();

private:
    Ui::manager_page *ui;
};

#endif // MANAGER_PAGE_H
