#include "rook.h"
#include "Piece.h"
#include "Board.h"
#include <math.h>

Rook::Rook(Point firstLoc) : Piece(firstLoc)
{
}

std::string Rook::isValidMove(const Board& board, Point sourcePoint, Point destPoint)
{
    bool isValidTemp = false;
    std::string str_code = "";
    Point tempPointOne;
    Point tempPointTwo;
    int i = 0;
    /*
    if (!(sourcePoint == this->getLoc()))
    {
        str_code = "2";
    }
    */
    if ((*board.getPieceAt(destPoint)).getColor() == this->getColor())
    {
        str_code = "3";
    }
    /*
    else if (isCheck())
    {
        str_code = "4";
    }
    */
    else if ((sourcePoint.getX() < 0 || sourcePoint.getX() >= 8 || sourcePoint.getY() < 0 || sourcePoint.getY() >= 8) ||
        (destPoint.getX() < 0 || destPoint.getX() >= 8 || destPoint.getY() < 0 || destPoint.getY() >= 8))
    {
        str_code = "5";
    }
    else
    {
        Point tempPointTwo;
        tempPointOne.setX(sourcePoint.getX());
        tempPointTwo.setY(sourcePoint.getY());
        for (i = 0; i < 8; i++)
        {
            tempPointOne.setY(i);
            tempPointTwo.setX(i);
            if ((tempPointOne == destPoint) || (tempPointTwo == destPoint))
            {
                isValidTemp = true;
            }
        }
        if (!isValidTemp)
        {
            str_code = "6";
        }
    }
}