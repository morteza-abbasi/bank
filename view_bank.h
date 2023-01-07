#ifndef VIEW_BANK_H
#define VIEW_BANK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class view_bank; }
QT_END_NAMESPACE

class view_bank : public QMainWindow
{
    Q_OBJECT

public:
    view_bank(QWidget *parent = nullptr);
    ~view_bank();

private slots:
    void on_exit_clicked();

    void on_Customer_clicked();

private:
    Ui::view_bank *ui;
};
#endif // VIEW_BANK_H
