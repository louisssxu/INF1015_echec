#pragma once
#include <QWidget>
#include <qpushbutton.h>

using namespace std;

class Square : public QPushButton {
public:
	Square(int row, int col, int width, int height);
	~Square() = default;
	void updateSquare();
	void selected();
	void targeted(); // missing
	void setPieceIcon(string icon);
	bool isOccuped();
	pair<int, int> getPosition() const;
	void setHilighted();


private:
	bool isHighlighted_ = false;
	bool isTargeted_ = false;
	bool isOccuped_ = false;
	int row_;
	int col_;
	int width_;
	int height_;
};
