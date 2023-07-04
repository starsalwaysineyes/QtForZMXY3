#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include<QKeyEvent>
#include<QDebug>

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

private:
    Ui::Widget *ui;
    QPushButton button1;
    QPushButton button2;
    int x1,x2;
    int y1,y2;

};
#endif // WIDGET_H
