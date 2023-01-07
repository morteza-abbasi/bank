#ifndef SET_COND_BY_EMP_H
#define SET_COND_BY_EMP_H

#include <QWidget>

namespace Ui {
class set_cond_by_emp;
}

class set_cond_by_emp : public QWidget
{
    Q_OBJECT

public:
    explicit set_cond_by_emp(QWidget *parent = nullptr);
    ~set_cond_by_emp();

private slots:
    void on_print_information_clicked();

    void on_print_information_2_clicked();

    void on_back_to_emploee_page_clicked();

private:
    Ui::set_cond_by_emp *ui;
};

#endif // SET_COND_BY_EMP_H
