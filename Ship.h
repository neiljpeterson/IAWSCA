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
#include <iostream>
#include <string>

class Ship {
public:
    Ship(); //Default Constructor

    ~Ship();

    void setName(const std::string& n);

    bool isDocked();
    void dock();
    void buySupplies();
    void sellSupplies();
    void loadPassengers();
    void unloadPassengers();
    void hireCrewMember();
	void fireCrewMember();
    void travelToStation();
    void viewMessage();
    void viewInventory();
	void viewPassengers();
	void viewCrew();
	int getBacon();
	string getOffers(Station*);
    /**
     *  Access function to get the name of the ship
     */
    std::string getName() const;

	void setLocation(const Station & s);
	Station getLocation();

private:

    /**
     *  Name of Ship
     */
    std::string name;
	int maxWeight;
	int currentWeight;
    bool docked;
	Station* location;
	std::string offers;
	Station* station;
	Bacon* bacon;

};

#endif
