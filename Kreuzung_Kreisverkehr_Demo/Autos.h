#pragma once
#include <string>
#include <vector>
#include "SFML/System.hpp"
#include <math.h>
#include <iostream>
class Autos
{
public:
	Autos(std::string Spawn, std::string Direction, float Fahrtweg);
	~Autos();

	//diese Funktionen sollen lediglich den counter(also einfach den fahrtweg) runterz�hlen
	void speedUp();//Beschleunigung, runterz�hlen nicht konstant
	void slowDown();//Bremsen, runterz�hlen nicht konstant, "R�ckw�rtsfahren" also counter fahrtweg hochz�hlen verhindern
	void keepPace();//Geschwindigkeit halten, konstant runterz�hlen mit geschwindigkeit*zeit
	void newPace();
	//float getPace();//gibt Geschwindigkeit zur�ck
	//float getWeg();//gibt Weg zur�ck
	void setZeit();//Setzt die zeit in der Formel mit der abgelaufenen Zeit des internalCounter gleich

	float getFahrtWeg() 
	{
		return fahrtweg;
	}

protected:
	std::string spawn;//ort des spawns
	std::string direction;//Zielrichtung
	int reactionTime;//Reaktionszeit
	float beschleunigung;
	float bremsBeschleunigung;
	float anfangsGeschwindigkeit;
	float geschwindigkeit;
	float weg;
	float zeit;
	float zeitInterval;
	float gesamtWeg;
	sf::Clock internalTimer;//wird beim spawn gestartet
	float fahrtweg;//berechneter Fahrtweg f�r die einzelnen Fahrtwege
};

