#include "Gerade.h"

Gerade::Gerade()
{
	m;
	b;
	f;
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

 void Gerade::setGerade(Point point1, Point point2)
 {
	 if (point1.x - point2.x == 0)
	 {
		 m = 0;
		 b = 0;
		 f = point1.getX();
	 }
	 else
	 {
		 m = (point2.getY() - point1.getY()) / (point2.getX() - point1.getY());
		 b = point1.getY() - m * point1.getX();
		 f = -(b / m);
	 }
 }