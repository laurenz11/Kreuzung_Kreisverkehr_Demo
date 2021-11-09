#pragma once
#include "Point.h"

class Gerade
{
public: 
	Gerade();
	~Gerade();

	

	float m; //Steigung
	float b; //y-Achsenabschnitt
	float f; //x-achsenabschnitt

	void setGerade(Point point1, Point pint2);
	//float funktionswert(float x);

	void setPointOnGeradeX(Point PointOnGerade, float X); // wenn der y-wert konstant ist
	void setPointOnGeradeY(Point PointOnGerade, float Y); // wenn der x-Wert konstant ist

	void movePointOnGeradeX(Point PointOnGerade, float X);
	void movePointOnGeradeY(Point PointOnGerade, float Y);
};

