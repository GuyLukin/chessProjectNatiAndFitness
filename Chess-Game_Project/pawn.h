#pragma once
#include "Piece.h"

class Pawn : public Piece 
{
private:
    bool _isFirstTime;

public:
    Pawn(Point source);

    bool isValidMove( const Board& board, Point inputPoint) override;
};
