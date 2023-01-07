#ifndef LEAVE_HOURS_H
#define LEAVE_HOURS_H

#include <QWidget>

namespace Ui {
class leave_hours;
}

class leave_hours : public QWidget
{
    Q_OBJECT

public:
    explicit leave_hours(QWidget *parent = nullptr);
    ~leave_hours();

private slots:
    void on_back_to_emploee_page_clicked();

    void on_accept_clicked();

    void on_accept_2_clicked();

    void on_list_clicked();
    friend class emploee_page;
    friend class list_leave;
private:
    Ui::leave_hours *ui;
};

#endif // LEAVE_HOURS_H
