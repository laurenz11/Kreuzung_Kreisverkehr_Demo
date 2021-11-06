#pragma once
#include "Autos.h"

class AutosFahrertyp2 : public Autos
{
public:
	AutosFahrertyp2(std::string Spawn, std::string Direction, float Fahrtweg) : Autos(Spawn, Direction, Fahrtweg) {
		reactionTime = 1;
	}

private: 

};

