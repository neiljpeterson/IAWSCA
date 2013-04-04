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
using namespace std;

static struct supplies{ //TODO: roll this into the class
		vector<string> itemNames;
		vector<int> prices;
	} supplyItems;

class Station {


public:

	Station();
	~Station();

	supplies getOffers();
	void sendDockingFee(DockingRequest);
	void showOffers();
	void displayPassengers();
	void deletePassenger();
	void displayPositions();
	void deleteCrewMember();

private:
	string name();
	int dockingFee();
	int stationID();
};

#endif