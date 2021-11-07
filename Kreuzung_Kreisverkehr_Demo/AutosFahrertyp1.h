#pragma once
#include "Autos.h"

class AutosFahrertyp1 : public Autos
{
public:
	AutosFahrertyp1(std::string Spawn, std::string Direction, float Fahrtweg, float ReactionTime) : Autos(Spawn, Direction, Fahrtweg, ReactionTime) {
		reactionTime = ReactionTime;
	}


};

