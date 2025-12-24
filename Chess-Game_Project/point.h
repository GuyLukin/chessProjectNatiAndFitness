#pragma once

class Point 
{
private:
    int _x;
    int _y;

public:
    Point();
    Point(const int x,const int y);

    int getX() const;
    int getY() const;

    void setX(int x);
    void setY(int y);

    bool operator==(const Point& other) const;
};

