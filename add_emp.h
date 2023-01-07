#ifndef ADD_EMP_H
#define ADD_EMP_H

#include <QWidget>

namespace Ui {
class add_emp;
}

class add_emp : public QWidget
{
    Q_OBJECT

public:
    explicit add_emp(QWidget *parent = nullptr);
    ~add_emp();

private slots:
    void on_add_emploee_clicked();

    void on_p_cod_chose_clicked();

    void on_p_cod_chose_2_clicked();

    void on_user_chose_clicked();

    void on_back_clicked();

private:
    Ui::add_emp *ui;
};

#endif // ADD_EMP_H
