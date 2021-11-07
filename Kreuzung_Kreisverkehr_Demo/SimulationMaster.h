#pragma once
#include "AutosFahrertyp1.h"
#include "AutosFahrertyp2.h"
#include "AutosFahrertyp3.h"
#include "time.h"
#include "Ampel.h"

class SimulationMaster
{
public: 

	int randValueType;//Zufallszahl f�r die Entscheidung, welcher Fahrertyp gespawnt wird
	int randValueSpawn;//Zufallszahl f�r Anfahrtsrichtung(Spawn)
	int randValueDirection; // Zufallszahl f�r die Zielrichtung (Direction)

	void run();

	void updateLists();

	void moveAutos();//soll Autos mit den Funktionen speedUp slowDown etc. bewegen
	void moveAutosOnKreuzung();
	void moveAutosVorKreuzung();//f�r nachher
	void moveAutosNachKreuzung();

	void allowMovement(); //soll noch vor moveAutos abgefragt werden, und �berpr�ft f�r jedes Auto, ob zum Beispiel die Ampel rot ist, ein Auto davor ist, oder Abbiegen m�glich ist.
	bool checkAmpelNordSued();//�berpr�ft, ob die Ampel NordSued gr�n ist
	bool checkAmpelOstWest();//""
	void checkIfInFront();//�berpr�ft, ob sich ein Auto vor demjenigen befindet, dass gerade losfahren soll
	bool inFront();//speichert f�r checkIfInFront, ob fahren erlaubt ist
	//Sollen �berpr�fen, ob die Kreuzung f�r die Richtungn im Funktionsnamen frei ist, also ob die Gegenfahrbahn leer ist
	void checkKreuzungNord_Ost();
	bool Nord_OstFree;
	void checkKreuzungSued_West();
	bool Sued_WestFree;
	void checkKreuzungWest_Nord();
	bool West_NordFree;
	void checkKreuzungOst_Sued();
	bool Ost_SuedFree;


	void spawnAutos(); //setzt Autos "zuf�llig" in die Vektoren
	void spawnAutosNord();
	void spawnAutosSued();
	void spawnAutosWest();
	void spawnAutosOst();

	void pushToKreuzung();


	SimulationMaster();
	~SimulationMaster();

	//Vectoren/Listen f�r die Autos, unterteilt nach Fahrertypen, insgesamt 36 Vectoren(f�r jede Kombi Fahrertyp, Spawn, Richtung)
	std::vector<Autos*> Nord_West1;//Nord: Spawn, West: Richtung 
	std::vector<Autos*> Nord_Ost1;// Nord: Spawn, Ost: Richtung
	std::vector<Autos*> Nord_Sued1;

	std::vector<Autos*> Sued_West1;
	std::vector<Autos*> Sued_Ost1;
	std::vector<Autos*> Sued_Nord1;

	std::vector<Autos*> Ost_West1;
	std::vector<Autos*> Ost_Sued1;
	std::vector<Autos*> Ost_Nord1;

	std::vector<Autos*> West_Ost1;
	std::vector<Autos*> West_Sued1;
	std::vector<Autos*> West_Nord1;

	//Vectoren/Listen f�r Autos, die auf die Kreuzung gefahren sind
	std::vector<Autos*> Nord_West_Kreuzung1;//Nord: Spawn, West: Richtung 
	std::vector<Autos*> Nord_Ost_Kreuzung1;// Nord: Spawn, Ost: Richtung
	std::vector<Autos*> Nord_Sued_Kreuzung1;

	std::vector<Autos*> Sued_West_Kreuzung1;
	std::vector<Autos*> Sued_Ost_Kreuzung1;
	std::vector<Autos*> Sued_Nord_Kreuzung1;

	std::vector<Autos*> Ost_West_Kreuzung1;
	std::vector<Autos*> Ost_Sued_Kreuzung1;
	std::vector<Autos*> Ost_Nord_Kreuzung1;

	std::vector<Autos*> West_Ost_Kreuzung1;
	std::vector<Autos*> West_Sued_Kreuzung1;
	std::vector<Autos*> West_Nord_Kreuzung1;
	
	//Einf�gen der Ampelschaltung
	Ampel* ampel;
	void initAmpel();

	/*Vectoren f�r Fahrertyp2
	std::vector<Autos*> Nord_West2;
	std::vector<Autos*> Nord_Ost2;
	std::vector<Autos*> Nord_Sued2;

	std::vector<AutosFahrertyp2*> Sued_West2;
	std::vector<AutosFahrertyp2*> Sued_Ost2;
	std::vector<AutosFahrertyp2*> Sued_Nord2;

	std::vector<AutosFahrertyp2*> Ost_West2;
	std::vector<AutosFahrertyp2*> Ost_Sued2;
	std::vector<AutosFahrertyp2*> Ost_Nord2;

	std::vector<AutosFahrertyp2*> West_Ost2;
	std::vector<AutosFahrertyp2*> West_Sued2;
	std::vector<AutosFahrertyp2*> West_Nord2;

	//Vectoren f�r Fahrertyp3
	std::vector<AutosFahrertyp3*> Nord_West3;
	std::vector<AutosFahrertyp3*> Nord_Ost3;
	std::vector<AutosFahrertyp3*> Nord_Sued3;

	std::vector<AutosFahrertyp3*> Sued_West3;
	std::vector<AutosFahrertyp3*> Sued_Ost3;
	std::vector<AutosFahrertyp3*> Sued_Nord3;

	std::vector<AutosFahrertyp3*> Ost_West3;
	std::vector<AutosFahrertyp3*> Ost_Sued3;
	std::vector<AutosFahrertyp3*> Ost_Nord3;

	std::vector<AutosFahrertyp3*> West_Ost3;
	std::vector<AutosFahrertyp3*> West_Sued3;
	std::vector<AutosFahrertyp3*> West_Nord3;*/

	//globaler Timer f�r die Zeitmessung
	sf::Clock globalTimer;


private:
	
	sf::Clock simulationsdauer;//Nachher im GUI �ndern lassen

	//Z�hler f�r die gespawnten Autos initialisieren,
	int counterNord = 0;
	int counterOst = 0;
	int counterWest = 0;
	int counterSued = 0;

	//Z�hler f�r die Autos, die die Simulation verlassen haben
	int counterOutNord = 0;
	int counterOutOst = 0;
	int counterOutWest = 0;
	int counterOutSued = 0;

	//Bezeichner f�r die Richtung und den Spawn der Autos
	std::string nord;
	std::string ost;
	std::string west;
	std::string sued;
};

