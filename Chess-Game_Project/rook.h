#pragma once
#include "Piece.h"

class Rook : public Piece 
{
public:
    Rook(Point source, std::string color);

    bool isValidMove(const Board& board, Point destPoint) override;
};
