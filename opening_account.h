#ifndef OPENING_ACCOUNT_H
#define OPENING_ACCOUNT_H

#include <QWidget>

namespace Ui {
class opening_account;
}

class opening_account : public QWidget
{
    Q_OBJECT

public:
    explicit opening_account(QWidget *parent = nullptr);
    ~opening_account();

private slots:
    void on_chose_number_account_clicked();

    void on_creat_account_clicked();

    void on_back_to_emploee_page_clicked();

private:
    Ui::opening_account *ui;
};

#endif // OPENING_ACCOUNT_H
