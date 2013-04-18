#ifndef INVENTORY_H
#define INVENTORY_H

//
//  File:         Inventory.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Inventory.
//

#include "CargoItem.h"
#include "Supplies.h"
#include <iostream>
#include <string>
#include <vector>

class Inventory {


public:
	Inventory();
	~Inventory();
	void addCargoItem(int);
	void removeCargoItem(int);
	void displayCargoItems(int);
	void displayStations();
	void setName(std::string & n);
	string getName();
	void setPrice(int p);
	int getPrice();

private:
	int prices;
	std::string itemNames;
	Supplies* inventory;

};

#endif