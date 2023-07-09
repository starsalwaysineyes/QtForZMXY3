#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include<QKeyEvent>
#include<QDebug>
#include<mybox.h>
#include<mypushbutton.h>
QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT//引入qt信号的宏

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void moving();
    void movea();
    void moves();
    void movew();
    void moved();
    void keyPressEvent(QKeyEvent* event);
    void AddMyBox();



private:
    Ui::Widget *ui;

    int x1,y1,x2,y2;
    MyPushButton btn1;
    //MyBox box1;
    int cntBtns;
    int cntBoxes;
    MyPushButton *btns[16];
    MyBox *boxes[16];


};
#endif // WIDGET_H
