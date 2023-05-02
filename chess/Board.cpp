#include "Board.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>



Board::Board(int width, int height, QWidget *parent) : QWidget(parent), width_(width), height_(height) {

    setFixedSize(width_, height_);
 
    grid_ = new QGridLayout(this);
    for (int row = 0; row < row_; ++row) {
        for (int col = 0; col < col_; ++col) {
            Square* s = new Square(row, col, width_/ row_, height_/col_, this);

            grid_->addWidget(s, row, col);
        }
    }
}

void Board::updateBoard() {
    QLayoutItem* item;
    for (int row = 0; row < row_; ++row) {
        for (int col = 0; col < col_; ++col) {
            item = grid_->itemAtPosition(row, col);
            Square* s = (Square*)(item->widget());
            s->updateSquare();
        }
    }
}

