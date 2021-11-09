#include "Map.h"

Map::Map()
{
}

void Map::createKreuzung()
{
	//Gerade a 
	point1.setPoint(2, -8);
	point2.setPoint(2, 8);

	//Gerade b
	point3.setPoint(-2, 8);
	point4.setPoint(-2, -8);

	//Gerade c
	point5.setPoint(-12, 2);
	point6.setPoint(12, 2);

	//Gerade d
	point7.setPoint(-12, -2);
	point8.setPoint(12, -2);

	//Gerade e
	point9.setPoint(-12, -6);
	point10.setPoint(12, -6);

	//Gerade f
	point11.setPoint(12, 6);
	point12.setPoint(-12, 6);

	a.setGerade(point1, point2);
	b.setGerade(point3, point4);
	c.setGerade(point5, point6);
	d.setGerade(point7, point8);
	e.setGerade(point9, point10);
	f.setGerade(point11, point12);
}