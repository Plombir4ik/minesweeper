#include "mainwindow.h"
#include <QPushButton>
#include <QGridLayout>
#include <QMouseEvent>
#include <QDebug>
#include <QVector>
#include <QRandomGenerator>

MineSweeperWindow::MineSweeperWindow(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("Minesweeper");
    createGrid();
}

void MineSweeperWindow::createGrid()
{
    QGridLayout *gridLayout = new QGridLayout(this);
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    const int numRows = 10;
    const int numCols = 10;
    int num = 0;

    QVector<int> randomNumbers(15);

    for (int i = 0; i < 15; i++) {
        randomNumbers[i] = QRandomGenerator::global()->bounded(1, 101); // 1 <= number < 101
    }


    for (int row = 0; row < numRows; ++row) {

        for (int col = 0; col < numCols; ++col) {
            bool isBomb;
            if (randomNumbers.contains(num)) {
                isBomb = true;
            } else {
                isBomb = false;
            }

            num++;

            CustomButton *button = new CustomButton(col,row,isBomb,this);
            connect(button, &CustomButton::leftButtonClicked, this, &MineSweeperWindow::handleLeftButtonClicked);
            connect(button, &CustomButton::rightButtonClicked, this, &MineSweeperWindow::handleRightButtonClicked);
            button->setFixedSize(40, 40);
            button->setText(QString::number(row * numCols + col));
            if(isBomb)Buttons.append(button);
            gridLayout->addWidget(button, row, col);

        }
    }

    setLayout(gridLayout);
    setMaximumSize(400, 400);
}

void MineSweeperWindow::handleLeftButtonClicked(CustomButton *button)
{

}

void MineSweeperWindow::handleRightButtonClicked(CustomButton *button)
{
    button->setText("🚩");
    checkWin();

}

void MineSweeperWindow::checkWin()
{

}


