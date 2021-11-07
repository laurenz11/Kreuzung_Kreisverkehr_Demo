#include "Ampel.h"

Ampel::Ampel() 
{
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
	if (ampelTimer.getElapsedTime().asSeconds() <= 38)//Die ersten 38 sekunden ist nord sued gr�n, 36 sekunden gr�n und dann noch zwei sekunden gelb in denen aber auch noch Autos fahren d�rfen
	{
		NordSuedIsGreen = true;
		OstWestIsGreen = false;
		std::cout << "NordSued: " << NordSuedIsGreen << std::endl;
		std::cout << "OstWest: " << OstWestIsGreen << std::endl;
	}
	else if (ampelTimer.getElapsedTime().asSeconds() > 38 && ampelTimer.getElapsedTime().asSeconds() <= 40) //F�r eine sekunde sind beide Ampeln rot und eine weiter sekunde ist die nordsued gelb, aber wir lassen keinen mehr r�ber
	{
		NordSuedIsGreen = false;
		OstWestIsGreen = false;
		std::cout << "NordSued: " << NordSuedIsGreen << std::endl;
		std::cout << "OstWest: " << OstWestIsGreen << std::endl;
	}
	else if (ampelTimer.getElapsedTime().asSeconds() > 40 && ampelTimer.getElapsedTime().asSeconds() <= 91)//ost west ist 50 sekundne gr�n und 1 sekunde gelb
	{
		NordSuedIsGreen = false;
		OstWestIsGreen = true;
		std::cout << "NordSued: " << NordSuedIsGreen << std::endl;
		std::cout << "OstWest: " << OstWestIsGreen << std::endl;
	}
	else if (ampelTimer.getElapsedTime().asSeconds() > 91 && ampelTimer.getElapsedTime().asSeconds() <= 93)//2 sekunden sind beide Ampeln rot, dann startet der Zyklus von vorne
	{
		NordSuedIsGreen = false;
		OstWestIsGreen = false;
		std::cout << "NordSued: " << NordSuedIsGreen << std::endl;
		std::cout << "OstWest: " << OstWestIsGreen << std::endl;
	}
	else
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