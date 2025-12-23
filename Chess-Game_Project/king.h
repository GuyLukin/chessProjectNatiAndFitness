#pragma once
#include "Piece.h"

class King : public Piece 
{
public:
    King(Point source);

    void isValidMove( const Board& board, Point inputPoint ) override;
};
