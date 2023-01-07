#ifndef INFORMATION_CUST_FOR_EMP_H
#define INFORMATION_CUST_FOR_EMP_H

#include <QWidget>

namespace Ui {
class information_cust_for_emp;
}

class information_cust_for_emp : public QWidget
{
    Q_OBJECT

public:
    explicit information_cust_for_emp(QWidget *parent = nullptr);
    ~information_cust_for_emp();
    friend class print_customer_with_ncod;

private slots:
    void on_back_menu_pc_clicked();

private:
    Ui::information_cust_for_emp *ui;
};

#endif // INFORMATION_CUST_FOR_EMP_H
