#include "scrolltext.h"

scrolltext::scrolltext(QWidget *parent) : QWidget(parent)
{
    textLable = new QLabel(this);

    textLable->setStyleSheet("QLabel {\
                             font-family: \"Microsoft YaHei\";\
                             font-size: 18px;\
                             color: red;\
                             font-style: normal;\
                             font-weight: bold;}");
    textLable->setText("This is scrolltext");
    textLable->setFixedHeight(20);
    textLable->hide();

    // 文字向上移动特效
    m_TopPropertyAnimatio = new QPropertyAnimation(this,"geometry");

    m_TopPropertyAnimatio->setDuration(600); // 制定动画时长

}


 void scrolltext::animationStart()
 {
     if(textLable->isHidden())
     {
         textLable->show();
     }
     // 前两个参数为坐标，后两个参数为长度和宽度 坐标系的朝向是朝右和朝下的
     // setStartValue是设置动画开始属性
     m_TopPropertyAnimatio->setStartValue(QRect(0,textLable->height(),textLable->width(),textLable->height()));
     m_TopPropertyAnimatio->setEndValue(QRect(0,0,textLable->width(),textLable->height()));
     // 通过setEasingCure设定动画的执行速度
     m_TopPropertyAnimatio->setEasingCurve(QEasingCurve::OutQuart);
     // 开始执行动画
     m_TopPropertyAnimatio->start(QAbstractAnimation::KeepWhenStopped);

     // 设置一个定时器，不让提示一直出现
     QTimer *timer = new QTimer(this);
     timer->start(3000);

     // 绑定定时器 并且实现下滑的效果
     connect(timer,&QTimer::timeout,this,[=]{
         m_TopPropertyAnimatio->setStartValue(QRect(0,0,textLable->width(),textLable->height()));
         m_TopPropertyAnimatio->setEndValue(QRect(0,textLable->height(),textLable->width(),textLable->height()));
         m_TopPropertyAnimatio->start(QAbstractAnimation::KeepWhenStopped);
         timer->stop();
         delete timer;
     });

 }
