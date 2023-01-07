#ifndef LIST_OVERTIME_H
#define LIST_OVERTIME_H

#include <QWidget>

namespace Ui {
class list_overtime;
}

class list_overtime : public QWidget
{
    Q_OBJECT

public:
    explicit list_overtime(QWidget *parent = nullptr);
    ~list_overtime();

    friend class overtime_hour;
private slots:
    void on_back_to_emploee_page_clicked();

private:
    Ui::list_overtime *ui;
};

#endif // LIST_OVERTIME_H
