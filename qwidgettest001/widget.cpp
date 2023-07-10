#include "widget.h"
#include "ui_widget.h"
#include"mybox.h"
#include"mypushbutton.h"
#include<QString>
#include<QVector>
#include<QPair>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    mp['A']=qMakePair(-1,0);
    mp['S']=qMakePair(0,1);
    mp['W']=qMakePair(0,-1);
    mp['D']=qMakePair(1,0);

    //初始化arr数组
    memset(arr,0,sizeof(arr));

    //初始化box的个数
    cntBoxes=0;

    //设置主窗口大小固定位800*800
    setFixedSize(800,800);

    //设置按钮的父窗口位当前widget
    btn1.setParent(this);

    //设置按钮框中文本
    btn1.setText("AddBox");

    //初始化btn1的位置
    x1=100;
    y1=100;

    //标记1,1处为btn1,用-1标记
    arr[1][1]=-1;

    //定义按钮的位置
    btn1.move(x1,y1);

    //设置btn1的大小为100*100
    btn1.resize(100,100);

    //将btn1的被按下这个事件与addmybox函数关联
    connect(&btn1,&MyPushButton::pressed,this,&Widget::AddMyBox);

    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}


void Widget::movea(char c)
{//四个主要移动事件

    if(arr[(8+x1/100+mp[c].first)%8][(8+y1/100+mp[c].second)%8]==0)
    {//无阻碍
        btn1.move((8+x1/100+mp[c].first)%8*100,(8+y1/100+mp[c].second)%8*100);
        arr[(8+x1/100+mp[c].first)%8][(8+y1/100+mp[c].second)%8]=-1;
        arr[x1/100][y1/100]=0;
        x1=(8+x1/100+mp[c].first)%8*100;
        y1=(8+y1/100+mp[c].second)%8*100;
        return;
    }

    if(arr[(8+x1/100+2*mp[c].first)%8][(8+y1/100+2*mp[c].second)%8]==0)
    {//单个，可推
        boxes[arr[(8+x1/100+mp[c].first)%8][(8+y1/100+mp[c].second)%8]-1]\
                ->move((8+x1/100+2*mp[c].first)%8*100,(8+y1/100+2*mp[c].second)%8*100);
        btn1.move((8+x1/100+mp[c].first)%8*100,(8+y1/100+mp[c].second)%8*100);
        arr[(8+x1/100+2*mp[c].first)%8][(8+y1/100+2*mp[c].second)%8]=\
                arr[(8+x1/100+mp[c].first)%8][(8+y1/100+mp[c].second)%8];
        arr[(8+x1/100+mp[c].first)%8][(8+y1/100+mp[c].second)%8]=-1;
        arr[x1/100][y1/100]=0;
        x1=(8+x1/100+mp[c].first)%8*100;
        y1=(8+y1/100+mp[c].second)%8*100;
        return;
    }

}

void Widget::keyPressEvent(QKeyEvent *event)
{//设置窗口内的键盘事件
    switch(event->key())
    {
        case Qt::Key_A :
            movea('A');
            break;
        case Qt::Key_S:
            movea('S');
            break;
        case Qt::Key_W:
            movea('W');
            break;
        case Qt::Key_D:
            movea('D');
            break;
    };
}

void Widget::AddMyBox()
{
    if(cntBoxes==16)return;
    //此处在构造函数中已经设定了大小和父窗口为this

    char c[4]={'D','S','A','W'};

    //设置box名字的前缀,这里当cnt为0时，编号为1
    QString name="Box-";
    name+=char((cntBoxes+1)/10+'0');
    name+=char((cntBoxes+1)%10+'0');

    for(int i=0;i<4;i++)
    {//遍历“右下左上”四个反向，判断是否有空位
        if(arr[(8+x1/100+mp[c[i]].first)%8][(8+y1/100+mp[c[i]].second)%8]==0)//没有方块阻挡
        {
            //实例化box
            boxes[cntBoxes]=new MyBox(this);
            //为box设置名字
            boxes[cntBoxes]->setText(name);

            //将box移动到指定位置
            boxes[cntBoxes]->move((8+x1/100+mp[c[i]].first)%8*100,(8+y1/100+mp[c[i]].second)%8*100);

            //记录该box的编号到arr中
            arr[(8+x1/100+mp[c[i]].first)%8][(8+y1/100+mp[c[i]].second)%8]=cntBoxes+1;

            //将box设置为可见
            boxes[cntBoxes]->show();

            cntBoxes++;
            break;
        }
    }
}




