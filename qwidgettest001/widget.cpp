#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    setFixedSize(800,800);


    button1.setParent(this);//绑定窗口和按钮
    button1.setText("Close");//按钮框中文本

    button2.setText("Box");
    button2.setParent(this);



    x1=100;
    y1=100;

    x2=300;
    y2=300;

    button1.move(100,100);//定义按钮的位置
    button1.resize(100,100);

    button2.move(300,300);//定义按钮的位置
    button2.resize(100,100);


    connect(&button1,&QPushButton::pressed,this,&Widget::close);

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::moving()
{
    button1.move(400,400);

}

void Widget::movea()
{
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

    button2.move(x2,y2);
    button1.move(x1,y1);
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

    button2.move(x2,y2);
    button1.move(x1,y1);
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

    button2.move(x2,y2);
    button1.move(x1,y1);
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

    button2.move(x2,y2);
    button1.move(x1,y1);
}

void Widget::keyPressEvent(QKeyEvent *event)
{
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


