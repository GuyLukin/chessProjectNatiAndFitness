#pragma once
#include "Piece.h"

class Pawn : public Piece 
{
private:
    bool _isFirstTime;

public:
    Pawn(Point source, std::string);

    bool isValidMove( const Board& board, Point destPoint) override;
};
