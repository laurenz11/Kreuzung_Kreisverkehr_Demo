#include "Point.h"

Point::Point()
{
    y = 0;
    x = 0;
}

void Point::changeSize(float X, float Y)
{
    x = X;
    y = Y;

}

float Point::getY()
{
    return y;
}

float Point::getX()
{
    return x;
}
