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
#include "Supplies.h"
#include <iostream>
#include <string>
#include <vector>

class Station {

public:

	Station();
	~Station();

	std::string getOffers();
	void sendDockingFee(DockingRequest);
	std::string showOffers();
	void displayPassengers();
	void deletePassenger();
	void displayPositions();
	void deleteCrewMember();

private:
	std::string name;
	int dockingFee;
	int stationID;
	Supplies* supplies;
	std::string offer;
};

#endif