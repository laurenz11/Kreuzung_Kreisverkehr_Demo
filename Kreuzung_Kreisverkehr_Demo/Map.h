#pragma once
#include "Point.h"
#include "Gerade.h"
class Map
{
public :
	Map();
	~Map();

	void createKreuzung();
	void createKreisverkehr();

	Point point1;
	Point point2;
	Point point3;
	Point point4;
	Point point5;
	Point point6;
	Point point7;
	Point point8;
	Point point9;
	Point point10;
	Point point11;
	Point point12;



	static Gerade a;
	static Gerade b;
	static Gerade c;
	static Gerade d;
	static Gerade e;
	static Gerade f;
	
};

