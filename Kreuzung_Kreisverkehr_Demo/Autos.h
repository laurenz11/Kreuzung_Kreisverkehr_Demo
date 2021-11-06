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

	//diese Funktionen sollen lediglich den counter(also einfach den fahrtweg) runterzählen
	void speedUp();//Beschleunigung, runterzählen nicht konstant
	void slowDown();//Bremsen, runterzählen nicht konstant, "Rückwärtsfahren" also counter fahrtweg hochzählen verhindern
	void keepPace();//Geschwindigkeit halten, konstant runterzählen mit geschwindigkeit*zeit
	void newPace();
	//float getPace();//gibt Geschwindigkeit zurück
	//float getWeg();//gibt Weg zurück
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
	float fahrtweg;//berechneter Fahrtweg für die einzelnen Fahrtwege
};

