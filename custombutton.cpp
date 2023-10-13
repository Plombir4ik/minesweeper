#include "custombutton.h"
#include <QMouseEvent>
#include <QDebug>

CustomButton::CustomButton(int x, int y, bool isBomb, QWidget *parent) : QPushButton(parent), x(x), y(y), isBomb(isBomb)
{

}

int CustomButton::getX()
{
    return x;
}

int CustomButton::getY()
{
    return y;
}

bool CustomButton::getIsBomb()
{
    return isBomb;
}

bool CustomButton::getIsMarked()
{
    return isBomb;
}

void CustomButton::setIsMarked(bool a)
{
    this->isBomb = a;
}

void CustomButton::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        emit leftButtonClicked(this);
    }
    else if (event->button() == Qt::RightButton)
    {
        emit rightButtonClicked(this);
    }

    QPushButton::mousePressEvent(event);
}

