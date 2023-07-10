#include "mybox.h"

MyBox::MyBox(QWidget *parent) : QPushButton(parent)
{
    resize(100,100);
    //把box的大小设为100*100像素
    setParent(parent);
    setText("Box");
    //设置文本内容
}


