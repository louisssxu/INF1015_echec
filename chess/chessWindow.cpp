#include "chessWindow.h"
#include <QPushButton>



chessWindow::chessWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setFixedSize(900, 900);
    setStyleSheet("background-color: #202020;");

    Board *b = new Board(800, 800, this);
    b->updateBoard();

    /*QPushButton* b = new QPushButton(this);
    b->setStyleSheet("background-color: #202020;");*/


   


}

chessWindow::~chessWindow()
{}
