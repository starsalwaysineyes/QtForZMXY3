#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include<QPushButton>
class MyPushButton : public QPushButton
{//继承自QPushButton
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);

signals:

};

#endif // MYPUSHBUTTON_H
