#include "widget.h"
#include "ui_widget.h"
#include"mybox.h"
#include"mypushbutton.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    cntBtns=0;//暂时无用
    cntBoxes=0;


    setFixedSize(800,800);
    btn1.setParent(this);
    //box1.setParent(this);

    btn1.setText("AddBox");//按钮框中文本
    //box1.setText("Box");


    x1=100;
    y1=100;

    x2=300;
    y2=300;

    btn1.move(100,100);//定义按钮的位置
    btn1.resize(100,100);

    //box1.move(300,300);//定义按钮的位置
    //box1.resize(100,100);

    connect(&btn1,&MyPushButton::pressed,this,&Widget::AddMyBox);
    //将btn1的被按下这个事件与addmybox函数关联

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::moving()
{//无用
    btn1.move(400,400);
}

void Widget::movea()
{//四个主要移动事件

    if(x1>=100)
        x1-=100;
    else
        x1=700;
    if(y1==y2 && x1==x2)
    {
        x2-=100;
        if(x2<0)
            x2=700;
    }
    if(cntBoxes>=1)
        boxes[0]->move(x2,y2);
    btn1.move(x1,y1);
}
void Widget::moves()
{
    if(y1<700)
        y1+=100;
    else
        y1=0;
    if(y1==y2 && x1==x2)
    {
        y2+=100;
        if(y2>700)
            y2=0;
    }

    if(cntBoxes>=1)
        boxes[0]->move(x2,y2);
    btn1.move(x1,y1);
}
void Widget::movew()
{
    if(y1>=100)
        y1-=100;
    else
        y1=700;
    if(y1==y2 && x1==x2)
    {
        y2-=100;
        if(y2<0)
            y2=700;
    }

    if(cntBoxes>=1)
        boxes[0]->move(x2,y2);
    btn1.move(x1,y1);
}
void Widget::moved()
{
    if(x1<700)
        x1+=100;
    else
        x1=0;
    if(y1==y2 && x1==x2)
    {
        x2+=100;
        if(x2>700)
            x2=0;
    }

    if(cntBoxes>=1)
        boxes[0]->move(x2,y2);
    btn1.move(x1,y1);
}

void Widget::keyPressEvent(QKeyEvent *event)
{//设置窗口内的键盘事件
    switch(event->key())
    {
        case Qt::Key_A :
            movea();
            break;
        case Qt::Key_S:
            moves();
            break;
        case Qt::Key_W:
            movew();
            break;
        case Qt::Key_D:
            moved();
            break;
    };
}

void Widget::AddMyBox()
{
    //boxes[0]=new MyBox(this);
    boxes[cntBoxes]=new MyBox(this);
    x2=100;
    y2=100;
    boxes[cntBoxes]->resize(100,100);
    boxes[cntBoxes]->move(100,100);
    boxes[cntBoxes]->setParent(this);
    boxes[cntBoxes]->show();
    cntBoxes++;
}




