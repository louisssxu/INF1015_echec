#include "Piece.h"


int Piece::getValue() {
	return value_;
}

pair<int, int> Piece::getPosition() {
	return currentPosition;
}

string Piece::getPng() {
	return adressPng_;
}

Rook::Rook(int width, int height, int x, int y) {
	//letter_ = "R";
	value_ = 8;
	width_ = width;
	height_ = height;
	currentPosition = { x, y };
	adressPng_ = "b_rook.png";

	//setText(letter_);
	//setFixedSize(width_, height_);
	//setAlignment(Qt::AlignCenter);
}

bool Rook::isValidMovement(int x, int y) const {
	if (x <= currentPosition.first + 1 && y <= currentPosition.second + 1 && x >= currentPosition.first - 1 && y >= currentPosition.second - 1) {
		//deplacement diagonal valide
		return true;
	}
	return false;
}