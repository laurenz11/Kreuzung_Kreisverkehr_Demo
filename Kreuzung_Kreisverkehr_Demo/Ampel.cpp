#include "Ampel.h"

Ampel::Ampel(bool nordSuedIsGreen, bool ostWestIsGreen) 
{
	NordSuedIsGreen = nordSuedIsGreen;
	OstWestIsGreen = ostWestIsGreen;
}

Ampel::~Ampel() 
{

}

void Ampel::startAmpelTimerNordSued()
{
	ampelTimerNordSued.restart();
}

void Ampel::startAmpelTimerOstWest()
{
	ampelTimerOstWest.restart();
}

void Ampel::startAmpelTimer()
{
	ampelTimer.restart();
}
void Ampel::cycleAmpelNordSued()
{
	if (ampelTimerNordSued.getElapsedTime().asSeconds() <= 38) {
		NordSuedIsGreen = true;
	}
	else if (ampelTimerNordSued.getElapsedTime().asSeconds() >= 38 && ampelTimerNordSued.getElapsedTime().asSeconds() <= 54) {
		NordSuedIsGreen = false;
	}
	else
		startAmpelTimerNordSued();
}

void Ampel::cycleAmpelOstWest()
{
	if (ampelTimerOstWest.getElapsedTime().asSeconds() <= 50) {
		OstWestIsGreen = true;
	}
	else if (ampelTimerOstWest.getElapsedTime().asSeconds() >= 38 && ampelTimerNordSued.getElapsedTime().asSeconds() <= 54) {
		NordSuedIsGreen = false;
	}
	else
		startAmpelTimerNordSued();
}

void Ampel::cycleAmpel()
{
	if(ampelTimer.getElapsedTime().asSeconds() <= 38)
	{

	}