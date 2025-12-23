#pragma once
#include <vector>
#include <string>
#include "Point.h"

class Board;

class Piece 
{
protected:
    std::vector<Point> _validDests;
    Point _currLocation;
    std::string _color;

public:
    Piece(Point source);
    virtual ~Piece() = default;

    std::string getColor() const;
    Point getLoc() const;

    virtual void isValidMove( const Board& board, Point inputPoint) = 0;

    void setLoc(Point inputPoint);

   
};
