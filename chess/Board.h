#pragma once
#pragma once
#include <QWidget>
#include <QGridLayout>
#include "Square.h"


class Board : public QWidget {
public:
	Board(int width, int height, QWidget* parent = nullptr);
	~Board() = default;
	void updateBoard();
private:
	int row_ = 8;
	int col_ = 8;
	int width_;
	int height_;
	//Square* square;
	QGridLayout* grid_;
};