#include "widget.h"

#include <QApplication>
#include<iostream>
int main(int argc, char *argv[])
{



	//123123123123
    QApplication a(argc, argv);
    Widget w;
        //123123

//    w.move(1200,800);
//    w.resize(800,600);


//    w.setWindowTitle("设置窗口标题");
//    w.setFixedSize(800,600);
//    w.setFixedWidth(800);
//    w.setFixedHeight(600);//优先级大于setgeometry

//    //同时设置窗口的位置和大小
//    w.setGeometry(1200,800,2000,1600);


    w.show();

//tt
    //std::cout<<"123"<<std::endl;
    return a.exec();
}
