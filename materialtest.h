#ifndef MATERIALTEST_H
#define MATERIALTEST_H

#include <QMainWindow>
#include <qtmaterialtabs.h>
#include <QVBoxLayout>
#include <QColorDialog>
#include <QSqlQuery>
#include <QDebug>
#include <qtmaterialsnackbar.h>

namespace Ui {
class materialTest;
}

class materialTest : public QMainWindow
{
    Q_OBJECT

public:
    explicit materialTest(QWidget *parent = nullptr);
    ~materialTest();

    // 保存输入信息的变量
    // 数字类型
    int Input_Age;
    int Input_Yuwen;
    int Input_English;
    int Input_Math;
    int Input_Tel;
    int Input_Xuehao;
    // 文字信息
    QString Input_Addr;
    QString Input_Name;
    QString Input_Sex;
    QString Input_Zhuanye;
    QString Input_Class;

    // 提示框
    QtMaterialSnackbar *m_Snackbar;








private slots:
    void on_pushButton_clicked();

private:
    Ui::materialTest *ui;
};

#endif // MATERIALTEST_H
