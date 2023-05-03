#include "Board.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>



Board::Board(int width, int height, QWidget *parent) : QWidget(parent), width_(width), height_(height) {

    setFixedSize(width_, height_);
 
    grid_ = new QGridLayout(this);
    for (int row = 0; row < row_; ++row) {
        for (int col = 0; col < col_; ++col) {
            Square* s = new Square(row, col, width_/ row_, height_/col_);

            grid_->addWidget(s, row, col);

            connect(s, SIGNAL(clicked()), this, SLOT(selectPiece()));
        }
    }

    initPieces();
}

void Board::updateBoard() {
    QLayoutItem* item;
    for (int row = 0; row < row_; ++row) {
        for (int col = 0; col < col_; ++col) {
            item = grid_->itemAtPosition(row, col);
            Square* s = (Square*)(item->widget());
            s->updateSquare();
        }
    }
}

/**************************** init Pieces *****************************/
// Methode permettant d'ajouter des pieces dans le chessboard
// modifier la methode lors de l'ajout de pieces
/**********************************************************************/
void Board::initPieces() {
    //ajouter les pieces necessaires
    Rook rook(1, 1, 0, 3);
    pieces_.push_back(make_unique<Rook>(rook));

    addPiecesOnBoard();
}

void Board::addPiecesOnBoard() {
    for (auto it = pieces_.begin(); it != pieces_.end(); it++) {
        Square* s = dynamic_cast<Square*>(grid_->itemAtPosition((*it)->getPosition().first, (*it)->getPosition().second)->widget());
        s->setPieceIcon((*it)->getPng());
    }
}

Piece* Board::findPieceAt(int row, int col) {
    auto it = find_if(pieces_.begin(), pieces_.end(), [&](const unique_ptr<Piece>& piece) {return (piece.get()->getPosition().first == row && piece.get()->getPosition().second == col);});
   if(it != pieces_.end())
    return (*it).get();
   return nullptr;
}

void Board::updateSquare(Piece* piece, Square* s) {
    if (piece->isValidMovement(s->getPosition().first, s->getPosition().second)) {
        s->setHilighted();
    }
}

void Board::selectPiece() {
    Square* selectedSquare = dynamic_cast<Square*>(sender());
    Piece* piece = findPieceAt(selectedSquare->getPosition().first, selectedSquare->getPosition().second);
    if (selectedSquare->isOccuped() && piece != nullptr) {
        for (int i = 0; i < row_; i++) {
            for (int j = 0; j < col_; j++) {
                Square* s = dynamic_cast<Square*>(grid_->itemAtPosition(i, j)->widget());
                updateSquare(piece, s);
                s->updateSquare();
            }
        }
    }
    selectedSquare->updateSquare();
}