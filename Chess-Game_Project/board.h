#pragma once
#include "Piece.h"
#include "Point.h"
#define ROWS_SIZE 8
class Board
{
private:
    Piece* gameBoard[ROWS_SIZE][ROWS_SIZE];

public:
    Board();
    ~Board();

    Piece* (*getBoard() const)[ROWS_SIZE];

    Piece* getPieceAt(const Point& p) const;
    void setPieceAt(const Point& p, Piece* piece);
    bool isCheck(std::string colorToCheck) const;
};
