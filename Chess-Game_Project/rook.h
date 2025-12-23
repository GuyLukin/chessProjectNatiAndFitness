#pragma once
#include "Piece.h"

class Rook : public Piece 
{
public:
    Rook(Point source);

    bool isValidMove( const Board& board, Point inputPoint ) override;
};
