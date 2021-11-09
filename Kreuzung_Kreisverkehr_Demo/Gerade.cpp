#include "Gerade.h"

Gerade::Gerade(Point point1, Point point2)
{
	if (point1.x - point2.x == 0)
	{
		m = 0;
		b = point1.getX();

	}
	else
	{
		m = (point2.getY() - point1.getY()) / (point2.getX() - point1.getX());
		b = point1.getY() - m * point1.getX();
	}
}

Gerade::~Gerade()
{

}



 float Gerade::funktionswert(float x)
{
	return m * x + b;
}

 void Gerade::setPointOnGeradeX(Point PointOnGerade,  float X)
 {
	 PointOnGerade.setPoint(X, m * X + b);
 }

 void Gerade::setPointOnGeradeY(Point PointOnGerade, float Y)
 {
	 PointOnGerade.setPoint(f, Y);
 }

 void Gerade::movePointOnGeradeX(Point PointOnGerade, float weg)
 {
	 PointOnGerade.movePoint(weg, m * weg + b);
 }

 void Gerade::movePointOnGeradeY(Point PointOnGerade, float weg)
 {
	 PointOnGerade.movePoint(m*weg +b, weg);
 }

