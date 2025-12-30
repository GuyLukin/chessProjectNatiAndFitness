#include "rook.h"
#include "Piece.h"
#include "Board.h"
#include <math.h>

Rook::Rook(Point firstLoc, std::string color) : Piece(firstLoc, color, false)
{
}

bool Rook::isValidMove(const Board& board, Point destPoint)
{
    bool isValidTemp = false;
    bool isBlocked = false;
    Point tempPointOne;
    Point tempPointTwo;
    int i = 0;
    tempPointOne.setX(getLoc().getX());
    tempPointTwo.setY(getLoc().getY());
    for (i = 0; (i < 8)&&(!isBlocked); i++)
    {
        tempPointOne.setY(i);
        if (board.getPieceAt(tempPointOne) != nullptr)
        {
            isBlocked = true;
        }
        else if (tempPointOne == destPoint)
        {
            isValidTemp = true;
        }
    }
    for (i = 0; (i < 8) && (!isBlocked); i++)
    {
        tempPointTwo.setX(i);
        if (board.getPieceAt(tempPointOne) != nullptr)
        {
            isBlocked = true;
        }
        else if (tempPointOne == destPoint)
        {
            isValidTemp = true;
        }
    }
    return isValidTemp;
}