#include "materialtest.h"
#include <QApplication>
#include "framelessWidget.h"
#include <QDialog>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QDebug>
#include <QSqlError>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);



    QSqlDatabase db=QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("101.42.25.110");
    db.setPort(3306);
    db.setDatabaseName("cxkj");
    db.setUserName("root");
    db.setPassword("123456");
    bool ok=db.open();
    if(ok)
    {
       qDebug()<<u8"数据库连接成功！";
    }
    else {

       qDebug()<<u8"连接失败，错误信息："<<db.lastError().text();
       return -1;
    }

    //materialTest w;

    framelessWidget mainWindow;

    mainWindow.setWindowFlag(Qt::FramelessWindowHint);
    mainWindow.setAttribute(Qt::WA_TranslucentBackground);
    mainWindow.show();

    return a.exec();


}
