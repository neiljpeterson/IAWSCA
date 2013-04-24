#ifndef STATION_H
#define STATION_H

//
//  File:         STATION.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Ship.
//

#include <iostream>
#include <string>
#include <vector>
#include "InventoryItem.h"
#include "SpaceThing.h"

using namespace std;

class Station: public SpaceThing {


public:

	Station();
	Station(vector<InventoryItem> inventory){};
	~Station();
        
private:
	

};

#endif