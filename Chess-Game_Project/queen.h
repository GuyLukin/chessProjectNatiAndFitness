#pragma once
#include "Piece.h"

class Queen : public Piece 
{
public:
    Queen(Point source);

    void isValidMove( const Board& board,  Point inputPoint ) override;
};
