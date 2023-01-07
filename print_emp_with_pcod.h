#ifndef PRINT_EMP_WITH_PCOD_H
#define PRINT_EMP_WITH_PCOD_H

#include <QWidget>

namespace Ui {
class print_emp_with_pcod;
}

class print_emp_with_pcod : public QWidget
{
    Q_OBJECT

public:
    explicit print_emp_with_pcod(QWidget *parent = nullptr);
    ~print_emp_with_pcod();

private slots:
    void on_print_information_clicked();

    void on_BACK_clicked();

private:
    Ui::print_emp_with_pcod *ui;
};

#endif // PRINT_EMP_WITH_PCOD_H
