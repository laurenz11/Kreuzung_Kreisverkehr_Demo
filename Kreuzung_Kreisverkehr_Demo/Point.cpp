#include "Point.h"
Point::Point()
{
	x;
	y
}

void Point::setPoint(float X, float Y)
{
	x = X;
	y = Y;

}

void Point::movePoint(float X, float Y)
{
	x = X; 
	y = Y;
}

float Point::getX()
{
	return x;
}

float Point::getY()
{
	return y;
}
