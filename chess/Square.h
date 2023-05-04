#pragma once
#include <QWidget>
#include <qpushbutton.h>

using namespace std;

class Square : public QPushButton {
public:
	Square(int row, int col, int width, int height);
	~Square() = default;
	void updateSquare();
	void setPieceIcon(string icon);
	void removePiece();
	bool isOccuped();
	bool isHighlighted();
	bool isTargeted();
	bool isNull();
	pair<int, int> getPosition() const;
	void toggleTargeted();
	void toggleHilighted();
	void resetSquare();


private:
	bool isHighlighted_ = false;
	bool isTargeted_ = false;
	bool isOccuped_ = false;
	int row_;
	int col_;
	int width_;
	int height_;
};