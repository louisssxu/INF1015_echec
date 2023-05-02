#pragma once
#include <QWidget>

#include "Piece.h"
using namespace std;

class Square : public QWidget {
public:
	Square(int row, int col, int width, int height, QWidget* parent = 0);
	~Square() = default;
	void updateSquare();
	void selected();
	void targeted(); // missing


private:
	bool isHighlighted_ = false;
	bool isTargeted_ = false;
	int row_;
	int col_;
	int width_;
	int height_;
	//Piece* piece_;
};
