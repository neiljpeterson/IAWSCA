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
#include "Inventory.h"
#include <iostream>
#include <string>
#include <vector>

class Station {

public:

	Station();
	~Station();

	Inventory getOffers();
	void sendDockingFee(DockingRequest);
	void showOffers();
	void displayPassengers();
	void deletePassenger();
	void displayPositions();
	void deleteCrewMember();

private:
	std::string name;
	int dockingFee;
	int stationID;
	std::vector<Inventory*> supplies;
};

#endif