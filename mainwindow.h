#ifndef MINESWEEPERWINDOW_H
#define MINESWEEPERWINDOW_H

#include <QWidget>
#include <QPushButton>
#include "custombutton.h"


class MineSweeperWindow : public QWidget
{
    Q_OBJECT



public:
    explicit MineSweeperWindow(QWidget *parent = nullptr);
    QList<CustomButton*>Buttons;
    void createGrid();
    void checkWin();


public slots:
    void handleLeftButtonClicked(CustomButton *button);
    void handleRightButtonClicked(CustomButton *button);

protected:

};

#endif // MINESWEEPERWINDOW_H
