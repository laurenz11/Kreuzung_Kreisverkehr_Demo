#include "Ampel.h"

Ampel::Ampel() 
{
	toOstWest = false;
	NordSuedIsGreen = false;
	OstWestIsGreen = false;
	ampelZyklusCounter = 0;
}

Ampel::~Ampel() 
{

}

void Ampel::startAmpelTimer()//Wird nach jedem Durchlauf der Ampel aufgerufen und startet dann den Timer aufs Neue, ein Durchlauf beutet, dass Ost-west und nord-sued ihre Gr�nphase durchlaufen haben
{
	ampelTimer.restart();
}

void Ampel::cycleAmpel()
{
	if (ampelTimer.getElapsedTime().asSeconds() <= 5) //Ladezeit f�r spawn und allowMovement Funktion.
	{
		toOstWest = false;
		NordSuedIsGreen = false;
		OstWestIsGreen = false;
		std::cout << "NordSued: " << NordSuedIsGreen << std::endl;
		std::cout << "OstWest: " << OstWestIsGreen << std::endl;
	}
	else if (ampelTimer.getElapsedTime().asSeconds() > 5 && ampelTimer.getElapsedTime().asSeconds() <= 43)//Die ersten 38 sekunden ist nord sued gr�n, 36 sekunden gr�n und dann noch zwei sekunden gelb in denen aber auch noch Autos fahren d�rfen
	{
		NordSuedIsGreen = true;
		OstWestIsGreen = false;
		std::cout << "NordSued: " << NordSuedIsGreen << std::endl;
		std::cout << "OstWest: " << OstWestIsGreen << std::endl;
	}

	else if (ampelTimer.getElapsedTime().asSeconds() <= 48)
	{
		toOstWest = true;
		NordSuedIsGreen = false;
		OstWestIsGreen = false;
	}
	else if (ampelTimer.getElapsedTime().asSeconds() < 56)//ost west ist 50 sekundne gr�n und 1 sekunde gelb
	{
		NordSuedIsGreen = false;
		OstWestIsGreen = true;
		std::cout << "NordSued: " << NordSuedIsGreen << std::endl;
		std::cout << "OstWest: " << OstWestIsGreen << std::endl;
	}
	else
		ampelZyklusCounter++;
		startAmpelTimer();
		
}

bool Ampel::checkIfGreenNordSued()
{
	return NordSuedIsGreen;
}

bool Ampel::checkIfGreenOstWest()
{
	return OstWestIsGreen;
}