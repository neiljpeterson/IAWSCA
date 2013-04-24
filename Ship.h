#ifndef SHIP_H
#define SHIP_H

//
//  File:         Ship.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Ship.
//
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include "Station.h"
#include "InventoryItem.h"
#include "SpaceThing.h"

using namespace std;

class Ship: public SpaceThing {
public:
	Ship(); //Default Constructor

	~Ship();

	


	
	//transfered to SpaceThing
//	std::string getName() const;	
//	void setName(const std::string& n);
//	void buySupplies();
//	void sell();
//	vector<string> getExternalAds();
//	void buy(int);
//	void buyItem(int);
//	bool isDocked();
//	void dock();
	
	vector<string> getInventory();
	
	void loadPassengers();
	void unloadPassengers();
	void hireCrewMember();
	void fireCrewMember(); //new
	void travelToStation();

	// views need to deleted
	void viewMessage();
	void viewInventory();
	void viewPassengers(); //new
	void viewCrew();

	/**
	 *  Access function to get the name of the ship
	 */
	

private:

	/**
	 *  Name of Ship
	 */
	std::string name;
	
	//transfered to space thing
//	bool docked;
//	SpaceThing * station = dockedThing; // current station

};

#endif
