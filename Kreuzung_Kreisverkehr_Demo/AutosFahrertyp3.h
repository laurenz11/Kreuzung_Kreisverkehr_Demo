#pragma once
#include "Autos.h"

class AutosFahrertyp3 : public Autos
{
public: 
	AutosFahrertyp3(std::string Spawn, std::string Direction, float Fahrtweg, float ReactionTime, float FahrtwegOnKreuzung) : Autos(Spawn, Direction, Fahrtweg, ReactionTime, FahrtwegOnKreuzung) {
		reactionTime = ReactionTime;
	}

private:
};


