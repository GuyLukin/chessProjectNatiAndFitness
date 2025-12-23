#include "piece.h"
#include "point.h"
#include "board.h"
Piece::Piece(Point source)
{
}

Piece::~Piece()
{
}

std::string Piece::getColor() const
{
	return _color;
}

Point Piece::getLoc() const
{
	return _currLocation;
}

void Piece::setLoc(Point inputPoint)
{
	_currLocation = inputPoint;
}
