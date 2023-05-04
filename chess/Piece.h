#pragma once
#include <QObject>
#include <memory>
#include "Square.h"
using namespace std;

class Piece {
public:
    Piece() = default;
    ~Piece() = default;
    virtual int getValue();
    pair<int, int> getPosition();
    string getPng();
    virtual bool isValidMovement(int x, int y) const = 0;
    void setPosition(int row, int col);
protected:
    //QString letter_;
    int value_;
    int width_;
    int height_;
    pair<int, int> currentPosition;
    string adressPng_;
};

class Rook : public Piece {
public:
    Rook(int width, int height, int x, int y, char color);
    bool isValidMovement(int x, int y) const;
};