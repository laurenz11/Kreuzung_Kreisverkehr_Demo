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
	for (int i = 0; i < Nord_Sued_Move1.size(); i++)
	{
		if (Nord_Sued_Move1[i]->getFahrtWeg() )
		{
			Nord_Sued_Move1[i]->speedUp();
		}
		else
		{
			Nord_Sued_Move1.erase(Nord_Sued_Move1.begin() + i);
			counterOutSued++;
		}
	}
	for (int i = 0; i < Nord_West_Move1.size(); i++)
	{
		if (Nord_West_Move1[i]->getFahrtWeg() >= 0)
		{
			Nord_West_Move1[i]->speedUp();
		}
		else
		{
			Nord_West_Move1.erase(Nord_West_Move1.begin() + i); 
		}
	}
	for (int i = 0; i < Nord_Ost_Move1.size(); i++)
	{
		if (Nord_Ost_Move1[i]->getFahrtWeg() >= 0)
		{
			Nord_Ost_Move1[i]->speedUp();
		}
		else
		{
			Nord_Ost_Move1.erase(Nord_Ost_Move1.begin() + i);
			counterOutOst++;
		}
	}
}

void SimulationMaster::moveAutosSued()
{
	for (int i = 0; i < Sued_Nord_Move1.size(); i++)
	{
		if (Sued_Nord_Move1[i]->getFahrtWeg() >= 0)
		{
			Sued_Nord_Move1[i]->speedUp();
		}
		else
		{
			Sued_Nord_Move1.erase(Sued_Nord_Move1.begin() + i);
		}
	}
	for (int i = 0; i < Sued_West_Move1.size(); i++)
	{
		if (Sued_West_Move1[i]->getFahrtWeg() >= 0)
		{
			Sued_West_Move1[i]->speedUp();
		}
		else
		{
			Sued_West_Move1.erase(Sued_West_Move1.begin() + i);
		}
	}
	for (int i = 0; i < Sued_Ost_Move1.size(); i++)
	{
		if (Sued_Ost_Move1[i]->getFahrtWeg() >= 0)
		{
			Sued_Ost_Move1[i]->speedUp();
		}
		else
		{
			Sued_Ost_Move1.erase(Sued_Ost_Move1.begin() + i);
			counterOutOst++;
		}
	}
}

void SimulationMaster::moveAutosOst()
{
	for (int i = 0; i < Ost_Nord_Move1.size(); i++)
	{
		if (Ost_Nord_Move1[i]->getFahrtWeg() >= 0)
		{
			Ost_Nord_Move1[i]->speedUp();
		}
		else
		{
			Ost_Nord_Move1.erase(Ost_Nord_Move1.begin() + i);
		}
	}
	for (int i = 0; i < Ost_West_Move1.size(); i++)
	{
		if (Ost_West_Move1[i]->getFahrtWeg() >= 0)
		{
			Ost_West_Move1[i]->speedUp();
		}
		else
		{
			Ost_West_Move1.erase(Ost_West_Move1.begin() + i);
		}
	}
	for (int i = 0; i < Ost_Sued_Move1.size(); i++)
	{
		if (Ost_Sued_Move1[i]->getFahrtWeg() >= 0)
		{
			Ost_Sued_Move1[i]->speedUp();
		}
		else
		{
			Ost_Sued_Move1.erase(Ost_Sued_Move1.begin() + i);
			counterOutSued++;
		}
	}
}

void SimulationMaster::moveAutosWest()
{
	for (int i = 0; i < West_Nord_Move1.size(); i++)
	{
		if (West_Nord_Move1[i]->getFahrtWeg() >= 0)
		{
			West_Nord_Move1[i]->speedUp();
		}
		else
		{
			West_Nord_Move1.erase(West_Nord_Move1.begin() + i);
		}
	}
	for (int i = 0; i < West_Ost_Move1.size(); i++)
	{
		if (West_Ost_Move1[i]->getFahrtWeg() >= 0)
		{
			West_Ost_Move1[i]->speedUp();
		}
		else
		{
			West_Ost_Move1.erase(West_Ost_Move1.begin() + i);
			counterOutOst++;
		}
	}
	for (int i = 0; i < West_Sued_Move1.size(); i++)
	{
		if (West_Sued_Move1[i]->getFahrtWeg() >= 0)
		{
			West_Sued_Move1[i]->speedUp();
		}
		else
		{
			West_Sued_Move1.erase(West_Sued_Move1.begin() + i);
			counterOutSued++;
		}
	}
}

void SimulationMaster::allowMovement()
{
	if (!ampel->NordSuedIsGreen && !ampel->OstWestIsGreen && !ampel->toOstWest)
	{
		allowMovementNord();
		allowMovementSued();
	}

	else if (!ampel->NordSuedIsGreen && !ampel->OstWestIsGreen && ampel->toOstWest)
	{
		allowMovementOst();
		allowMovementWest();
	}
}

void SimulationMaster::allowMovementNord()
{
	for (int i = 0; i < Nord_Kreuzung1.size(); i++)
	{
	
			if (Nord_Kreuzung1[i]->getDirection() == west)
			{
				Nord_West_Move1.push_back(Nord_Kreuzung1[i]);
				Nord_Kreuzung1.erase(Nord_Kreuzung1.begin() + i);
			}
			else if (Nord_Kreuzung1[i]->getDirection() == sued)
			{
				Nord_Sued_Move1.push_back(Nord_Kreuzung1[i]);
				Nord_Kreuzung1.erase(Nord_Kreuzung1.begin() + i);
			}
			else
			{
				checkKreuzungNord_Ost();
				if (Nord_OstFree)
				{
					Nord_Ost_Move1.push_back(Nord_Kreuzung1[i]);
					Nord_Kreuzung1.erase(Nord_Kreuzung1.begin() + i);
				}
			}
	}
}

void SimulationMaster::allowMovementSued()
{
	for (int i = 0; i < Sued_Kreuzung1.size(); i++)
	{

		if (Sued_Kreuzung1[i]->getDirection() == ost)
		{
			Sued_Ost_Move1.push_back(Sued_Kreuzung1[i]);
			Sued_Kreuzung1.erase(Sued_Kreuzung1.begin() + i);
		}
		else if (Sued_Kreuzung1[i]->getDirection() == nord)
		{
			Sued_Nord_Move1.push_back(Sued_Kreuzung1[i]);
			Sued_Kreuzung1.erase(Sued_Kreuzung1.begin() + i);
		}
		else
		{
			checkKreuzungSued_West();
			if (Sued_WestFree)
			{
				Sued_West_Move1.push_back(Sued_Kreuzung1[i]);
				Sued_Kreuzung1.erase(Sued_Kreuzung1.begin() + i);
			}
		}

	}
}

void SimulationMaster::allowMovementWest()
{
	for (int i = 0; i < West_Kreuzung1.size(); i++)
	{

		if (West_Kreuzung1[i]->getDirection() == ost)
		{
			West_Ost_Move1.push_back(West_Kreuzung1[i]);
			West_Kreuzung1.erase(West_Kreuzung1.begin() + i);
		}
		else if (West_Kreuzung1[i]->getDirection() == sued)
		{
			West_Sued_Move1.push_back(West_Kreuzung1[i]);
			West_Kreuzung1.erase(West_Kreuzung1.begin() + i);
		}
		else
		{
			checkKreuzungWest_Nord();
			if (West_NordFree)
			{
				West_Nord_Move1.push_back(West_Kreuzung1[i]);
				West_Kreuzung1.erase(West_Kreuzung1.begin() + i);
			}
		}

	}
}

void SimulationMaster::allowMovementOst()
{
	for (int i = 0; i < Ost_Kreuzung1.size(); i++)
	{

		if (Ost_Kreuzung1[i]->getDirection() == west)
		{
			Ost_West_Move1.push_back(Ost_Kreuzung1[i]);
			Ost_Kreuzung1.erase(Ost_Kreuzung1.begin() + i);
		}
		else if (Ost_Kreuzung1[i]->getDirection() == nord)
		{
			Ost_Nord_Move1.push_back(Ost_Kreuzung1[i]);
			Ost_Kreuzung1.erase(Ost_Kreuzung1.begin() + i);
		}
		else
		{
			checkKreuzungOst_Sued();
			if (Ost_SuedFree)
			{
				Ost_Sued_Move1.push_back(Ost_Kreuzung1[i]);
				Ost_Kreuzung1.erase(Ost_Kreuzung1.begin() + i);
			}
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



void SimulationMaster::checkKreuzungNord_Ost()
{
	if (Sued_Nord_Move1.empty() && Sued_Ost_Move1.empty())
	{
		Nord_OstFree = true;
	}
	else
		Nord_OstFree = false;
}

void SimulationMaster::checkKreuzungSued_West()
{
	if (Nord_Sued_Move1.empty() && Nord_West_Move1.empty())
	{
		Sued_WestFree = true;
	}
	else
		Sued_WestFree = false;
}

void SimulationMaster::checkKreuzungWest_Nord()
{
	if (Ost_West_Move1.empty() && Ost_Nord_Move1.empty())
	{
		West_NordFree = true;
	}
	else
		West_NordFree = false;
}

void SimulationMaster::checkKreuzungOst_Sued()
{
	if (West_Ost_Move1.empty() && West_Sued_Move1.empty())
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
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, ost, Map::a, 0.75, 2.5 )); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;														//hier müssen die Geraden hin anstatt des Fahrtweges.
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, ost, Map::a, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else {
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, ost, Map::a, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
			counterNord++;
		}
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, sued, Map::a, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, sued, Map::a, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, sued, Map::a, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		counterNord++;
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, west, Map::a ,0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			counterNord++;
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, west, Map::a, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			counterNord++;
		}
		else
			this->Nord_Kreuzung1.push_back(new Autos(2, -8, west, Map::a, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		counterNord++;
	}
}


void SimulationMaster::spawnAutosOstKreuzung()
{
	if (randValueDirection <= 9)// Fahr nach Norden
	{
		if (randValueType <= 1)
		{
			this->Ost_Kreuzung1.push_back(new Autos(-12 , -6, nord, Map::e, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_Kreuzung1.push_back(new Autos( - 12, -6, nord, Map::e, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_Kreuzung1.push_back(new Autos(-12, -6, nord, Map::e, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden

	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		//geht nicht
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->Ost_Kreuzung1.push_back(new Autos(-12, -2, sued, Map::d, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_Kreuzung1.push_back(new Autos(-12, -2, sued, Map::d, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_Kreuzung1.push_back(new Autos(-12, -2, sued, Map::d, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Ost_Kreuzung1.push_back(new Autos(-12, -6, west, Map::e, 0.75f, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Ost_Kreuzung1.push_back(new Autos(-12, -6, west, Map::e, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Ost_Kreuzung1.push_back(new Autos(-12, -6, west, Map::e, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}
}

void SimulationMaster::spawnAutosWestKreuzung()
{
	if (randValueDirection <= 9)// Fahr nach Norden
	{
		if (randValueType <= 1)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 2, nord, Map::d, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 2, nord, Map::d, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Kreuzung1.push_back(new Autos(12, 2, nord, Map::d, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 2, ost, Map::d, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 2, ost, Map::d, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Kreuzung1.push_back(new Autos(12, 2, ost, Map::d, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		if (randValueType <= 1)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 6, nord, Map::f, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->West_Kreuzung1.push_back(new Autos(12, 6, nord, Map::f, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->West_Kreuzung1.push_back(new Autos(12, 6, nord, Map::f, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
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
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, nord, Map::b, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, nord, Map::b, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, nord, Map::b, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
	{
		if (randValueType <= 1)
		{
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, ost, Map::b, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, nord, Map::b, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, nord, Map::b, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}

	else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
	{
		//geht nicht
	}

	else //Fahr nach Westen
	{
		if (randValueType <= 1)
		{
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, west, Map::b, 0.75, 2.5)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
		}
		else if (randValueType >= 2 && randValueType < 9)
		{
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, nord, Map::b, 1.f, 2.5));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
		}
		else
			this->Sued_Kreuzung1.push_back(new Autos(-2, 8, nord, Map::b, 2.f, 2.5));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
	}
}


//Für später benötigt, wenn wir Autos an die Kreuzung anfahren lassen wollen
//Alles unterhalb dieses Kommentars ist evtl für später wenn noch Zeit ist das anfahren an die Ampel zu simulieren
