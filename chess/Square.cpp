#include "Square.h"
#include <QWidget>
#include <QLabel>

Square::Square(int row, int col, int width, int height) {
	row_ = row;
	col_ = col;
	width_ = width;
	height_ = height;

	setFixedSize(width_, height_);

	QString styleSheet = "";

	//Rook* label = new Rook(width_, height_, this);

	
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

void Square::setPieceIcon(string icon) {
	isOccuped_ = true;
	QPixmap pixmap(QString::fromStdString(icon));
	setIcon(pixmap);
	setIconSize(QSize(width_, height_));
}

bool Square::isOccuped() {
	return isOccuped_;
}

pair<int, int> Square::getPosition() const {
	return { row_, col_ };
}

void Square::setHilighted() {
	isHighlighted_ = !isHighlighted_;
}