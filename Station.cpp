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
	name = "";
	dockingFee = 0;
	stationID = 0;
	offer = "";
}

Station::~Station()
{
}

string Station::getOffers(){
	/*supplies=setName(itemNames).push_back("Warp Manifolds");
	supplies.push_back("Warp Manifolds", 100);

	supplies.itemNames.push_back("Plasma Relays");
	supplies.prices.push_back(1000);
	
	supplies.itemNames.push_back("EPS Conduites");
	supplies.prices.push_back(42);
	*/

	return offer;
}

string Station::showOffers(){
	return "Offers";
}
