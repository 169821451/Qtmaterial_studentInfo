#include "materialtest.h"
#include "ui_materialtest.h"

materialTest::materialTest(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::materialTest)
{
    ui->setupUi(this);

    //test = new QtMaterialToggle(this);

    //test->setGeometry(200,200,96,48);
    this->setWindowTitle(u8"学生信息管理系统 V1.0 By:xbckt");

    // 设置tab头
    ui->tabWidget->setTabText(0,u8"学生信息录入");
    ui->tabWidget->setTabText(1,u8"学生信息查询");
    ui->tabWidget->setTabText(2,u8"学生成绩录入");
    ui->tabWidget->setTabText(3,u8"学生成绩查询");

    // 设置信息录入栏lineedit输入限制
    // 限制只能输入数字
    ui->lineEdit_xh->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_tel->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_age->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_sx->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_yw->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));
    ui->lineEdit_yy->setValidator(new QRegExpValidator(QRegExp("[0-9]+$")));





}

materialTest::~materialTest()
{
    delete ui;
}

void materialTest::on_pushButton_clicked()
{
    // 往变量里面存取数据
    Input_Age = ui->lineEdit_age->text().toInt();
    Input_Yuwen = ui->lineEdit_yw->text().toInt();
    Input_Math = ui->lineEdit_sx->text().toInt();
    Input_English = ui->lineEdit_yy->text().toInt();
    Input_Tel = ui->lineEdit_tel->text().toInt();
    Input_Xuehao = ui->lineEdit_xh->text().toInt();

    Input_Addr = ui->lineEdit_home->text();
    Input_Name = ui->lineEdit_name->text();
    Input_Sex = ui->comboBox_sex->currentText();
    Input_Zhuanye = ui->comboBox_zhuanye->currentText();
    Input_Class = ui->lineEdit_class->text();

    // sql语句
    QString sql = QString("insert into studentInfo(name,xuehao,age,tel,addr,sex,zhuanye,class,yuwen,math,english) "
                          "values('%1','%2','%3','%4','%5','%6','%7','%8','%9','%10','%11')")
            .arg(Input_Name).arg(Input_Xuehao).arg(Input_Age).arg(Input_Tel).arg(Input_Addr).arg(Input_Sex)
            .arg(Input_Zhuanye).arg(Input_Class).arg(Input_Yuwen).arg(Input_Math).arg(Input_English);

    // 写入数据
    m_Snackbar = new QtMaterialSnackbar(this);
    QSqlQuery q;
    if(q.exec(sql))
    {
        QString sucess = u8"信息录入成功";
        m_Snackbar->addMessage(sucess); // 设置显示文本
        m_Snackbar->setGeometry(325,500,150,50); // 设置坐标位置及大小，前两个参数为坐标，后两个参数为大小
        m_Snackbar->setFontSize(15); // 设置文本大小
        m_Snackbar->show(); // 显示控件
    }
    else {
        QString defalse = u8"信息录入失败";
        m_Snackbar->addMessage(defalse); // 设置显示文本
        m_Snackbar->setGeometry(325,500,150,50); // 设置坐标位置及大小，前两个参数为坐标，后两个参数为大小
        m_Snackbar->setFontSize(15); // 设置文本大小
        m_Snackbar->show(); // 显示控件
    }


}
