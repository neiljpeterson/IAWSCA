//
//  File:         Store.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Non-inline member function definitions.
//
#include "Ship.h"
#include "vector"
#include "Station.h"
#include <fstream>
using namespace std;

/**
 *  Constructor
 */
Ship::Ship() {
	//initialization should be delegated to the main()
	setName("USS Behind Schedule");
	
	//manifest = new set<InventoryItem>;
	
	cout << "Ship constructor executed" << endl;
	
	
	//building a station
	vector<InventoryItem> inventory;
	
	inventory.push_back(*(new InventoryItem(
		"Warp Manifolds",4200,
		"These warp manifolds are slightly used but will work great after a good theta radiation decon!",
		1
		)));
	inventory.push_back(*(new InventoryItem(
		"Freeze dried McRibs",210,
		"A delicacy of our ancestors. Was part of a regular ritual. Only a few thousand in this sector!!",
		2
		)));
	inventory.push_back(*(new InventoryItem(
		"CryPax",-1000,
		"This Cryogenic Passenger with federation passage to A579bg",
		3
		)));
	
	dockedThing = new SpaceThing(inventory);
	
	//docking
	dockedThing->dock(*this);
	this->dock(*dockedThing);
	dockedThing->setName("STATION");
	
	//manifest
	
	
}
/**
 *  Destructor
 */
Ship::~Ship() {
	cout << "Ship destructor executed" << endl;
}

/**
 *  Modifier function to set the name of the store
 */

//transfered to Spacething. delete before merge
//void Ship::buySupplies() {
//	cout << "Buying Supplies" << endl;
//}

//void Ship::setName(const std::string& n) {
//	name = n;
//}

//vector<string> Ship::getExternalAds() {
//	return station.getAds();
//}

//void Ship::buy(int id) {//or referenceCode? 
//	InventoryItem newItem = station.sellItem(id,station.getItemPrice(id));
//	manifest.insert(newItem);
//}

//void Ship::sell() {
//	cout << "Selling Supplies" << endl;
//}

void Ship::loadPassengers() {
	cout << "Loading Passengers" << endl;
}

void Ship::unloadPassengers() {
	cout << "Unloading Passengers" << endl;
}

void Ship::hireCrewMember() {
	cout << "Hiring Crew" << endl;
}

void Ship::travelToStation() {
	docked = false;
	cout << "Traveling to Station" << endl;
}

void Ship::viewMessage() {
	cout << "Viewing Messages" << endl;
}

void Ship::viewInventory() {
	cout << "Viewing Inventory" << endl;
}