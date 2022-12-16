#include "add.h"
#include "ui_add.h"
#include <QMessageBox>
add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_pushButton_clicked()
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
            qry.prepare("insert into Нечисть(id_Нечести, Тип_нечести, Цвет,	Питание, Среда_обитания, Дата_обнаружения, Степень_опасности) values ('"+first+"', '"+second+"', '"+third+"', '"+four+"', '"+five+"', '"+sixth+"','"+seventh+"')");
          if (qry.exec())
          {
              QMessageBox::information(this,tr("Добавлено"),tr("сохранено"));
              conn.connClose();


          }
          else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}

void add::on_pushButton_2_clicked()
{
    MainWindow conn;

    QString five, first, second, third, four, sixth, seventh;
    first = ui -> first-> text();
    second = ui -> second-> text();
    third = ui -> third-> text();
    four = ui -> four-> text();
    five = ui -> five-> text();


    if (!conn.connOpen()){
            qDebug()<<"база данных не открылась ";
            return;
        }
        conn.connOpen();
        QSqlQuery qry;
            qry.prepare("insert into Взаимодействие(id_Нечести, Дружба,Нейтралитет, Вражда) values ('"+first+"', '"+second+"', '"+third+"', '"+four+"')");

        if (qry.exec())
        {
            QMessageBox::information(this,tr("Добавлено"),tr("сохранено"));
            conn.connClose();


        }
        else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
}
