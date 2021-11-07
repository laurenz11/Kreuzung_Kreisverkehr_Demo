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
	sf::Clock ampelTimerNordSued;
	sf::Clock ampelTimerOstWest;
	sf::Clock ampelTimer;

	//startet AmpelTimer
	void startAmpelTimerNordSued();
	void startAmpelTimerOstWest();
	void startAmpelTimer();

	//Schaltet Ampel weiter
	void cycleAmpelNordSued();
	void cycleAmpelOstWest();
	void cycleAmpel();

	//getter-Funktion für die Simulation
	bool checkIfGreenNordSued();
	bool checkIfGreenOstWest();

};