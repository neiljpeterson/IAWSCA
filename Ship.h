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
	void fireCrewMember();	//new
    void travelToStation();
    void viewMessage();
    void viewInventory();
	void viewPassengers();	//new
	void viewCrew();		//new
    /**
     *  Access function to get the name of the ship
     */
    std::string getName() const;

private:

    /**
     *  Name of Ship
     */
    std::string name;
    bool docked;

};

#endif
