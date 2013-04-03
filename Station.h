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
using namespace std;

static struct supplies{ //TODO: roll this into the class
		vector<string> itemNames;
		vector<int> prices;
	} supplyItems;

class Station {


public:

	Station();
	~Station();

	supplies getOffers();

private:

};

#endif