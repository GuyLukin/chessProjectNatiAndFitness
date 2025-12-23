#pragma once
#include "Piece.h"

class Bishop : public Piece 
{
public:
    Bishop(Point source);

    void isValidMove( const Board& board,  Point inputPoint ) override;
};
