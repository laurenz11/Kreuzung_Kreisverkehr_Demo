#include "Kreis.h"

Kreis::Kreis()
{
	r;
	x;
	y;
}

Kreis::~Kreis()
{

}

void Kreis::setKreis(float R, Point Center)
{
	r = R;
	x = sqrt(pow(r, 2) - pow(y - Center.getY(), 2)) - Center.getX();
	y = sqrt(pow(r, 2) - pow(x - Center.getX(), 2)) - Center.getY();
}
