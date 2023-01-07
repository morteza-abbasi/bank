#ifndef ACCOUNTS_CUSTOMER_H
#define ACCOUNTS_CUSTOMER_H

#include <QWidget>

namespace Ui {
class accounts_customer;
}

class accounts_customer : public QWidget
{
    Q_OBJECT

public:
    explicit accounts_customer(QWidget *parent = nullptr);
    ~accounts_customer();
    friend class customer_page;
private slots:
    void on_charg_clicked();

    void on_bardasht_clicked();

    void on_back_menu_pc_clicked();

private:
    Ui::accounts_customer *ui;
};

#endif // ACCOUNTS_CUSTOMER_H
