#include "Autos.h"


//Zykluszeiten vorgeben, Anfangsgeschwindigkeit 0, nur wenn Ampel nicht rot ist, wenn linksabbieger fahren wollen , erstmal streckenabschnitt der blockiert laufen lassen
//Geschwindigkeit die das Auto hat
Autos::Autos(std::string Spawn, std::string Direction, float Fahrtweg, float ReactionTime) {
	beschleunigung = 2;
	bremsBeschleunigung = -1;
	spawn = Spawn;
	direction = Direction;
	fahrtweg = Fahrtweg;
	internalTimer.restart();
	anfangsGeschwindigkeit = 8.333; // in meter pro sekunde 
	gesamtWeg = 0;
	wegBefore = 0;
	weg = 0;
	reactionTime = ReactionTime;
}

Autos::~Autos()
{
}

void Autos::speedUp()
{
	setZeit();
	geschwindigkeit = beschleunigung * zeit + anfangsGeschwindigkeit; //aus Integral weg

	if (geschwindigkeit < 8.333) {
		wegBefore = weg;

		weg = 0.5 * beschleunigung * (pow(zeit, 2)) + (anfangsGeschwindigkeit * zeit); //aus Integral geschwindigkeit

		gesamtWeg = gesamtWeg + weg - wegBefore;
		fahrtweg = fahrtweg - gesamtWeg + wegBefore;
	}
	else
		keepPace();
}

void Autos::slowDown()
{
	setZeit();
	wegBefore = weg;
	geschwindigkeit = bremsBeschleunigung * zeit + anfangsGeschwindigkeit;

	if (geschwindigkeit >= 0) {
		wegBefore = weg;

		weg = 0.5 * bremsBeschleunigung * (pow(zeit, 2)) + (anfangsGeschwindigkeit * zeit);
	}
	else
		bremsBeschleunigung = 0;

	gesamtWeg = gesamtWeg + weg - wegBefore;
	fahrtweg = fahrtweg - gesamtWeg + wegBefore;
	//fahrtweg = fahrtweg - (gesamtWeg + weg - wegBefore) + wegBefore;
}

void Autos::keepPace()
{
	setZeit();
	wegBefore = weg;

	weg = geschwindigkeit * zeit;

	gesamtWeg = gesamtWeg + weg - wegBefore;
	fahrtweg = fahrtweg - gesamtWeg + wegBefore;
}

void Autos::newPace()
{
	anfangsGeschwindigkeit = geschwindigkeit;
}

void Autos::setZeit()
{
	zeit = internalTimer.getElapsedTime().asSeconds();
	//std::cout << "internalTimer: " << zeit << std::endl;
}

