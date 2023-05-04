#pragma once
#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QtWidgets>
#include "Square.h"
#include "Piece.h"
#include <vector>


class Board : public QWidget {

	Q_OBJECT

public:
	Board(int width, int height, QWidget* parent = nullptr);
	~Board() = default;
	void updateBoard();
	void resetSquares();
	void selectPiece(Piece* piece);
	void movePiece(Piece* piece, Square* newSquare);
private:
	void initPieces();
	void removePiece(Piece* piece);
	void addPiecesOnBoard();
	Piece* getPieceAt(int row, int col);
	void targetValidMovements(Piece* piece, Square* s);
	int row_ = 8;
	int col_ = 8;
	int width_;
	int height_;
	vector<unique_ptr<Piece>> pieces_;
	Square* selectedSquare_ = nullptr;
	//Square* square;
	QGridLayout* grid_;

public slots:
	void selectSquare();
};