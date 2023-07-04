#include "mybox.h"

MyBox::MyBox(QPushButton *parent) : QPushButton(parent)
{

    resize(100,100);
    setText("Box");

}

MyBox::MyBox(int x, int y, QPushButton *parent)
{
    resize(100,100);
    setParent(parent);
    setText("Box");
    move(x,y);
}
