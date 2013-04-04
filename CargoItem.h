#ifndef CARGOITEM_H
#define CARGOITEM_H

//
//  File:         CargoItem.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for CargoItem.
//
#include "Supplies.h"
#include "Passenger.h"
#include "Fuel.h"
#include "Bacon.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CargoItem {


public:
	CargoItem();
	~CargoItem();
	
private:
	int supplyType;
	int weight;
	int units;
};

#endif