#include "Gerade.h"

Gerade::Gerade()
{
	
}

void Gerade::createGerade(Point* point1, Point* point2)
{
	if (point1->getX() - point2->getX() == 0)
	{
		m = 0;
		b = point1->getY();
	}
	else
	{
		m = (point2->getY() - point1->getY()) / (point2->getX() - point1->getY());
		b = point1->getY() - m * point1->getX();
	}
}


float Gerade::funktionswert(float x)
{
	return m * x + b;
}
