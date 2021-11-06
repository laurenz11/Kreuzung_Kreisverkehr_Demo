#pragma once
#include "Autos.h"

class AutosFahrertyp3 : public Autos
{
public: 
	AutosFahrertyp3(std::string Spawn, std::string Direction, float Fahrtweg) : Autos(Spawn, Direction, Fahrtweg) {
		reactionTime = 3;
	}

private:
};


