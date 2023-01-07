#ifndef OVERTIME_HOUR_H
#define OVERTIME_HOUR_H

#include <QWidget>

namespace Ui {
class overtime_hour;
}

class overtime_hour : public QWidget
{
    Q_OBJECT

public:
    explicit overtime_hour(QWidget *parent = nullptr);
    ~overtime_hour();

private slots:
    void on_back_to_emploee_page_clicked();

    void on_accept_clicked();

    void on_list_clicked();

private:
    Ui::overtime_hour *ui;
};

#endif // OVERTIME_HOUR_H
