#include "Autos.h"

Autos::Autos(std::string Spawn, std::string Direction, float Fahrtweg) {
	beschleunigung = 2;
	bremsBeschleunigung = -1;
	spawn = Spawn;
	direction = Direction;
	fahrtweg = Fahrtweg;
	internalTimer.restart();
	anfangsGeschwindigkeit = 8.333;
}

Autos::~Autos()
{
}

void Autos::speedUp()
{
	if (geschwindigkeit <= 8.333) {
		geschwindigkeit = beschleunigung * zeit + anfangsGeschwindigkeit;//aus Integral weg
		weg = 0.5 * beschleunigung * (pow(zeit, 2)) + (anfangsGeschwindigkeit * zeit);//aus Integral geschwindigkeit

		gesamtWeg = gesamtWeg + weg;
		fahrtweg = fahrtweg - gesamtWeg;
	}
	else
		keepPace();
}

void Autos::slowDown()
{
	geschwindigkeit = bremsBeschleunigung * zeit + anfangsGeschwindigkeit;
	if (geschwindigkeit >= 0) {
		weg = 0.5 * bremsBeschleunigung * (pow(zeit, 2)) + (anfangsGeschwindigkeit * zeit);
	}
	else
		bremsBeschleunigung = 0;

	gesamtWeg = gesamtWeg + weg;
	fahrtweg = fahrtweg - gesamtWeg;
}

void Autos::keepPace()
{
	weg = geschwindigkeit * zeit;

	gesamtWeg = gesamtWeg + weg;
	fahrtweg = fahrtweg - gesamtWeg;
}

void Autos::newPace()
{
	anfangsGeschwindigkeit = geschwindigkeit;
}

void Autos::setZeit()
{
	zeit = internalTimer.getElapsedTime().asMicroseconds()*pow(10,-6);
}