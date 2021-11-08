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

	//diese Funktionen sollen lediglich den counter(also einfach den fahrtweg) runterz�hlen
	void speedUp();//Beschleunigung, runterz�hlen nicht konstant
	void slowDown();//Bremsen, runterz�hlen nicht konstant, "R�ckw�rtsfahren" also counter fahrtweg hochz�hlen verhindern
	void keepPace();//Geschwindigkeit halten, konstant runterz�hlen mit geschwindigkeit*zeit
	void newPace();
	void stop();//F�r den Anfang erstmal einfacher
	//float getPace();//gibt Geschwindigkeit zur�ck
	//float getWeg();//gibt Weg zur�ck
	void setZeit();//Setzt die zeit in der Formel mit der abgelaufenen Zeit des internalCounter gleich

	void changeIsMoving();//ver�ndert isMoving, je nachdem ob geschwindigkeit > 0 oder =0 ist

	float getFahrtWeg();
	float getOriginalFahrtweg();
	bool getIsMoving();//gibt an ob das Element in Bewegung ist (geschwindigkeit > 0), und kann dann f�r die checkIfInFront() in SimulationMaster verwendet werden
	
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
	float fahrtweg;//berechneter Fahrtweg f�r die einzelnen Fahrtwege, wird w�hrend der Simulation weiter runtergez�hlt
	float fahrtwegKreuzung;
	float originalFahrtweg; //urspr�nglicher Fahrtweg, der sich nicht ver�ndert, f�r den Agleich, ob die Kreuzung erreicht wurde 
	bool isMoving; //gibt an ob sich das Element bewegt.
	bool isSlowingDown; //f�r sp�ter, gibt an ob das Element gerade bremst
};

