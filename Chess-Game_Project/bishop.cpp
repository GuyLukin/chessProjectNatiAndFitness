#include "bishop.h"

Bishop::Bishop(Point source) : Piece(source)
{
}

bool Bishop::isValidMove(const Board& board, Point inputPoint)
{
    
        int dx = inputPoint.getX() - _currLocation.getX();
        int dy = inputPoint.getY() - _currLocation.getY();

        // Must move diagonally
        if (std::abs(dx) != std::abs(dy))
        {
            return false;
        }
        int stepX = (dx > 0) ? 1 : -1;
        int stepY = (dy > 0) ? 1 : -1;

        int x = _currLocation.getX() + stepX;
        int y = _currLocation.getY() + stepY;

        // Check path is clear
        while (x != inputPoint.getX() && y != inputPoint.getY())
        {
            if (board.getPieceAt(Point(x, y)) != nullptr)
                return false;

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
