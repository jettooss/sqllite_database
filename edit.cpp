#include "edit.h"
#include "ui_edit.h"

edit::edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::edit)
{
    ui->setupUi(this);
}

edit::~edit()
{
    delete ui;
}

void edit::on_pushButton_clicked()
{
    MainWindow conn;
    QString five, first, second, third, four, sixth, seventh;
    first = ui -> first-> text();
    second = ui -> second-> text();
    third = ui -> third-> text();
    four = ui -> four-> text();
    five = ui -> five-> text();
    sixth = ui -> sixth-> text();
    seventh = ui -> seventh-> text();

    if (!conn.connOpen()){
            qDebug()<<"база данных не открылась ";
            return;
        }
        conn.connOpen();
        QSqlQuery qry;
           qry.prepare("update Нечисть set id_Нечести='"+first+"',Тип_нечести='"+second+"',Цвет='"+third+"',Питание='"+four+"',Среда_обитания='"+five+"',Дата_обнаружения='"+sixth+"' ,Степень_опасности='"+seventh+"' where id_Нечести='"+first+"'");

        if (qry.exec())
        {
            QMessageBox::information(this,tr("Добавлено"),tr("сохранено"));
            conn.connClose();


        }
        else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}


void edit::on_pushButton_2_clicked()
{
    MainWindow conn;
    QString five, first, second, third, four, sixth, seventh;
    first = ui -> first-> text();
    second = ui -> second-> text();
    third = ui -> third-> text();
    four = ui -> four-> text();
    five = ui -> five-> text();
    sixth = ui -> sixth-> text();
    seventh = ui -> seventh-> text();

    if (!conn.connOpen()){
            qDebug()<<"база данных не открылась ";
            return;
        }
        conn.connOpen();
        QSqlQuery qry;
        qry.prepare("update Взаимодействие set id_Нечести='"+first+"',Дружба='"+second+"',Нейтралитет='"+third+"',Вражда='"+four+"' where id_Нечести='"+first+"'");

        if (qry.exec())
        {
            QMessageBox::information(this,tr("Добавлено"),tr("сохранено"));
            conn.connClose();


        }
        else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}
