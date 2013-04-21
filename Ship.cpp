//
//  File:         Store.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Non-inline member function definitions.
//
#include "Ship.h"
#include "Station.h"
#include <fstream>
using namespace std;

/**
 *  Constructor
 */
Ship::Ship()
{
    setName("My Ship");
    docked = false;
    cout << "Ship constructor executed" << endl;
	location = 0;
	offers = "";
	station = new Station();
	bacon = new Bacon();
	bacon->getAmount();
}

/**
 *  Destructor
 */
Ship::~Ship()
{
    cout << "Ship destructor executed" << endl;
}

/**
 *  Modifier function to set the name of the store
 */
void Ship::setName(const std::string& n)
{
    name = n;
}

void Ship::setLocation(const Station & s)
{
	*location = s;
}
	
Station Ship::getLocation()
{
	return *location;
}

string Ship::getName() const
{
	return name;
}

int Ship::getBacon()
{
	return bacon->getAmount();
}

bool Ship::isDocked()
{
	return docked;
}

void Ship::dock()
{
  docked = true;
  cout << "Docking" << endl;
}

void Ship::buySupplies()
{
	cout << "Buying Supplies" << endl;
	offers = location->buyMenu();
}

void Ship::sellSupplies(){
	cout << "Selling Supplies" << endl;
	offers = location->sellMenu();
}

void Ship::loadPassengers(){
  cout << "Loading Passengers" << endl;
}

void Ship::unloadPassengers(){
  cout << "Unloading Passengers" << endl;
}

void Ship::hireCrewMember(){
  cout << "Hiring Crew" << endl;
}

void Ship::fireCrewMember(){
  cout << "Firing Crew" << endl;
}

void Ship::travelToStation(){
  docked = false;
  cout << "Traveling to Station" << endl;
}

void Ship::viewMessage(){
  cout << "Viewing Messages" << endl;
}

void Ship::viewInventory(){
  cout << "Viewing Inventory" << endl;
}

void Ship::viewPassengers(){
  cout << "Viewing Passengers" << endl;
}

void Ship::viewCrew(){
  cout << "Viewing Crew" << endl;
}