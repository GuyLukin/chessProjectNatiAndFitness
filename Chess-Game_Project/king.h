#pragma once
#include "Piece.h"

class King : public Piece 
{
public:
    King(Point source);

    bool isValidMove( const Board& board, Point inputPoint ) override;
};
