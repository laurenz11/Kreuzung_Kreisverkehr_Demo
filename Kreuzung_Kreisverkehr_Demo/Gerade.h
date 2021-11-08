#pragma once
#include "Point.h"

class Gerade
{
public: 
	Gerade();
	float m; //Steigung
	float b; //y-Achsenabschnitt

	void createGerade(Point* point1, Point* point2);
	float funktionswert(float x);

};

