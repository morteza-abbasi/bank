#ifndef PRINT_CUSTOMER_WITH_NCOD_H
#define PRINT_CUSTOMER_WITH_NCOD_H

#include <QWidget>

namespace Ui {
class print_customer_with_ncod;
}

class print_customer_with_ncod : public QWidget
{
    Q_OBJECT

public:
    explicit print_customer_with_ncod(QWidget *parent = nullptr);
    ~print_customer_with_ncod();

private slots:
    void on_print_information_clicked();

    void on_back_clicked();

private:
    Ui::print_customer_with_ncod *ui;
};

#endif // PRINT_CUSTOMER_WITH_NCOD_H
