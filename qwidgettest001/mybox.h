#ifndef MYBOX_H
#define MYBOX_H

#include <QWidget>
#include<QPushButton>
class MyBox : public QPushButton
{
    Q_OBJECT
public:
    explicit MyBox(QWidget *parent = nullptr);

private:
    //int x,y;
signals:

};

#endif // MYBOX_H
