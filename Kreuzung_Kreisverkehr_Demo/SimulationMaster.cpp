#include "SimulationMaster.h"

SimulationMaster::SimulationMaster()
{

}

SimulationMaster::~SimulationMaster()
{
}

void SimulationMaster::run() {
	while (simulationsdauer.getElapsedTime().asSeconds() <= 5) {
		updateLists();
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
}
void SimulationMaster::allowMovement()
{
}

void SimulationMaster::spawnAutos()//Fragt die Zufallszahlen ab und füllt dann die entsptrechenden Vektoren
{									//Von da an sind Weg, und Weglänge vorgegeben

	randValueType = rand() % 10;
	randValueSpawn = rand() % 100;
	randValueDirection = rand() % 100;
	
	if (randValueType <= 1)//Type1 muss gespawnt werden
	{
		if (randValueSpawn <= 14) //Spawn im Norden
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				//Geht nicht
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				this->Nord_Ost1.push_back(new AutosFahrertyp1(nord, ost, 103.142));
				counterNord++;
			}
			else if (randValueDirection >= 50 && randValueDirection <=59) //Fahr nach Sueden
			{
				this->Nord_Sued1.push_back(new AutosFahrertyp1(nord, sued, 96));
				counterNord++;
			}
			else //Fahr nach Westen
			{
				this->Nord_West1.push_back(new AutosFahrertyp1(nord, west, 95.142));
				counterNord++;
			}
		}
		else if (randValueSpawn >= 15 && randValueSpawn < 50) //Spawn im Osten
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				this->Ost_Nord1.push_back(new AutosFahrertyp1(ost, nord, 91.142));
				counterOst++;
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				//geht nicht
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				this->Ost_Sued1.push_back(new AutosFahrertyp1(ost, sued, 95.142));
				counterOst++;
			}
			else //Fahr nach Westen
			{
				this->Ost_West1.push_back(new AutosFahrertyp1(ost, west, 104));
				counterOst++;
			}
		}
		else if (randValueSpawn >= 50 && randValueSpawn < 65 ) //Spawn im Süden
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				this->Sued_Nord1.push_back(new AutosFahrertyp1(sued, nord, 96));
				counterSued++;
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				this->Sued_Ost1.push_back(new AutosFahrertyp1(sued, ost, 95.142));
				counterSued++;
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				//geht nicht
			}
			else //Fahr nach Westen
			{
				this->Sued_West1.push_back(new AutosFahrertyp1(sued, west, 103.142));
				counterSued++;
			}
		}
		else //Spawn im Westen
		{
			if (randValueDirection <= 9)// Fahr nach Norden
			{
				this->West_Nord1.push_back(new AutosFahrertyp1(west, nord, 95.142));
				counterWest++;
			}
			else if (randValueDirection >= 10 && randValueDirection <= 9) //Fahr nach Osten
			{
				this->West_Ost1.push_back(new AutosFahrertyp1(west, ost, 104));
				counterWest++;
			}
			else if (randValueDirection >= 50 && randValueDirection <= 59) //Fahr nach Sueden
			{
				this->West_Sued1.push_back(new AutosFahrertyp1(west, sued, 91.142));
				counterWest++;
			}
			else //Fahr nach Westen
			{
				//Geht nicht
			}
		}
	}


	else if (randValueType >= 2 && randValueType < 9)//Type2 muss spawnen
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
	}
	std::cout << counterNord << std::endl;
	std::cout << counterOst << std::endl;
	std::cout << counterSued << std::endl;
	std::cout << counterWest << std::endl;
}

