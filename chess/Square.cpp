#include "Square.h"
#include <QWidget>
#include <QLabel>

Square::Square(int row, int col, int width, int height, QWidget* parent) : QWidget(parent) {
	row_ = row;
	col_ = col;
	width_ = width;
	height_ = height;

	setFixedSize(width_, height_);

	QString styleSheet = "";

	Rook* label = new Rook(width_, height_, this);

	
	if ((row_ + col_) % 2 == 0) {
		styleSheet += "background-color: #eeeed2; "; //cream color
	}
	else {
		styleSheet += "background-color: #769656; "; //green color
	}

	setStyleSheet(styleSheet);
}

void Square::updateSquare() {
	QString styleSheet = "";

	if ((this->row_ + this->col_) % 2 == 0) {
		if (this->isHighlighted_) {
			styleSheet += "background-color: #F7F769; "; //cream highlighted
		}
		else {
			styleSheet += "background-color: #eeeed2; "; //cream color
		}
		
	}
	else {
		if (this->isHighlighted_) {
			styleSheet += "background-color: #BBCB2B; ";    //green highlighted
		}
		else {
			styleSheet += "background-color: #769656; "; //green color
		}
		
	}

	this->setStyleSheet(styleSheet);
};


void Square::selected() {
	if (isHighlighted_) {
		isHighlighted_ = false;
	}
	else {
		isHighlighted_ = true;
	}
}
