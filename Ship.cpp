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
	setName("My Ship");
	docked = false;
	cout << "Ship constructor executed" << endl;
	//	location = 0;
	//	offers = "";
	//	station = new Station();
	bacon = new Bacon();
	bacon->getAmount();

	//building a station
	vector<InventoryItem> inventory;

	inventory.push_back(*(new InventoryItem(
		"Warp Manifolds", 4200,
		"These warp manifolds are slightly used but will work great after a good theta radiation decon!",
		1
		)));
	inventory.push_back(*(new InventoryItem(
		"Freeze dried McRibs", 210,
		"A delicacy of our ancestors. Was part of a regular ritual. Only a few thousand in this sector!!",
		2
		)));
	inventory.push_back(*(new InventoryItem(
		"CryPax", -1000,
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

Ship::~Ship() {
	cout << "Ship destructor executed" << endl;
}

vector<string> Ship::getInventory() {//could just be a conversion
	vector<string> inventory; //conversion works, but cant convert with containers. not sure why.
	for (InventoryItem item : manifest) {
		inventory.push_back(item);
	}
	return inventory;
}

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

void Ship::setName(const std::string& n) {
	name = n;
}

//void Ship::setLocation(const Station & s) {
//	*location = s;
//}
//
//Station Ship::getLocation() {
//	return *location;
//}

string Ship::getName() const {
	return name;
}

int Ship::getBacon() {
	return bacon->getAmount();
}

//sent to SpaceThing
//bool Ship::isDocked() {
//	return docked;
//}
//
//void Ship::dock() {
//	docked = true;
//	cout << "Docking" << endl;
//}

//void Ship::buySupplies() {
//	cout << "Buying Supplies" << endl;
//	offers = location->buyMenu();
//}
//
//void Ship::sellSupplies() {
//	cout << "Selling Supplies" << endl;
//	offers = location->sellMenu();
//}

void Ship::fireCrewMember() {
	cout << "Firing Crew" << endl;
}

void Ship::viewPassengers() {
	cout << "Viewing Passengers" << endl;
}

//void Ship::viewCrew() {
//	cout << "Viewing Crew" << endl;
//	== == == =


