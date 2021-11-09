#pragma once
#include "Point.h"
#include <math.h>
class Kreis
{
public :

	Kreis(float R, float x, float y);
	~Kreis();

	float r;
	Point center;
	void setKreis();


};

