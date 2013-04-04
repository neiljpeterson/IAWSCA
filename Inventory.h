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
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Inventory {


public:
	Inventory();
	~Inventory();
	void addCargoItem(int);
	void removeCargoItem(int);
	void displayCargoItems(int);
	void displayStations();
	
private:
	int price;
};

#endif