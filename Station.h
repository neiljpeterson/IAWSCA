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

using namespace std;

class Station {


public:

	Station();
	Station(vector<InventoryItem>);
	~Station();
	
	bool sellItem(int,int);
	bool sellItem(int);
	vector<string> getAds();
	int getItemPrice(int);
	
        vector<int> foo;
        
private:
	vector<InventoryItem> manifest;

};

#endif