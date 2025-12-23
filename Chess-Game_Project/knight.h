#pragma once
#include "Piece.h"

class Knight : public Piece 
{
public:
    Knight(Point source);

    bool isValidMove( const Board& board, Point inputPoint ) override;
};
