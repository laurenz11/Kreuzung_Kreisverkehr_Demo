#pragma once
#include "Autos.h"

class AutosFahrertyp2 : public Autos
{
public:
	AutosFahrertyp2(std::string Spawn, std::string Direction, float Fahrtweg, float ReactionTime) : Autos(Spawn, Direction, Fahrtweg, ReactionTime) {
		reactionTime = ReactionTime;
	}

private: 

};

