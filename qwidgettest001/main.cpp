#include "widget.h"

#include <QApplication>
#include<iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Widget w;//实例化widget

    w.show();

    return a.exec();
}
