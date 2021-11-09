#pragma once
#include "Point.h"
#include <math.h>
class Kreis
{
public :

	Kreis();
	~Kreis();
	float r;
	float x;
	float y;
	Point center;
	void setKreis(float R, Point Center);


};

