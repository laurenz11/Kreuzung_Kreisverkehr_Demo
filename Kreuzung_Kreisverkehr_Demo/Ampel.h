#pragma once
#include "SFML/System/Clock.hpp"
#include <iostream>

class Ampel
{
public :
	Ampel();
	~Ampel();
	
	//Gibt uns nachher aus, ob die Ampel grün ist oder nicht
	bool NordSuedIsGreen;
	bool OstWestIsGreen;

	//Timer für die beiden gegenüberliegenden Ampeln
	sf::Clock ampelTimer;

	//startet AmpelTimer
	void startAmpelTimer();

	//Schaltet Ampel weiter
	void cycleAmpel();
	int ampelZyklusCounter;

	//Zeigt an wohin geschaltet wird
	bool toOstWest;

	//getter-Funktion für die Simulation
	bool checkIfGreenNordSued();
	bool checkIfGreenOstWest();

};