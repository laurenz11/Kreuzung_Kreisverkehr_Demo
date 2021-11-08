#include "SimulationMaster.h"

SimulationMaster::SimulationMaster()
{
	this->initAmpel();
}

SimulationMaster::~SimulationMaster()
{

}

void SimulationMaster::initAmpel()
{
	ampel = new Ampel();
}

void SimulationMaster::run() {

	ampel->startAmpelTimer();

	globalTimer.restart();
	simulationsdauer.restart();
	while (simulationsdauer.getElapsedTime().asSeconds() <= 100) {
		ampel->cycleAmpel();
		updateLists();
		
		//std::cout << "globalTimer: " << globalTimer.getElapsedTime().asSeconds() << std::endl;
	}
}

void SimulationMaster::updateLists() 
{
	spawnAutos();
	moveAutos();
	allowMovement();
}

void SimulationMaster::moveAutos()
{
	
	for (auto x : Nord_West1)
	{
		if (x->getFahrtWeg() > 0 && x->getInternalTimer() >= x->getReactionTime())
		{
			x->speedUp();
			//std::cout << x->getFahrtWeg() << std::endl;
		}
		else
			counterOutWest++;
	}
}
void SimulationMaster::moveAutosOnKreuzung()
{
	if (ampel->checkIfGreenNordSued())//NordSued ist grün
	{
		checkIfInFront();
		if (inFront)
		{

		}
		else
		{

		}
	}
	else if (ampel->checkIfGreenOstWest())//OstWest ist grün
	{
		checkIfInFront();
		if (inFront)
		{

		}
		else
		{

		}
	}
	else//beide sind rot, für diese eine oder zwei sekunden
	{

	}
}



void SimulationMaster::allowMovement()
{

}

void SimulationMaster::checkIfInFront()
{
	
}

void SimulationMaster::spawnAutos()//Fragt die Zufallszahlen ab und füllt dann die entsptrechenden Vektoren
{									//Von da an sind Weg, und Weglänge vorgegeben
									//Spawnt nur wenn die entsprechende Ampel grün ist, erstmal nur 15 Autos pro richtung auf einmal (vereinfachende Annahme)

	randValueType = rand() % 10;
	randValueSpawn = rand() % 100;
	randValueDirection = rand() % 100;

	if (randValueSpawn <= 14 && ampel->checkIfGreenNordSued() && sizeOfVector(Nord_Ost_Kreuzung1, Nord_West_Kreuzung1, Nord_Sued_Kreuzung1) <= 15) //Spawn im Norden
	{
		this->spawnAutosNordKreuzung();
	}

	else if (randValueSpawn >= 15 && randValueSpawn < 50 && ampel->checkIfGreenOstWest() && sizeOfVector(Ost_Nord_Kreuzung1, Ost_West_Kreuzung1, Ost_Sued_Kreuzung1) <= 15) //Spawn im Osten
	{
		this->spawnAutosOstKreuzung();
	}
	else if (randValueSpawn >= 50 && randValueSpawn < 65 && ampel->checkIfGreenNordSued() && sizeOfVector(Sued_Ost_Kreuzung1, Sued_West_Kreuzung1, Sued_Nord_Kreuzung1) <= 15) //Spawn im Süden
	{
		this->spawnAutosSuedKreuzung();
	}
	else if (ampel->checkIfGreenOstWest() && sizeOfVector(West_Ost_Kreuzung1, West_Nord_Kreuzung1, West_Sued_Kreuzung1) <= 15)//spawn im Westen
	{
		this->spawnAutosWestKreuzung();
	}
}



int SimulationMaster::sizeOfVector(std::vector<Autos*> vec_1, std::vector<Autos*> vec_2, std::vector<Autos*> vec_3)
{
	return vec_1.size() + vec_2.size() + vec_3.size();
}



void SimulationMaster::checkKreuzungNord_Ost()
{
	if (Sued_Nord_Kreuzung1.empty() && Sued_Ost_Kreuzung1.empty() && Sued_West_Kreuzung1.empty())
	{
		Nord_OstFree = true;
	}
	else
		Nord_OstFree = false;
}

void SimulationMaster::checkKreuzungSued_West()
{
	if (Nord_Ost_Kreuzung1.empty() && Nord_Sued_Kreuzung1.empty() && Nord_West_Kreuzung1.empty())
	{
		Sued_WestFree = true;
	}
	else
		Sued_WestFree = false;
}

void SimulationMaster::checkKreuzungWest_Nord()
{
	if (Ost_Nord_Kreuzung1.empty() && Ost_Sued_Kreuzung1.empty() && Ost_West_Kreuzung1.empty())
	{
		West_NordFree = true;
	}
	else
		West_NordFree = false;
}

void SimulationMaster::checkKreuzungOst_Sued()
{
	if (West_Nord_Kreuzung1.empty() && West_Ost_Kreuzung1.empty() && West_Sued_Kreuzung1.empty())
	{
		Ost_SuedFree = true;
	}
	else
		Ost_SuedFree = false;
}



//Autos spawnen quasi direkt auf der Kreuzung und zählen Fahrtweg runter, wenn das erlaubt ist

void SimulationMaster::spawnAutosNordKreuzung()
{

	if (randValueDirection <= 9)// Fahr nach Norden
	{
		//Geht nicht
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->Nord_Ost_Kreuzung1.push_back(new Autos(nord, ost, 23.142, 0.75, 23.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_Ost_Kreuzung1.push_back(new Autos(nord, ost, 23.142, 1.f, 23.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else {
			this->Nord_Ost_Kreuzung1.push_back(new Autos(nord, ost, 23.142, 2.f, 23.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
			counterNord++;
		}
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->Nord_Sued_Kreuzung1.push_back(new Autos(nord, sued, 16, 0.75, 16)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_Sued_Kreuzung1.push_back(new Autos(nord, sued, 16, 1.f, 16));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else
			this->Nord_Sued_Kreuzung1.push_back(new Autos(nord, sued, 16, 2.f, 16));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		counterNord++;
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Nord_West_Kreuzung1.push_back(new Autos(nord, west, 15.142, 0.75, 15.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_West_Kreuzung1.push_back(new Autos(nord, west, 15.142, 1.f, 15.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else
			this->Nord_West_Kreuzung1.push_back(new Autos(nord, west, 15.142, 2.f, 15.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		counterNord++;
	}
}


void SimulationMaster::spawnAutosOstKreuzung()
{
	if (randValueDirection <= 9)// Fahr nach Norden
	{
		if (randValueType <= 1)
		{
			this->Ost_Nord_Kreuzung1.push_back(new Autos(ost, nord, 11.142, 0.75, 11.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_Nord_Kreuzung1.push_back(new Autos(ost, nord, 11.142, 1.f, 11.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_Nord_Kreuzung1.push_back(new Autos(ost, nord, 11.142, 2.f, 11.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden

	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		//geht nicht
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->Ost_Sued_Kreuzung1.push_back(new Autos(ost, sued, 15.142, 0.75, 15.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_Sued_Kreuzung1.push_back(new Autos(ost, sued, 15.142, 1.f, 15.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_Sued_Kreuzung1.push_back(new Autos(ost, sued, 15.142, 2.f, 15.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Ost_West_Kreuzung1.push_back(new Autos(ost, west, 24, 0.75, 24)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_West_Kreuzung1.push_back(new Autos(ost, west, 24, 1.f, 24));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_West_Kreuzung1.push_back(new Autos(ost, west, 24, 2.f, 24));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}
}

void SimulationMaster::spawnAutosWestKreuzung()
{
	if (randValueDirection <= 9)// Fahr nach Norden
	{
		if (randValueType <= 1)
		{
			this->West_Nord_Kreuzung1.push_back(new Autos(west, nord, 15.142, 0.75, 15.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Nord_Kreuzung1.push_back(new Autos(west, nord, 15.142, 1.f, 15.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Nord_Kreuzung1.push_back(new Autos(west, nord, 15.142, 2.f, 15.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->West_Ost_Kreuzung1.push_back(new Autos(west, ost, 24, 0.75, 24)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Ost_Kreuzung1.push_back(new Autos(west, ost, 24, 1.f, 24));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Ost_Kreuzung1.push_back(new Autos(west, ost, 24, 2.f, 24));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->West_Sued_Kreuzung1.push_back(new Autos(west, sued, 11.142, 0.75, 11.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Sued_Kreuzung1.push_back(new Autos(west, sued, 11.142, 1.f, 11.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Sued_Kreuzung1.push_back(new Autos(west, sued, 11.142, 2.f, 11.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else //Fahr nach Westen
	{
		//Geht nicht
	}
}


void SimulationMaster::spawnAutosSuedKreuzung()
{
	if (randValueDirection <= 9)// Fahr nach Norden
	{
		if (randValueType <= 1)
		{
			this->Sued_Nord_Kreuzung1.push_back(new Autos(sued, nord, 16, 0.75, 16)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_Nord_Kreuzung1.push_back(new Autos(sued, nord, 16, 1.f, 16));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_Nord_Kreuzung1.push_back(new Autos(sued, nord, 16, 2.f, 16));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->Sued_Ost_Kreuzung1.push_back(new Autos(sued, ost, 15.142, 0.75, 15.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_Ost_Kreuzung1.push_back(new Autos(sued, ost, 15.142, 1.f, 15.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_Ost_Kreuzung1.push_back(new Autos(sued, ost, 15.142, 2.f, 15.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		//geht nicht
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Sued_West_Kreuzung1.push_back(new Autos(sued, west, 23.142, 0.75, 23.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_West_Kreuzung1.push_back(new Autos(sued, west, 23.142, 1.f, 23.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_West_Kreuzung1.push_back(new Autos(sued, west, 23.142, 2.f, 23.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}
}


/*Für später benötigt, wenn wir Autos an die Kreuzung anfahren lassen wollen
Alles unterhalb dieses Kommentars ist evtl für später wenn noch Zeit ist das anfahren an die Ampel zu simulieren*/
void SimulationMaster::spawnAutosNord()
{

	if (randValueDirection <= 9)// Fahr nach Norden
	{
		//Geht nicht
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->Nord_Ost1.push_back(new Autos(nord, ost, 103.142, 0.75, 23.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_Ost1.push_back(new Autos(nord, ost, 103.142, 1.f, 23.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else {
			this->Nord_Ost1.push_back(new Autos(nord, ost, 103.142, 2.f, 23.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
			counterNord++;
		}
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->Nord_Sued1.push_back(new Autos(nord, sued, 96, 0.75, 16)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_Sued1.push_back(new Autos(nord, sued, 96, 1.f, 16));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else
			this->Nord_Sued1.push_back(new Autos(nord, sued, 96, 2.f, 16));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		counterNord++;
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Nord_West1.push_back(new Autos(nord, west, 95.142, 0.75, 15.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_West1.push_back(new Autos(nord, west, 95.142, 1.f, 15.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else
			this->Nord_West1.push_back(new Autos(nord, west, 95.142, 2.f, 15.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		counterNord++;
	}
}


void SimulationMaster::spawnAutosOst()
{
	if (randValueDirection <= 9)// Fahr nach Norden
	{
		if (randValueType <= 1)
		{
			this->Ost_Nord1.push_back(new Autos(ost, nord, 91.142, 0.75, 11.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_Nord1.push_back(new Autos(ost, nord, 91.142, 1.f, 11.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_Nord1.push_back(new Autos(ost, nord, 91.142, 2.f, 11.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden

	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		//geht nicht
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->Ost_Sued1.push_back(new Autos(ost, sued, 95.142, 0.75, 15.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_Sued1.push_back(new Autos(ost, sued, 95.142, 1.f, 15.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_Sued1.push_back(new Autos(ost, sued, 95.142, 2.f, 15.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Ost_West1.push_back(new Autos(ost, west, 104, 0.75, 24)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_West1.push_back(new Autos(ost, west, 104, 1.f, 24));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_West1.push_back(new Autos(ost, west, 104, 2.f, 24));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}
}

void SimulationMaster::spawnAutosWest()
{
	if (randValueDirection <= 9)// Fahr nach Norden
	{
		if (randValueType <= 1)
		{
			this->West_Nord1.push_back(new Autos(west, nord, 103.142, 0.75, 15.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Nord1.push_back(new Autos(west, nord, 103.142, 1.f, 15.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Nord1.push_back(new Autos(west, nord, 103.142, 2.f, 15.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->West_Ost1.push_back(new Autos(west, ost, 104, 0.75, 24)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Ost1.push_back(new Autos(west, ost, 104, 1.f, 24));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Ost1.push_back(new Autos(west, ost, 104, 2.f, 24));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->West_Sued1.push_back(new Autos(west, sued, 91.142, 0.75, 11.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Sued1.push_back(new Autos(west, sued, 91.142, 1.f, 11.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Sued1.push_back(new Autos(west, sued, 91.142, 2.f, 11.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else //Fahr nach Westen
	{
		//Geht nicht
	}
}


void SimulationMaster::spawnAutosSued()
{
	if (randValueDirection <= 9)// Fahr nach Norden
	{
		if (randValueType <= 1)
		{
			this->Sued_Nord1.push_back(new Autos(sued, nord, 96, 0.75, 16)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_Nord1.push_back(new Autos(sued, nord, 96, 1.f, 16));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_Nord1.push_back(new Autos(sued, nord, 96, 2.f, 16));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->Sued_Ost1.push_back(new Autos(sued, ost, 95.142, 0.75, 15.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_Ost1.push_back(new Autos(sued, ost, 95.142, 1.f, 15.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_Ost1.push_back(new Autos(sued, ost, 95.142, 2.f, 15.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		//geht nicht
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Sued_West1.push_back(new Autos(sued, west, 103.142, 0.75, 23.142)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_West1.push_back(new Autos(sued, west, 103.142, 1.f, 23.142));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_West1.push_back(new Autos(sued, west, 103.142, 2.f, 23.142));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}
}

void SimulationMaster::pushToKreuzungNord()
{
	if (ampel->checkIfGreenNordSued())
	{
		for (auto x : Nord_Ost1)
		{
			if (x->getOriginalFahrtweg() - x->getFahrtWeg() > 40)
			{
				Nord_Ost_Kreuzung1.push_back(x);
			}
		}
		for (auto x : Nord_Sued1)
		{
			if (x->getOriginalFahrtweg() - x->getFahrtWeg() > 40)
			{
				Nord_Sued_Kreuzung1.push_back(x);
			}
		}
		for (auto x : Nord_West1)
		{
			if (x->getOriginalFahrtweg() - x->getFahrtWeg() > 40)
			{
				Nord_West_Kreuzung1.push_back(x);
			}
		}
	}
}

void SimulationMaster::pushToKreuzungOst()
{

}

void SimulationMaster::pushToKreuzungWest()
{

}

void SimulationMaster::pushToKreuzungSued()
{

}

void SimulationMaster::moveAutosVorKreuzung()
{
	if (ampel->checkIfGreenNordSued())//NordSued ist grün
	{
		checkIfInFront();
		if (inFront)
		{

		}
		else
		{

		}
	}
	else if (ampel->checkIfGreenOstWest())//OstWest ist grün
	{
		checkIfInFront();
		if (inFront)
		{

		}
		else
		{

		}
	}
	else//beide sind rot, für diese eine oder zwei sekunden
	{

	}
}