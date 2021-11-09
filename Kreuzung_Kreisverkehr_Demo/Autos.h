#pragma once
#include <string>
#include <vector>
#include "SFML/System.hpp"
#include <math.h>
#include <iostream>
#include "Gerade.h"
#include "Kreis.h"
#include "Point.h"
#include "Autos.h"
#include "Map.h"
#include "CarProp.h"
class Autos
{
public:
	Autos(float x, float y, Spawnpoint spawn , std::string Direction, Gerade g, float ReactionTime, float r);
	~Autos();

	Map kreuzung;
	void initKreuzung();


	Point Auto;//Jedes Auto ist dann ein Punkt auf der Geraden mit einem Kreis mit gegebenen Abstandsradius, der nicht geschnitten werden darf
	Gerade fahrtwegBeginn; //Geraden, auf dem sich das Auto bewegen soll
	Gerade fahrtwegWechsel;//Gerade auf die das Auto dann wechseln soll
	Kreis abstandHalter;


	//diese Funktionen sollen lediglich den counter(also einfach den fahrtweg) runterz�hlen
	void speedUp();//Beschleunigung, runterz�hlen nicht konstant
	void slowDown();//Bremsen, runterz�hlen nicht konstant, "R�ckw�rtsfahren" also counter fahrtweg hochz�hlen verhindern
	void keepPace();//Geschwindigkeit halten, konstant runterz�hlen mit geschwindigkeit*zeit
	void newPace();
	void stop();//F�r den Anfang erstmal einfacher
	//float getPace();//gibt Geschwindigkeit zur�ck
	//float getWeg();//gibt Weg zur�ck
	void setZeit();//Setzt die zeit in der Formel mit der abgelaufenen Zeit des internalCounter gleich

	float getFahrtWeg();
	
	float getInternalTimer();
	float getReactionTime();
	float getX();
	float getY();
	
	void moveOnGerade();

protected:
	//std::string spawn ;//ort des spawns
	std::string direction; //Zielrichtung
	float reactionTime; //Reaktionszeit
	float beschleunigung;
	float bremsBeschleunigung;
	float anfangsGeschwindigkeit;
	float geschwindigkeit;
	float weg;
	float zeit;
	float wegBefore;
	float gesamtWeg;
	sf::Clock internalTimer;//wird beim spawn gestartet
	float streckenL�nge;//berechneter Fahrtweg f�r die einzelnen Fahrtwege, wird w�hrend der Simulation weiter runtergez�hlt
	float originalFahrtweg; //urspr�nglicher Fahrtweg, der sich nicht ver�ndert, f�r den Agleich, ob die Kreuzung erreicht wurde 
	//bool isMoving; //gibt an ob sich das Element bewegt.
	//bool isSlowingDown; //f�r sp�ter, gibt an ob das Element gerade bremst

	
};

