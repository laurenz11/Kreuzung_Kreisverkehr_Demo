#include "Autos.h"


//Zykluszeiten vorgeben, Anfangsgeschwindigkeit 0, nur wenn Ampel nicht rot ist, wenn linksabbieger fahren wollen , erstmal streckenabschnitt der blockiert laufen lassen
//Geschwindigkeit die das Auto hat
Autos::Autos(float x, float y, Spawnpoint spawn, std::string Direction, Gerade g, float ReactionTime, float r) {
	beschleunigung = 1;
	bremsBeschleunigung = -2;
	fahrtwegBeginn = g;
	direction = Direction;
	Auto.setPoint(x, y);
	internalTimer.restart();
	anfangsGeschwindigkeit = 0; // in meter pro sekunde 
	gesamtWeg = 0;
	wegBefore = 0;
	weg = 0;
	reactionTime = ReactionTime;

	abstandHalter.setKreis(r, Auto);

	switch (spawn)
	{
	case Spawnpoint::B: //Spawn auf Gerade b (im Süden)
	{
		if (direction == "ost")
		{
			fahrtwegWechsel = Map::c;
		}
		else if (direction == "west")
		{
			fahrtwegWechsel = Map::d;
		}
		else
			fahrtwegWechsel = fahrtwegBeginn;
	}
	case Spawnpoint::D:
	{
		if (direction == "sued")
		{
			fahrtwegWechsel = Map::a;
		}
		else
			fahrtwegWechsel = fahrtwegBeginn;
	}
	case Spawnpoint::E:
	{
		fahrtwegWechsel = Map::b;
	}
	case Spawnpoint::A:
	{
		if (direction == "ost")
		{
			fahrtwegWechsel = Map::c;
		}
		else if (direction == "west")
		{
			fahrtwegWechsel = Map::d;
		}
		else
			fahrtwegWechsel = fahrtwegBeginn;
	}
	case Spawnpoint::F:
	{
		fahrtwegWechsel = Map::a;
	}
	case Spawnpoint::C:
	{
		if (direction == "nord")
		{
			fahrtwegWechsel = Map::b;
		}
		else
			fahrtwegWechsel = fahrtwegBeginn;
	}
	}
}

Autos::~Autos()
{
}

void Autos::initKreuzung()
{
	kreuzung.createKreuzung();
}

void Autos::speedUp()// weg muss dann im Koordinatensystem entweder das Auto parallel der x-Achse, oder auf der y-Achse verschieben, wenn die Fahrbedingung erüllt ist 
{
	setZeit();
	geschwindigkeit = beschleunigung * zeit + anfangsGeschwindigkeit; //aus Integral weg

		wegBefore = weg;

		weg = 0.5 * beschleunigung * (pow(zeit, 2)) + (anfangsGeschwindigkeit * zeit); //aus Integral geschwindigkeit

		gesamtWeg = gesamtWeg + weg - wegBefore;
		streckenLänge = streckenLänge - gesamtWeg + wegBefore;

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
	streckenLänge = streckenLänge - gesamtWeg + wegBefore;
	//fahrtweg = fahrtweg - (gesamtWeg + weg - wegBefore) + wegBefore;
}

void Autos::keepPace()
{
	setZeit();
	wegBefore = weg;

	weg = geschwindigkeit * zeit;

	gesamtWeg = gesamtWeg + weg - wegBefore;
	streckenLänge = streckenLänge - gesamtWeg + wegBefore;
}

void Autos::newPace()
{
	anfangsGeschwindigkeit = geschwindigkeit;
}

void Autos::stop()
{
	geschwindigkeit = 0;
}

void Autos::setZeit()
{
	zeit = internalTimer.getElapsedTime().asSeconds();
	//std::cout << "internalTimer: " << zeit << std::endl;
}


float Autos::getFahrtWeg()
{
	return streckenLänge;
}

float Autos::getInternalTimer()
{
	return internalTimer.getElapsedTime().asSeconds();
}

float Autos::getReactionTime()
{
	return reactionTime;
}

float Autos::getX()
{
	return Auto.getX();
}

float Autos::getY()
{
	return Auto.getY();
}




