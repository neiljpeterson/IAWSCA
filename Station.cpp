//
//  File:         Station.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Non-inline member function definitions.
//

#include "Station.h"
#include <fstream>

using namespace std;

Station::Station()
{
}

Station::~Station()
{
}

supplies Station::getOffers(){
	supplyItems.itemNames.push_back("Warp Manifolds");
	supplyItems.prices.push_back(100);

	supplyItems.itemNames.push_back("Plasma Relays");
	supplyItems.prices.push_back(1000);
	
	supplyItems.itemNames.push_back("EPS Conduites");
	supplyItems.prices.push_back(42);

	return supplyItems;
}
