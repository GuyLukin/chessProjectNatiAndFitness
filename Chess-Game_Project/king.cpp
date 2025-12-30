#include "king.h"
#include "king.h"
#include "King.h"
#include "Board.h"
#include <cmath>
//a constructor for king
//input: none
//output
King::King(Point source,std::string color) : Piece(source, color, true)
{
}
/*function that checks what square can the king go to
 input:the board and the point you want to go to
* output:if you can go there or not
*/
bool King::isValidMove(const Board& board, Point inputPoint) 
{
    int dx = std::abs(inputPoint.getX() - _currLocation.getX());
    int dy = std::abs(inputPoint.getY() - _currLocation.getY());

    if (dx > 1 || dy > 1 || (dx == 0 && dy == 0))//the  king can only mive one square in each direction
    {
        return false;
    }
    Piece* target = board.getPieceAt(inputPoint);

    // Empty square or enemy piece
    if (target == nullptr || target->getColor() != this->getColor())
    {
        return true;
    }
    return false;
}
