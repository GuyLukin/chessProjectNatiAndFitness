#pragma once
#include "Piece.h"

class Bishop : public Piece 
{
public:
    Bishop(Point source, std::string color);

    bool isValidMove( const Board& board,  Point inputPoint ) override;
};
