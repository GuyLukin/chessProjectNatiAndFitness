#include "Board.h"

Piece* (*Board::getBoard() const)[ROWS_SIZE]
{
    return (Piece * (*)[ROWS_SIZE])gameBoard;
}

Piece* Board::getPieceAt(const Point& p) const
{
    return getBoard()[p.getY()][p.getX()];
}

void Board::setPieceAt(const Point& p, Piece* piece)
{
    getBoard()[p.getY()][p.getX()] = piece;
}

bool Board::isCheck() const
{
    int i = 0;
    int j = 0;
    Point kingLoc;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (getBoard()[i][j]->isKing())
            {
                kingLoc.setX(i);
                kingLoc.setY(j);
            }
        }
    }
}