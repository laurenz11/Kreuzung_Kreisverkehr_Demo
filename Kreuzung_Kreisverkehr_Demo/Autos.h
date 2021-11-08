#pragma once
#include <string>
#include <vector>
#include "SFML/System.hpp"
#include <math.h>
#include <iostream>
class Autos
{
public:
	Autos(std::string Spawn, std::string Direction, float Fahrtweg, float ReactionTime, float FahrtwegOnKreuzung);
	~Autos();

	//diese Funktionen sollen lediglich den counter(also einfach den fahrtweg) runterzählen
	void speedUp();//Beschleunigung, runterzählen nicht konstant
	void slowDown();//Bremsen, runterzählen nicht konstant, "Rückwärtsfahren" also counter fahrtweg hochzählen verhindern
	void keepPace();//Geschwindigkeit halten, konstant runterzählen mit geschwindigkeit*zeit
	void newPace();
	void stop();//Für den Anfang erstmal einfacher
	//float getPace();//gibt Geschwindigkeit zurück
	//float getWeg();//gibt Weg zurück
	void setZeit();//Setzt die zeit in der Formel mit der abgelaufenen Zeit des internalCounter gleich

	void changeIsMoving();//verändert isMoving, je nachdem ob geschwindigkeit > 0 oder =0 ist

	float getFahrtWeg();
	float getOriginalFahrtweg();
	bool getIsMoving();//gibt an ob das Element in Bewegung ist (geschwindigkeit > 0), und kann dann für die checkIfInFront() in SimulationMaster verwendet werden
	
	float getInternalTimer();
	float getReactionTime();

	std::string getDirection();

protected:
	std::string spawn;//ort des spawns
	std::string direction;//Zielrichtung
	float reactionTime;//Reaktionszeit
	float beschleunigung;
	float bremsBeschleunigung;
	float anfangsGeschwindigkeit;
	float geschwindigkeit;
	float weg;
	float zeit;
	float wegBefore;
	float gesamtWeg;
	sf::Clock internalTimer;//wird beim spawn gestartet
	float fahrtweg;//berechneter Fahrtweg für die einzelnen Fahrtwege, wird während der Simulation weiter runtergezählt
	float fahrtwegKreuzung;
	float originalFahrtweg; //ursprünglicher Fahrtweg, der sich nicht verändert, für den Agleich, ob die Kreuzung erreicht wurde 
	bool isMoving; //gibt an ob sich das Element bewegt.
	bool isSlowingDown; //für später, gibt an ob das Element gerade bremst
};

