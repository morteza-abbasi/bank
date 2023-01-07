#ifndef DEL_EMP_H
#define DEL_EMP_H

#include <QWidget>

namespace Ui {
class del_emp;
}

class del_emp : public QWidget
{
    Q_OBJECT

public:
    explicit del_emp(QWidget *parent = nullptr);
    ~del_emp();

private slots:
    void on_print_information_clicked();

    void on_print_information_2_clicked();

private:
    Ui::del_emp *ui;
};

#endif // DEL_EMP_H
