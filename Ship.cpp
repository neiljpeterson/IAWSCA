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
	
	manifest = new set<InventoryItem>;
	docked = true;
	
	cout << "Ship constructor executed" << endl;
	
	
	//building a station
	vector<InventoryItem> inventory;
	
	inventory.push_back(*(new InventoryItem(
		"Warp Manifolds",4200,"These warp manifolds are slightly used but will work great after a good theta radiation decon!"
		)));
	inventory.push_back(*(new InventoryItem(
	"Freeze dried McRibs",210,"A delicacy of our ancestors. Was part of a regular ritual. Only a few thousand in this sector!!"
		)));
	inventory.push_back(*(new InventoryItem(
	"CryPax",-1000,"This Cryogenic Passenger with federation passage to A579bg"
		)));
	station = *(new Station(inventory));
	
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
void Ship::setName(const std::string& n) {
	name = n;
}

bool Ship::isDocked() {
	return docked;
}

void Ship::dock() {
	docked = true;
	cout << "Docking" << endl;
}

void Ship::buySupplies() {
	cout << "Buying Supplies" << endl;
}


vector<InventoryItem> Ship::getStationOffers() {
	//return station.getOffers();
	return *(new vector<InventoryItem>);
}

vector<string> Ship::getStationAds() {
	
	return station.getAds();
}

void Ship::buy(int itemNum) {//or referenceCode? 
	station.sellItem(itemNum);
}

void Ship::buy(int itemNum) {//or referenceCode? 
	InventoryItem newItem = station.sellItem(itemNum,station.getItemPrice());
	manifest.insert(newItem);
}
void Ship::sell() {
	cout << "Selling Supplies" << endl;
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