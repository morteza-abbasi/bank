#ifndef LIST_LEAVE_H
#define LIST_LEAVE_H

#include <QWidget>

namespace Ui {
class list_leave;
}

class list_leave : public QWidget
{
    Q_OBJECT

public:
    explicit list_leave(QWidget *parent = nullptr);
    ~list_leave();
    friend class leave_hours;
private slots:
    void on_back_to_emploee_page_clicked();

private:
    Ui::list_leave *ui;
};

#endif // LIST_LEAVE_H
