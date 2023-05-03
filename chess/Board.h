#pragma once
#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QtWidgets>
#include "Square.h"
#include "Piece.h"


class Board : public QWidget {

	Q_OBJECT

public:
	Board(int width, int height, QWidget* parent = nullptr);
	~Board() = default;
	void updateBoard();
private:
	void initPieces();
	void addPiecesOnBoard();
	Piece* findPieceAt(int row, int col);
	void updateSquare(Piece* piece, Square* s);
	int row_ = 8;
	int col_ = 8;
	int width_;
	int height_;
	vector<unique_ptr<Piece>> pieces_;
	//Square* square;
	QGridLayout* grid_;
	
public slots:
	void selectPiece();
};