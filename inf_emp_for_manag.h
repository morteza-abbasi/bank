#ifndef INF_EMP_FOR_MANAG_H
#define INF_EMP_FOR_MANAG_H

#include <QWidget>

namespace Ui {
class inf_emp_for_manag;
}

class inf_emp_for_manag : public QWidget
{
    Q_OBJECT

public:
    explicit inf_emp_for_manag(QWidget *parent = nullptr);
    ~inf_emp_for_manag();
    friend class print_emp_with_pcod;
private slots:
    void on_overtime_clicked();

    void on_vacation_clicked();

    void on_back_menu_pc_clicked();

private:
    Ui::inf_emp_for_manag *ui;
};

#endif // INF_EMP_FOR_MANAG_H
