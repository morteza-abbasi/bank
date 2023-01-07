#ifndef CUSTOMER_PAGE_H
#define CUSTOMER_PAGE_H

#include <QWidget>

namespace Ui {
class customer_page;
}

class customer_page : public QWidget
{
    Q_OBJECT

public:
    explicit customer_page(QWidget *parent = nullptr);
    ~customer_page();
    friend class login;
    friend class information_customer;
    friend class accounts_customer;
private slots:
    void on_back_menu_pc_clicked();

    void on_print_information_clicked();

    void on_btt_account_clicked();

private:
    Ui::customer_page *ui;
};

#endif // CUSTOMER_PAGE_H
