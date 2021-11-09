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


	//diese Funktionen sollen lediglich den counter(also einfach den fahrtweg) runterzählen
	void speedUp();//Beschleunigung, runterzählen nicht konstant
	void slowDown();//Bremsen, runterzählen nicht konstant, "Rückwärtsfahren" also counter fahrtweg hochzählen verhindern
	void keepPace();//Geschwindigkeit halten, konstant runterzählen mit geschwindigkeit*zeit
	void newPace();
	void stop();//Für den Anfang erstmal einfacher
	//float getPace();//gibt Geschwindigkeit zurück
	//float getWeg();//gibt Weg zurück
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
	float streckenLänge;//berechneter Fahrtweg für die einzelnen Fahrtwege, wird während der Simulation weiter runtergezählt
	float originalFahrtweg; //ursprünglicher Fahrtweg, der sich nicht verändert, für den Agleich, ob die Kreuzung erreicht wurde 
	//bool isMoving; //gibt an ob sich das Element bewegt.
	//bool isSlowingDown; //für später, gibt an ob das Element gerade bremst

	
};

