#ifndef SCROLLTEXT_H
#define SCROLLTEXT_H

#include <QWidget>
#include <QLabel>
#include <QGridLayout>
#include <QPropertyAnimation>  // QT的动画类
#include <QGraphicsObject>
#include <QTime>
#include <QTimer>

/*
 * 此文件是写提示的动态效果
 *
 *
 * */

class scrolltext : public QWidget
{
    Q_OBJECT
public:
    explicit scrolltext(QWidget *parent = nullptr);
    // 通过label实现
    QLabel *textLable;

    // 定义一个动画开始的函数
    void animationStart();

private:
    QPropertyAnimation *m_TopPropertyAnimatio;

signals:

public slots:
};

#endif // SCROLLTEXT_H
