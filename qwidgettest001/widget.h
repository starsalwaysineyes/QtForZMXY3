#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include<QKeyEvent>
#include<QDebug>
#include<mybox.h>
#include<mypushbutton.h>
#include<QMap>
#include<QPair>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT//引入qt信号的宏

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void movea(char c);

    void keyPressEvent(QKeyEvent* event);
    void AddMyBox();



private:
    Ui::Widget *ui;
    //初始坐标
    int x1,y1,x2,y2;

    //二维数组
    int arr[8][8];

    //btn1
    MyPushButton btn1;

    //map字典对，key为char，value为pair
    QMap<char,QPair<int,int>> mp;

    //box的数量
    int cntBoxes;

    //初始化16个指向box的指针
    MyBox *boxes[16];


};
#endif // WIDGET_H
