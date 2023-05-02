#pragma once
#include <QLabel>
#include "Square.h"
using namespace std;

class Piece{
public:
    Piece() = default;
    ~Piece() = default;
    virtual int getValue();
protected:
    QString letter_;
    int value_;
    int width_;
    int height_;
};

class Rook : public Piece, public QLabel {
public:
    Rook(int width, int height, QWidget* parent = nullptr);
};