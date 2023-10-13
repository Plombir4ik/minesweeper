#include <QApplication>
#include <QList>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    MineSweeperWindow window;
    window.show();

    return app.exec();
}
