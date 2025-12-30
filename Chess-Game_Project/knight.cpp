#include "Knight.h"
#include "Board.h"
#include <cmath>
// Constructor
Knight::Knight(Point source,std::string color) : Piece(source, color, false)
{
}

/*function that checks if the move that was inputed is valid
* input:the board and where do you want to go
* output:is it valid or not
*/
bool Knight::isValidMove(const Board& board, Point inputPoint)
{
    int dx = std::abs(inputPoint.getX() - _currLocation.getX());
    int dy = std::abs(inputPoint.getY() - _currLocation.getY());

    // Knight moves in an L shape
    if (!((dx == 2 && dy == 1) || (dx == 1 && dy == 2)))
    {
        return false;
    }

    Piece* target = board.getPieceAt(inputPoint);

    // Can move to empty square or capture enemy piece
    if (target == nullptr || target->getColor() != this->getColor())
    {
        return true;
    }
    return false;
}