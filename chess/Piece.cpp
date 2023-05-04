#include "Piece.h"


int Piece::getValue() {
	return value_;
}

void Piece::setPosition(int row, int col) {
	currentPosition = { row, col };
}

pair<int, int> Piece::getPosition() {
	return currentPosition;
}

string Piece::getPng() {
	return adressPng_;
}

Rook::Rook(int width, int height, int x, int y, char color) {
	//letter_ = "R";
	value_ = 8;
	width_ = width;
	height_ = height;
	currentPosition = { x, y };

	if (color == 'b') {
		adressPng_ = "b_rook.png";
	}
	else if (color == 'w') {
		adressPng_ = "w_rook.png";
	}
	else {
		adressPng_ = "w_rook.png"; // a changer erreur
	}
}

bool isCroiceMovement(int x_p, int y_p, int x, int y) {
	if (x_p == x || y_p == y) { return true; }
	return false;
}

bool isNearMovement(int x_p, int y_p, int x, int y) {
	if (x <= x_p + 1 && y <= y_p + 1 && x >= x_p - 1 && y >= y_p - 1) {
		return true;
	}
	return false;
}

bool Rook::isValidMovement(int x, int y) const {
	return isCroiceMovement(currentPosition.first, currentPosition.second, x, y);
}