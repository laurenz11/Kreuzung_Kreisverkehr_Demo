#include "Kreis.h"

Kreis::Kreis()
{
	
	
}

Kreis::~Kreis()
{

}

void Kreis::setKreis(float R, Point Center)
{
	r = R;
	x = sqrt(pow(r, 2) - pow(y - center.getY(), 2)) - center.getX();
	y = sqrt(pow(r, 2) - pow(x - center.getX(), 2)) - center.getY();
}
