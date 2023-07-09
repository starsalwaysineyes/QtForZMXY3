#include "mybox.h"

MyBox::MyBox(QWidget *parent) : QPushButton(parent)
{
    resize(100,100);
    //把box的大小设为100*100像素
    setText("Box");
    //设置文本内容
}

MyBox::MyBox(int x, int y, QWidget *parent):QPushButton(parent)
{//暂时用不到
    x/=100;
    y/=100;
    resize(100,100);
    setText("Box");
    move(x*100,y*100);
}
