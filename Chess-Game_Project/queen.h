#pragma once
#include "Piece.h"

class Queen : public Piece 
{
public:
    Queen(Point source, std::string color);

    bool isValidMove( const Board& board,  Point inputPoint ) override;
};
