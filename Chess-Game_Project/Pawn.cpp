#include "pawn.h"
#include "Piece.h"
#include "Board.h"

bool Pawn::isValidMove(const Board& board, Point destPoint)
{
	bool isValidTemp = false;
	bool isBlocked = false;
	if (destPoint.getX() == _currLocation.getX())
	{
		if (destPoint.getY() == _currLocation.getY())
		{
			isValidTemp = true;
		}
		else if ((!_isFirstTime) && (destPoint.getY() == _currLocation.getY() + 1))
		{
			isValidTemp = true;
		}
		else
		{
			isValidTemp = false;
		}
	}
}