#ifndef DIALOG1_H
#define DIALOG1_H
#include <mainwindow.h>
#include <QDialog>

namespace Ui {
class Dialog1;
}

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog1(QWidget *parent = nullptr);
    ~Dialog1();
signals:
    void firstWindow();
private slots:
    void on_add_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::Dialog1 *ui;


};

#endif // DIALOG1_H
