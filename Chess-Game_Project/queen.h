#pragma once
#include "Piece.h"

class Queen : public Piece 
{
public:
    Queen(Point source);

    bool isValidMove( const Board& board,  Point inputPoint ) override;
};
