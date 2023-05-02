#include "Piece.h"


int Piece::getValue() {
	return value_;
}

Rook::Rook(int width, int height, QWidget* parent) : QLabel(parent) {
	letter_ = "R";
	value_ = 8;
	width_ = width;
	height_ = height;

	setText(letter_);
	setFixedSize(width_, height_);
	setAlignment(Qt::AlignCenter);
}
