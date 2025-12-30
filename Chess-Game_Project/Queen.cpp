#include "queen.h"
#include "board.h"
#include <cmath>

Queen::Queen(Point source, std::string color) : Piece(source, color, false)
{
}

bool Queen::isValidMove(const Board& board, Point inputPoint)
{
    int currX = _currLocation.getX();
    int currY = _currLocation.getY();
    int destX = inputPoint.getX();
    int destY = inputPoint.getY();
    int dx = destX - currX;
    int dy = destY - currY;
    //cant move to the piece its already on
    if (dx == 0 && dy == 0)
    {
        return false;
    }
    if (!(dx == 0 || dy == 0 || std::abs(dx) == std::abs(dy)))
    {
        return false;
    }
    int stepX = (dx == 0) ? 0 : (dx > 0 ? 1 : -1);
    int stepY = (dy == 0) ? 0 : (dy > 0 ? 1 : -1);

    int x = currX + stepX;
    int y = currY + stepY;

    // Check path is clear (excluding destination)
    while (x != destX || y != destY)
    {
        if (board.getPieceAt(Point(x, y)) != nullptr)
        {
            return false;
        }
        x += stepX;
        y += stepY;
    }

    Piece* target = board.getPieceAt(inputPoint);

    // Empty square or enemy piece
    if (target == nullptr || target->getColor() != this->getColor())
    {
        return true;
    }

    return false;
}