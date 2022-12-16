#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);



};

MainWindow::~MainWindow()
{
    delete ui;
};
void MainWindow::dca()
{MainWindow conn;
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db);
    qry->prepare("select * from Нечисть");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView1->setModel(modal);

    conn.connClose();
    qDebug()<<(modal->rowCount());

}


void MainWindow::on_pushButton_4_clicked()
{
            this->hide();
            Dialog1 dialog1;
            dialog1.setModal(true);
            dialog1.exec();
}







void MainWindow::on_pushButton_5_clicked()
{
    dca();
}

void MainWindow::on_pushButton_2_clicked()
{

            add add;
            add.setModal(true);
            add.exec();
             dca();
}

void MainWindow::on_tableView1_activated(const QModelIndex &index)
{
     MainWindow conn;
    QString val=ui->tableView1->model()->data(index).toString();
    QSqlQueryModel * modal=new QSqlQueryModel();
    conn.connOpen();
    QSqlQuery* qry=new QSqlQuery(conn.db);
    qry->prepare("select * from Взаимодействие  where id_Нечести ='"+val+"'");
    qry->exec();
    modal->setQuery(*qry);
    ui->tableView->setModel(modal);
    if (!conn.connOpen()){
       qDebug()<<"база данных не открылась ";
       return;
      }
      conn.connOpen();
      QSqlQuery qry1;
      qry1.prepare("Delete from Нечисть where Тип_нечести='"+val+"'");
      if (qry1.exec())
      {
              conn.connClose();

       }
       else QMessageBox::critical(this,tr("ошибка"),qry1.lastError().text());
     dca();
}



void MainWindow::on_add_clicked()
{


                edit edit;
                edit.setModal(true);
                edit.exec();
                dca();
}
