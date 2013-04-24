#ifndef SHIP_H
#define SHIP_H

//
//  File:         Ship.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Ship.
//





#include "Alert.h"
#include "Bacon.h"
#include "Captain.h"
#include "CargoItem.h"
#include "Crew.h"
#include "CrewMember.h"
#include "DockingRequest.h"
#include "Fuel.h"
#include "Inventory.h"
#include "Message.h"
#include "Messenger.h"
#include "Passenger.h"
#include "Supplies.h"
#include "Station.h"
#include "Transmission.h"
#include "Station.h"
#include "InventoryItem.h"
#include "SpaceThing.h"

#include <iostream>
#include <string>
#include <vector>
#include <set>


using namespace std;

class Ship : public SpaceThing {
public:
	Ship(); //Default Constructor

	~Ship();

	vector<string> getInventory();

	void loadPassengers();
	void unloadPassengers();
	void hireCrewMember();
	void fireCrewMember(); //new
	void travelToStation();

	//merged from B
	bool isDocked();
	void dock(SpaceThing&);
	void buySupplies();
	void sellSupplies();
	void viewMessage();
	void viewInventory();
	void viewPassengers();
	void viewCrew();
	int getBacon();
	string getOffers(Station*);
	string getName() const;
	string setName(const string&);

	void setLocation(const Station & s);
	Station getLocation();

private:
	//this is only needed if station adds to SpaceThing
	//SpaceThing * station = dockedThing; // current station

	string name;
	int maxWeight;
	int currentWeight;
	bool docked;
	//Station* location;
	//string offers;
	//Station* station;
	Bacon* bacon;

};

#endif