#ifndef EDIT_H
#define EDIT_H
#include <mainwindow.h>
#include <QDialog>

namespace Ui {
class edit;
}

class edit : public QDialog
{
    Q_OBJECT

public:
    explicit edit(QWidget *parent = nullptr);
    ~edit();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::edit *ui;
};

#endif // EDIT_H
