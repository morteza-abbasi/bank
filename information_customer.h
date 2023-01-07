#ifndef INFORMATION_CUSTOMER_H
#define INFORMATION_CUSTOMER_H

#include <QWidget>
namespace Ui {
class information_customer;
}

class information_customer : public QWidget
{
    Q_OBJECT

public:
    explicit information_customer(QWidget *parent = nullptr);
    ~information_customer();
    friend class customer_page;

private slots:
    void on_back_menu_pc_clicked();

private:
    Ui::information_customer *ui;
};

#endif // INFORMATION_CUSTOMER_H
