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
	while (ampel->ampelZyklusCounter <= 50) {
		ampel->cycleAmpel();
		updateLists();
		//std::cout << "globalTimer: " << globalTimer.getElapsedTime().asSeconds() << std::endl;
	}
}

void SimulationMaster::updateLists() 
{
	
	spawnAutos();
	allowMovement();
	moveAutos();
	
}

void SimulationMaster::moveAutos()
{
	moveAutosOnKreuzung();
}

void SimulationMaster::moveAutosOnKreuzung()
{
	if (ampel->NordSuedIsGreen)
	{
		moveAutosNord();
		moveAutosSued();
	}
	else if (ampel->OstWestIsGreen)
	{
		moveAutosOst();
		moveAutosWest();
	}
}

void SimulationMaster::moveAutosNord()
{
	for (int i = 0; i < Nord_Kreuzung1.size(); i++)
	{
		if (Nord_Kreuzung1[i]->getY() >= 2) 
		{
			
			
		}


			
	
			Nord_Kreuzung1.erase(Nord_Kreuzung1.begin() + i);
			counterOutSued++;
	}
}

void SimulationMaster::moveAutosSued()
{
	for (int i = 0; i < Sued_Kreuzung1.size(); i++)
	{
		if (Sued_Kreuzung1[i]->getFahrtWeg() >= 0)
		{
			Sued_Kreuzung1[i]->speedUp();
		}
		else
		{
			Sued_Kreuzung1.erase(Sued_Kreuzung1.begin() + i);
		}
	}
}

void SimulationMaster::moveAutosOst()
{
	for (int i = 0; i < Ost_Kreuzung1.size(); i++)
	{
		if (Ost_Kreuzung1[i]->getFahrtWeg() >= 0)
		{
			Ost_Kreuzung1[i]->speedUp();
		}
		else
		{
			Ost_Kreuzung1.erase(Ost_Kreuzung1.begin() + i);
		}
	}
}

void SimulationMaster::moveAutosWest()
{
	for (int i = 0; i < West_Kreuzung1.size(); i++)
	{
		if (West_Kreuzung1[i]->getFahrtWeg() >= 0)
		{
			West_Kreuzung1[i]->speedUp();
		}
		else
		{
			West_Kreuzung1.erase(West_Kreuzung1.begin() + i);
		}
	}
}




void SimulationMaster::spawnAutos()//Fragt die Zufallszahlen ab und füllt dann die entsptrechenden Vektoren
{									//Von da an sind Weg, und Weglänge vorgegeben
									//Spawnt nur wenn die entsprechende Ampel grün ist, erstmal nur 15 Autos pro richtung auf einmal (vereinfachende Annahme)

	randValueType = rand() % 10;
	randValueSpawn = rand() % 100;
	randValueDirection = rand() % 100;

	if (randValueSpawn <=14  && !ampel->NordSuedIsGreen && !ampel->OstWestIsGreen && !ampel->toOstWest && sizeOfVector(Nord_Kreuzung1) <= 15) //Spawn im Norden
	{
		this->spawnAutosNordKreuzung();
	}

	else if (randValueSpawn >= 50 && randValueSpawn < 65 && !ampel->NordSuedIsGreen && !ampel->OstWestIsGreen && !ampel->toOstWest && sizeOfVector(Sued_Kreuzung1) <= 15) //Spawn im Süden
	{
		this->spawnAutosSuedKreuzung();
	}

	else if (randValueSpawn >= 15 && randValueSpawn < 50 && !ampel->NordSuedIsGreen && !ampel->OstWestIsGreen && ampel->toOstWest && sizeOfVector(Ost_Kreuzung1) <= 15) //Spawn im Osten
	{
		this->spawnAutosOstKreuzung();
	}
	
	else if (!ampel->NordSuedIsGreen && !ampel->OstWestIsGreen && ampel->toOstWest && sizeOfVector(West_Kreuzung1) <= 15)//spawn im Westen
	{
		this->spawnAutosWestKreuzung();
	}
}



int SimulationMaster::sizeOfVector(std::vector<Autos*> vec_1)
{
	return vec_1.size();
}




//Autos spawnen quasi direkt auf der Kreuzung und zählen Fahrtweg runter, wenn das erlaubt ist

void SimulationMaster::spawnAutosNordKreuzung()//Spawn Norden
{

	if (randValueDirection <= 9)// Fahr nach Norden
	{
		//Geht nicht
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, Spawnpoint::A, ost, Map::a, 0.75, 2.5 )); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;														//hier müssen die Geraden hin anstatt des Fahrtweges.
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, Spawnpoint::A,ost, Map::a, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else {
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, Spawnpoint::A, ost, Map::a, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
			counterNord++;
		}
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, Spawnpoint::A, sued, Map::a, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, Spawnpoint::A, sued, Map::a, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, Spawnpoint::A, sued, Map::a, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		counterNord++;
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, Spawnpoint::A, west, Map::a ,0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, Spawnpoint::A, west, Map::a, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, Spawnpoint::A, west, Map::a, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		counterNord++;
	}
}


void SimulationMaster::spawnAutosOstKreuzung()//Spawn Osten
{
	if (randValueDirection <= 9)// Fahr nach Norden
	{
		if (randValueType <= 1)
		{
			this->Ost_Kreuzung1.push_back(new Autos(-12 , -6, Spawnpoint::E, nord, Map::e, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_Kreuzung1.push_back(new Autos( - 12, -6, Spawnpoint::E, nord, Map::e, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_Kreuzung1.push_back(new Autos(-12, -6, Spawnpoint::E, nord, Map::e, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden

	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		//geht nicht
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->Ost_Kreuzung1.push_back(new Autos(-12, -2, Spawnpoint::D, sued, Map::d, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_Kreuzung1.push_back(new Autos(-12, -2, Spawnpoint::D, sued, Map::d, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_Kreuzung1.push_back(new Autos(-12, -2, Spawnpoint::D, sued, Map::d, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Ost_Kreuzung1.push_back(new Autos(-12, -6,Spawnpoint::D, west, Map::e, 0.75f, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_Kreuzung1.push_back(new Autos(-12, -6, Spawnpoint::D, west, Map::e, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_Kreuzung1.push_back(new Autos(-12, -6, Spawnpoint::D, west, Map::e, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}
}

void SimulationMaster::spawnAutosWestKreuzung()
{
	if (randValueDirection <= 9)// Fahr nach Norden
	{
		if (randValueType <= 1)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 2, Spawnpoint::C, nord, Map::c, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 2, Spawnpoint::C,nord, Map::c, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Kreuzung1.push_back(new Autos(12, 2, Spawnpoint::C, nord, Map::c, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 2, Spawnpoint::C, ost, Map::c, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 2, Spawnpoint::C, ost, Map::c, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Kreuzung1.push_back(new Autos(12, 2, Spawnpoint::C, ost, Map::c, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 6,Spawnpoint::F, nord, Map::f, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 6, Spawnpoint::F, nord, Map::f, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Kreuzung1.push_back(new Autos(12, 6, Spawnpoint::F, nord, Map::f, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
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
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8,Spawnpoint::B, nord, Map::b, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, Spawnpoint::B ,nord, Map::b, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, Spawnpoint::B , nord, Map::b, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, Spawnpoint::B , ost, Map::b, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, Spawnpoint::B , nord, Map::b, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, Spawnpoint::B , nord, Map::b, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		//geht nicht
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, Spawnpoint::B , west, Map::b, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, Spawnpoint::B , nord, Map::b, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, Spawnpoint::B , nord, Map::b, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}
}


//Für später benötigt, wenn wir Autos an die Kreuzung anfahren lassen wollen
//Alles unterhalb dieses Kommentars ist evtl für später wenn noch Zeit ist das anfahren an die Ampel zu simulieren
