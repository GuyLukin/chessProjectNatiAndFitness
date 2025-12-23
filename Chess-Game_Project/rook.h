#pragma once
#include "Piece.h"

class Rook : public Piece 
{
public:
    Rook(Point source);

    void isValidMove( const Board& board, Point inputPoint ) override;
};
