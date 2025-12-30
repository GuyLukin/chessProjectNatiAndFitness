#include "Point.h"
#include <math.h>

//consturctor will zerofy the coordinate of the circle
Point::Point() : _x(0), _y(0)
{
}

/*
the func will put given coordinates
input: int x and int y, the coordinate to put into the circle
*/
Point::Point(const int x, const int y)
{
	_x = x;
	_y = y;
}

/*
Baisc destructor
*/
Point::~Point()
{
}

/*
The function will check if 2 points are idetical
input: other point to compare
output: true equall, false otherwise
*/
bool Point::operator==(const Point& other) const
{
	return (this->_x == other.getX()) && (this->_y == other.getY());
}

/*
the func will return the x coordinate of the circle
intput: null
output: the x coordinate of this circle
*/
int Point::getX() const
{
	return _x;
}

/*
the func will return the y coordinate of the circle
intput: null
output: the y coordinate of this circle
*/
int Point::getY() const
{
	return _y;
}

void Point::setX(int x)
{
    _x = x;
}

void Point::setY(int y)
{
    _y = y;
}
