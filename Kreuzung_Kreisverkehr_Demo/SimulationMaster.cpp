#include "SimulationMaster.h"

SimulationMaster::SimulationMaster()
{
}

SimulationMaster::~SimulationMaster()
{
}

void SimulationMaster::run() {
	globalTimer.restart();
	simulationsdauer.restart();
	while (simulationsdauer.getElapsedTime().asSeconds() <= 20) {
		updateLists();
		std::cout << "globalTimer: " << globalTimer.getElapsedTime().asSeconds() << std::endl;
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
		if (x->getFahrtWeg() > 0) 
		{
			x->speedUp();
			std::cout << x->getFahrtWeg() << std::endl;
		}
		else
			counterOutWest++;
	}
}
void SimulationMaster::allowMovement()
{
}

void SimulationMaster::spawnAutos()//Fragt die Zufallszahlen ab und füllt dann die entsptrechenden Vektoren
{									//Von da an sind Weg, und Weglänge vorgegeben

	randValueType = rand() % 10;
	randValueSpawn = rand() % 100;
	randValueDirection = rand() % 100;

	if (randValueSpawn <= 14) //Spawn im Norden
	{
		this->spawnAutosNord();
	}

	else if (randValueSpawn >= 15 && randValueSpawn < 50) //Spawn im Osten
	{
		this->spawnAutosOst();
	}
	else if (randValueSpawn >= 50 && randValueSpawn < 65) //Spawn im Süden
	{
		this->spawnAutosSued();
	}
	else //spawn im Westen
	{
		this->spawnAutosWest();
	}
	
	
	
	
}
		


		

		




	

	/*else if (randValueType >= 2 && randValueType < 9)//Type2 muss spawnen
	{
		if (randValueSpawn <= 14) //Spawn im Norden
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				//Geht nicht
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				this->Nord_Ost2.push_back(new AutosFahrertyp2(nord, ost, 103.142));
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				this->Nord_Sued2.push_back(new AutosFahrertyp2(nord, sued, 96));
			}
			else //Fahr nach Westen
			{
				this->Nord_West2.push_back(new AutosFahrertyp2(nord, west, 95.142));
			}
		}
		else if (randValueSpawn >= 15 && randValueSpawn < 50) //Spawn im Osten
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				this->Ost_Nord2.push_back(new AutosFahrertyp2(ost, nord, 91.142));
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				//geht nicht
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				this->Ost_Sued2.push_back(new AutosFahrertyp2(ost, sued, 95.142));
			}
			else //Fahr nach Westen
			{
				this->Ost_West2.push_back(new AutosFahrertyp2(ost, west, 104));
			}
		}
		else if (randValueSpawn >= 50 && randValueSpawn < 65) //Spawn im Süden
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				this->Sued_Nord2.push_back(new AutosFahrertyp2(sued, nord, 96));
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				this->Sued_Ost2.push_back(new AutosFahrertyp2(sued, ost, 95.142));
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				//geht nicht
			}
			else //Fahr nach Westen
			{
				this->Sued_West2.push_back(new AutosFahrertyp2(sued, west, 103.142));
			}
		}
		else //Spawn im Westen
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				this->West_Nord2.push_back(new AutosFahrertyp2(west, nord, 95.142));
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				this->West_Ost2.push_back(new AutosFahrertyp2(west, ost, 104));
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				this->West_Sued2.push_back(new AutosFahrertyp2(west, sued, 91.142));
			}
			else //Fahr nach Westen
			{
				//Geht nicht
			}
		}
	}


	else//Type3 spawnt
	{
		if (randValueSpawn <= 14) //Spawn im Norden
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				//Geht nicht
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				this->Nord_Ost3.push_back(new AutosFahrertyp3(nord, ost, 103.142));
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				this->Nord_Sued3.push_back(new AutosFahrertyp3(nord, sued, 96));
			}
			else //Fahr nach Westen
			{
				this->Nord_West3.push_back(new AutosFahrertyp3(nord, west, 95.142));
			}
		}
		else if (randValueSpawn >= 15 && randValueSpawn < 50) //Spawn im Osten
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				this->Ost_Nord3.push_back(new AutosFahrertyp3(ost, nord, 91.142));
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				//geht nicht
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				this->Ost_Sued3.push_back(new AutosFahrertyp3(ost, sued, 95.142));
			}
			else //Fahr nach Westen
			{
				this->Ost_West3.push_back(new AutosFahrertyp3(ost, west, 104));
			}
		}
		else if (randValueSpawn >= 50 && randValueSpawn < 65) //Spawn im Süden
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				this->Sued_Nord3.push_back(new AutosFahrertyp3(sued, nord, 96));
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				this->Sued_Ost3.push_back(new AutosFahrertyp3(sued, ost, 95.142));
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				//geht nicht
			}
			else //Fahr nach Westen
			{
				this->Sued_West3.push_back(new AutosFahrertyp3(sued, west, 103.142));
			}
		}
		else //Spawn im Westen
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				this->West_Nord3.push_back(new AutosFahrertyp3(west, nord, 95.142));
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				this->West_Ost3.push_back(new AutosFahrertyp3(west, ost, 104));
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				this->West_Sued3.push_back(new AutosFahrertyp3(west, sued, 91.142));
			}
			else //Fahr nach Westen
			{
				//Geht nicht
			}
		}
	}*/
	//std::cout << counterNord << std::endl;
	//std::cout << counterOst << std::endl;
	//std::cout << counterSued << std::endl;
	//std::cout << counterWest << std::endl;


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
				this->Nord_Ost1.push_back(new Autos(nord, ost, 103.142, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
				counterNord++;
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->Nord_Ost1.push_back(new Autos(nord, ost, 103.142, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
				counterNord++;
			}
			else {
				this->Nord_Ost1.push_back(new Autos(nord, ost, 103.142, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
				counterNord++;
			}
		}

		else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
		{
			if (randValueType <= 1)
			{
				this->Nord_Sued1.push_back(new Autos(nord, sued, 96, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
				counterNord++;
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->Nord_Sued1.push_back(new Autos(nord, sued, 96, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
				counterNord++;
			}
			else
				this->Nord_Sued1.push_back(new Autos(nord, sued, 96, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
			counterNord++;
		}

		else //Fahr nach Westen
		{
			if (randValueType <= 1)
			{
				this->Nord_West1.push_back(new Autos(nord, west, 95.142, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
				counterNord++;
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->Nord_West1.push_back(new Autos(nord, west, 95.142, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
				counterNord++;
			}
			else
				this->Nord_West1.push_back(new Autos(nord, west, 95.142, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
			counterNord++;
		}
}


void SimulationMaster::spawnAutosOst()
{


		if (randValueDirection <= 9)// Fahr nach Norden
		{
			if (randValueType <= 1)
			{
				this->Ost_Nord1.push_back(new Autos(ost, nord, 91.142, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->Ost_Nord1.push_back(new Autos(ost, nord, 91.142, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			}
			else
				this->Ost_Nord1.push_back(new Autos(ost, nord, 91.142, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden

		}

		else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
		{
			//geht nicht
		}

		else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
		{
			if (randValueType <= 1)
			{
				this->Ost_Sued1.push_back(new Autos(ost, sued, 95.142, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->Ost_Sued1.push_back(new Autos(ost, sued, 95.142, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			}
			else
				this->Ost_Sued1.push_back(new Autos(ost, sued, 95.142, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		}

		else //Fahr nach Westen
		{
			if (randValueType <= 1)
			{
				this->Ost_West1.push_back(new Autos(ost, west, 104, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->Ost_West1.push_back(new Autos(ost, west, 104, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			}
			else
				this->Ost_West1.push_back(new Autos(ost, west, 104, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		}
}



void SimulationMaster::spawnAutosWest()
{
		if (randValueDirection <= 9)// Fahr nach Norden
		{
			if (randValueType <= 1)
			{
				this->West_Nord1.push_back(new Autos(west, nord, 103.142, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->West_Nord1.push_back(new Autos(west, nord, 103.142, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			}
			else
				this->West_Nord1.push_back(new Autos(west, nord, 103.142, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		}

		else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
		{
			if (randValueType <= 1)
			{
				this->West_Ost1.push_back(new Autos(west, ost, 104, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->West_Ost1.push_back(new Autos(west, ost, 104, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			}
			else
				this->West_Ost1.push_back(new Autos(west, ost, 104, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		}

		else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
		{
			if (randValueType <= 1)
			{
				this->West_Sued1.push_back(new Autos(west, sued, 91.142, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->West_Sued1.push_back(new Autos(west, sued, 91.142, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			}
			else
				this->West_Sued1.push_back(new Autos(west, sued, 91.142, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
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
				this->Sued_Nord1.push_back(new Autos(sued, nord, 96, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->Sued_Nord1.push_back(new Autos(sued, nord, 96, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			}
			else
				this->Sued_Nord1.push_back(new Autos(sued, nord, 96, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		}

		else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
		{
			if (randValueType <= 1)
			{
				this->Sued_Ost1.push_back(new Autos(sued, ost, 95.142, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->Sued_Ost1.push_back(new Autos(sued, ost, 95.142, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			}
			else
				this->Sued_Ost1.push_back(new Autos(sued, ost, 95.142, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		}

		else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
		{
			//geht nicht
		}

		else //Fahr nach Westen
		{
			if (randValueType <= 1)
			{
				this->Sued_West1.push_back(new Autos(sued, west, 103.142, 0.75)); // Spawn Fahrertyp 1, Reaktionszeit 0.75 sekunden
			}
			else if (randValueType >= 2 && randValueType < 9)
			{
				this->Sued_West1.push_back(new Autos(sued, west, 103.142, 1.f));// Spawn Fahrertyp 2, Reaktionszeit 1 sekunde
			}
			else
				this->Sued_West1.push_back(new Autos(sued, west, 103.142, 2.f));//Spawn Fahrertyp 3, Reaktionszeit 2 sekunden
		}
}


