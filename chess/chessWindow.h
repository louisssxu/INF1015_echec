#pragma once

#include <QtWidgets/QMainWindow>
#include "Board.h"
#include "ui_chess.h"

class chessWindow : public QMainWindow
{
    Q_OBJECT

public:
    chessWindow(QWidget *parent = nullptr);
    ~chessWindow();

private:
    Ui::chessClass ui;
};
