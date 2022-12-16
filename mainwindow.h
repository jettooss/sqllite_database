#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include  "dialog1.h"
#include  "add.h"
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include "QtSql/QSqlDatabase"
#include "QSqlQuery"
#include <QtDebug>
#include <QFileInfo>
#include <QMessageBox>



#include "edit.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public:

    QSqlQueryModel * modal=new QSqlQueryModel();
    QSqlDatabase db;

    void dca();
    void connClose()
    {
        db.close();
        db.removeDatabase(QSqlDatabase::defaultConnection);
    }
//    void swou1()
    //    {
    //        QSqlQuery* qry1=new QSqlQuery(db);
    //        qry1->prepare("select * from Нечисть");
    //        qry1->exec();
    //        modal->setQuery(*qry1);
    ////        Ui->tableView1->setModel(modal);
    //////        qDebug()<<(modal->rowCount());
    //    }

    bool connOpen()
    {

        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("C:\\Users\\PC\\Desktop\\1\\BD.db");
        if(!db.open())
        {
            qDebug()<<("возникли проблемы с подключением БД");
            return false;
        }
        else {
            qDebug()<<("нет ошибок  с БД ");
            return true;
        }

    }


//        Qt::ItemFlags flags(const QModelIndex& index) const override;

//          Qt::ItemFlags flags(const QModelIndex& index) ;
private slots:
//    void on_add_clicked();







    void on_pushButton_4_clicked();


//    void on_tableView1_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_2_clicked();

    void on_tableView1_activated(const QModelIndex &index);

    void on_add_clicked();

private:

  Ui::MainWindow *ui;
    QSqlTableModel *model; //указатель на ...
    QString sd();


};
#endif // MAINWINDOW_H
