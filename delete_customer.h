#ifndef DELETE_CUSTOMER_H
#define DELETE_CUSTOMER_H

#include <QWidget>

namespace Ui {
class delete_customer;
}

class delete_customer : public QWidget
{
    Q_OBJECT

public:
    explicit delete_customer(QWidget *parent = nullptr);
    ~delete_customer();

private slots:
    void on_print_information_clicked();

    void on_print_information_2_clicked();

    void on_back_to_emploee_page_clicked();

private:
    Ui::delete_customer *ui;
};

#endif // DELETE_CUSTOMER_H
