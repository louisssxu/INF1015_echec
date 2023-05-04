#include "Board.h"
#include <QWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <vector>



Board::Board(int width, int height, QWidget* parent) : QWidget(parent), width_(width), height_(height) {

    setFixedSize(width_, height_);

    grid_ = new QGridLayout(this);
    for (int row = 0; row < row_; ++row) {
        for (int col = 0; col < col_; ++col) {
            Square* s = new Square(row, col, width_ / row_, height_ / col_);

            grid_->addWidget(s, row, col);

            connect(s, SIGNAL(clicked()), this, SLOT(selectSquare()));
        }
    }

    initPieces();
}

void Board::updateBoard() {
    QLayoutItem* item;

    //updateSquare
    for (int row = 0; row < row_; ++row) {
        for (int col = 0; col < col_; ++col) {
            item = grid_->itemAtPosition(row, col);
            Square* s = (Square*)(item->widget());
            s->updateSquare();
            s->removePiece();
        }
    }

    // setPieceIcon
    for (auto it = pieces_.begin(); it != pieces_.end(); it++) {
        Square* s = dynamic_cast<Square*>(grid_->itemAtPosition((*it)->getPosition().first, (*it)->getPosition().second)->widget());
        s->setPieceIcon((*it)->getPng());
    }
}

void Board::resetSquares() {
    QLayoutItem* item;

    //resetSquare
    for (int row = 0; row < row_; ++row) {
        for (int col = 0; col < col_; ++col) {
            item = grid_->itemAtPosition(row, col);
            Square* s = (Square*)(item->widget());
            s->resetSquare();
        }
    }
}

/**************************** init Pieces *****************************/
// Methode permettant d'ajouter des pieces dans le chessboard
// modifier la methode lors de l'ajout de pieces
/**********************************************************************/
void Board::initPieces() {
    //ajouter les pieces necessaires
    Rook rook(1, 1, 2, 3, 'b');
    pieces_.push_back(make_unique<Rook>(rook));
    Rook rook_w(1, 1, 1, 3, 'w');
    pieces_.push_back(make_unique<Rook>(rook_w));

    //addPiecesOnBoard();
}

// cause des bug
//void Board::removePiece(Piece* p) {
//    auto it = find_if(pieces_.begin(), pieces_.end(), [=](Piece* piece) {return (piece->getPosition().first == p->getPosition().first && piece->getPosition().second == p->getPosition().second); });
//    pieces_.erase(remove_if(pieces_.begin(), pieces_.end(), [=](Piece* piece) {return (p == piece); }), pieces_.end());
//}


Piece* Board::getPieceAt(int row, int col) {
    auto it = find_if(pieces_.begin(), pieces_.end(), [&](const unique_ptr<Piece>& piece) {return (piece.get()->getPosition().first == row && piece.get()->getPosition().second == col);});
    if (it != pieces_.end())
        return (*it).get();
    return nullptr;
}

void Board::targetValidMovements(Piece* piece, Square* s) {
    if (piece->isValidMovement(s->getPosition().first, s->getPosition().second)) {
        s->toggleTargeted();
    }
}

void Board::selectPiece(Piece* piece) {
    resetSquares();
    for (int i = 0; i < row_; i++) {
        for (int j = 0; j < col_; j++) {
            Square* s = dynamic_cast<Square*>(grid_->itemAtPosition(i, j)->widget());
            if (piece->getPosition().first == i && piece->getPosition().second == j) {
                s->toggleHilighted();
                continue;
            }
            targetValidMovements(piece, s);
        }
    }
}

void Board::movePiece(Piece* piece, Square* newSquare) {
    piece->setPosition(newSquare->getPosition().first, newSquare->getPosition().second);
}

void Board::selectSquare() {
    Square* newSelectedSquare = dynamic_cast<Square*>(sender());




    //moving / capture
    if (newSelectedSquare->isTargeted()) {
        Piece* piece = getPieceAt(selectedSquare_->getPosition().first, selectedSquare_->getPosition().second);

        if (newSelectedSquare->isOccuped()) { // capture
            Piece* prey = getPieceAt(newSelectedSquare->getPosition().first, newSelectedSquare->getPosition().second);
            // test
            selectedSquare_ == nullptr;
            resetSquares();
        }
        else { // move
            movePiece(piece, newSelectedSquare);
        }
        selectedSquare_ == nullptr;
        resetSquares();
        updateBoard();
        return;
    }

    //null reset
    if (newSelectedSquare->isNull()) {
        selectedSquare_ == nullptr;
        resetSquares();
        updateBoard();
        return;
    }


    // select
    if (newSelectedSquare->isOccuped()) { //&& piece != nullptr) {
        Piece* piece = getPieceAt(newSelectedSquare->getPosition().first, newSelectedSquare->getPosition().second);
        selectPiece(piece);
        selectedSquare_ = newSelectedSquare;
        updateBoard();
        return;
    }

    updateBoard();
}