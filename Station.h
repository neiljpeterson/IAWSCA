#ifndef STATION_H
#define STATION_H

//
//  File:         STATION.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Ship.
//

#include "DockingRequest.h"
#include <iostream>
#include <string>
#include <vector>
<<<<<<< HEAD

class Bacon;

class Station {
=======
#include "InventoryItem.h"
#include "SpaceThing.h"

using namespace std;

class Station: public SpaceThing {


>>>>>>> origin/SpaceThing
public:

	Station();
	Station(vector<InventoryItem> inventory){};
	~Station();
<<<<<<< HEAD

	void sendDockingFee(DockingRequest);
	std::string buyMenu();
	std::string sellMenu();
	int numberToBuy(const std::string &, int);
	int chooseToBuy(int, int);
	int numberToSell(const std::string &, int);
	int chooseToSell(int, int);
	int menu(std::vector<std::string>&);
	int getIntWithinRange(int, int, std::string);
	void displayPassengers();
	void deletePassenger();
	void displayPositions();
	void deleteCrewMember();
	int getPrice();

private:
	std::string name;
	int dockingFee;
	int stationID;
	int price;
	std::string offer;
=======
        
private:
	

>>>>>>> origin/SpaceThing
};

#endif