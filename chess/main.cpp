#include "chessWindow.h"
#include <QtWidgets/QApplication>
#include <QPushButton>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    chessWindow w;
    w.show();



    return app.exec();
}
