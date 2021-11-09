#pragma once
#include "Point.h"
#include "Gerade.h"
class Map
{
public :
	Map();
	~Map();

	void createKreuzung();

	void createKreisverkehr();

	Point point1;
	Point point2;
	Point point3;
	Point point4;
	Point point5;
	Point point6;
	Point point7;
	Point point8;
	Point point9;
	Point point10;
	Point point11;
	Point point12;

	Gerade a;
	Gerade b;
	Gerade c;
	Gerade d;
	Gerade e;
	Gerade f;


	//Strecken erstellen
	Gerade strecke1;//Gerade, auf der das Auto zuerst fahren soll
	Gerade strecke2;//Gerade, auf der das Auto als zweites Fahren soll

	void createOst_West();//bei denen ist strecke1 gleich strecke2
	void createSued_Nord();
	void createNord_Sued();
	void createWest_Ost();


	void createWest_Sued();//Die Fahrstreifen mit extra abbiegespuren
	void createOst_Nord();


	void createOst_Nord();
	void createOst_Sued();

	void createNord_Ost();
	void createNord_West();
	void createSued_Ost();
	void createSued_West();



	
};

