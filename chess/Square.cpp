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

	if (this->isTargeted_) {
		styleSheet += "border: 2px solid red; ";// outlined red
	}

	//this->isOccuped_ = false;
	this->setStyleSheet(styleSheet);
};


void Square::removePiece() {
	isOccuped_ = false;
	setIcon(QIcon());
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

bool Square::isTargeted() {
	return isTargeted_;
}

bool Square::isHighlighted() {
	return isHighlighted_;
}

bool Square::isNull() {
	return !(isOccuped_ || isTargeted_ || isHighlighted_);
}


pair<int, int> Square::getPosition() const {
	return { row_, col_ };
}

void Square::toggleTargeted() {
	isTargeted_ = !isTargeted_;
}

void Square::toggleHilighted() {
	isHighlighted_ = !isHighlighted_;
}

void Square::resetSquare() {
	isHighlighted_ = false;
	isTargeted_ = false;
}