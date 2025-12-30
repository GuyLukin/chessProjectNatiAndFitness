#pragma once
#include <vector>
#include <string>
#include "Point.h"

class Board;

class Piece
{
protected:
    bool _isKingFlag;
    Point _currLocation;
    std::string _color;
public:
    std::string chooseMoveCode(Board& board, Point destPoint);
    Piece(Point source, std::string color, bool isKingFlag);
    virtual ~Piece();
    bool checkIsKing();
    std::string getColor() const;
    Point getLoc() const;

    virtual bool isValidMove(const Board& board, Point inputPoint) = 0;

    void setLoc(Point inputPoint);

};