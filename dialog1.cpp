#include "dialog1.h"
#include "ui_dialog1.h"
#include <QMessageBox>
MainWindow *w2;
Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
    MainWindow conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db);
    qry->prepare("select * from Взаимодействие");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView1->setModel(modal);
//      modal->setEditTriggers(QAbstractItemView::NoEditTriggers);
    conn.connClose();
    qDebug()<<(modal->rowCount());

}

Dialog1::~Dialog1()
{
    delete ui;
}

void Dialog1::on_add_clicked()
{
    MainWindow conn;
    QString id_nechisti, Friendship, Neutrality, Enmity;
    id_nechisti = ui -> id_nechisti-> text();
    Friendship = ui -> type-> text();
    Neutrality = ui -> color-> text();
    Enmity = ui -> eat-> text();


    qDebug() << id_nechisti; //вывод в консоль для проверки

    if (!conn.connOpen()){
            qDebug()<<"база данных не открылась ";
            return;
        }
        conn.connOpen();
    QSqlQuery qry; //request - запрос
    qry.prepare("insert into Взаимодействие(id_Нечести, Дружба,Нейтралитет, Вражда) values ('"+id_nechisti+"', '"+Friendship+"', '"+Neutrality+"', '"+Enmity+"')");
    if (qry.exec())
       {
           QMessageBox::critical(this,tr("Добавлено"),tr("сохранено"));
           conn.connClose();


       }
       else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry1=new QSqlQuery(conn.db);
    qry1->prepare("select * from Взаимодействие");
    qry1->exec();
    modal->setQuery(*qry1);
    ui->tableView1->setModel(modal);
    conn.connClose();
    qDebug()<<(modal->rowCount());
}

void Dialog1::on_pushButton_2_clicked()
{
    MainWindow conn;
    QString id_nechisti, Friendship, Neutrality, Enmity;
    id_nechisti = ui -> id_nechisti-> text();
    Friendship = ui -> type-> text();
    Neutrality = ui -> color-> text();
    Enmity = ui -> eat-> text();

    if (!conn.connOpen()){
            qDebug()<<"база данных не открылась ";
            return;
        }
        conn.connOpen();
        QSqlQuery qry;
        qry.prepare("update Взаимодействие set id_Нечести='"+id_nechisti+"',Дружба='"+Friendship+"',Нейтралитет='"+Neutrality+"',Вражда='"+Enmity+"' where id_Нечести='"+id_nechisti+"'");

        if (qry.exec())
        {
            QMessageBox::critical(this,tr("Добавлено"),tr("сохранено"));
            conn.connClose();


        }
        else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());
        QSqlQueryModel * modal=new QSqlQueryModel();
        conn.connOpen();
        QSqlQuery* qry1=new QSqlQuery(conn.db);
        qry1->prepare("select * from Взаимодействие");
        qry1->exec();
        modal->setQuery(*qry1);
        ui->tableView1->setModel(modal);
        conn.connClose();
        qDebug()<<(modal->rowCount());
}

void Dialog1::on_pushButton_clicked()
{
    MainWindow conn;
    QString id_nechisti;
    id_nechisti = ui -> lineEdit-> text();

     qDebug() << id_nechisti;
    if (!conn.connOpen()){
            qDebug()<<"база данных не открылась ";
            return;
        }
        conn.connOpen();
        QSqlQuery qry;
        qry.prepare("Delete from Взаимодействие where id_Нечести='"+id_nechisti+"'");
        if (qry.exec())
        {
            QMessageBox::critical(this,tr("Точно удалить?"),tr("Точно удалить?"));
            conn.connClose();


        }
        else QMessageBox::critical(this,tr("ошибка"),qry.lastError().text());

        QSqlQueryModel * modal=new QSqlQueryModel();
        conn.connOpen();
        QSqlQuery* qry1=new QSqlQuery(conn.db);
        qry1->prepare("select * from Взаимодействие");
        qry1->exec();
        modal->setQuery(*qry1);
        ui->tableView1->setModel(modal);
        conn.connClose();
        qDebug()<<(modal->rowCount());
}

void Dialog1::on_pushButton_4_clicked()
{
    w2 = new  MainWindow(this);
    w2->show();
}
