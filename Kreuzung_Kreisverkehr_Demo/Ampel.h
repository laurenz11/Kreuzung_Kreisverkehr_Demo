#pragma once
#include "SFML/System/Clock.hpp"
#include <iostream>

class Ampel
{
public :
	Ampel();
	~Ampel();
	
	//Gibt uns nachher aus, ob die Ampel gr�n ist oder nicht
	bool NordSuedIsGreen;
	bool OstWestIsGreen;

	//Timer f�r die beiden gegen�berliegenden Ampeln
	sf::Clock ampelTimer;

	//startet AmpelTimer
	void startAmpelTimer();

	//Schaltet Ampel weiter
	void cycleAmpel();
	int ampelZyklusCounter;

	//Zeigt an wohin geschaltet wird
	bool toOstWest;

	//getter-Funktion f�r die Simulation
	bool checkIfGreenNordSued();
	bool checkIfGreenOstWest();

};