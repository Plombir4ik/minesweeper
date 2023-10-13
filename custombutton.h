#ifndef CUSTOMBUTTON_H
#define CUSTOMBUTTON_H

#include <QPushButton>

class CustomButton : public QPushButton
{
    Q_OBJECT

public:
    CustomButton(int x, int y, bool isBomb, QWidget *parent = nullptr);

    int getX();
    int getY();
    bool getIsBomb();
    bool getIsMarked();
    void setIsMarked(bool a);

signals:
    void leftButtonClicked(CustomButton *button);
    void rightButtonClicked(CustomButton *button);

protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    int x;
    int y;
    bool isBomb;
    bool IsMarked = false;
};

#endif // CUSTOMBUTTON_H
