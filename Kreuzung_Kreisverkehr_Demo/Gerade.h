#pragma once
#include "Point.h"

class Gerade
{
public: 
	Gerade(Point point1, Point point2);
	~Gerade();

	

	float m; //Steigung
	float b; //y-Achsenabschnitt
	float f; //x-achsenabschnitt

	float funktionswert(float x);

	void setPointOnGeradeX(Point PointOnGerade, float X); // wenn der y-wert konstant ist
	void setPointOnGeradeY(Point PointOnGerade, float Y); // wenn der x-Wert konstant ist

	void movePointOnGeradeX(Point PointOnGerade, float weg);
	void movePointOnGeradeY(Point PointOnGerade, float weg);
};

