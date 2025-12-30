#pragma once
#include "Piece.h"

class King : public Piece 
{
public:
    King(Point source, std::string color);

    bool isValidMove( const Board& board, Point inputPoint ) override;
};
