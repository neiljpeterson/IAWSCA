//
//  SpaceTraveler.cpp
//  IAWSCA
//
//  Created by Neil Peterson on 4/30/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#include "SpaceTraveler.h"

/* \brief returns the fuel needed to reach the next destination
 * \param destination A Coordinate object with the destination coordinates
 */
bool SpaceTraveler::set_course(Coordinate destination){
	next = destination;
	//Add obstacles and detour functionality later if time allows
	if((distanceTo(next) * burnRate) < fuel->getCount())
		return true;
	//else
	return false;
}

bool SpaceTraveler::engage(){
	if (fuel->remove(distanceTo(next) * getBurnRate())){
		current = next;
		return true;
	}
	//else
	return false;
};

double SpaceTraveler::getBurnRate(){
	cout << "Ship is burning fuel at " << burnRate << endl;//testing, remove later
	return burnRate;
};

Coordinate SpaceTraveler::getCurrent(){
	return current;
}

Coordinate SpaceTraveler::getNext(){
	return next;
}

double SpaceTraveler::distanceTo(Coordinate destination){
	return sqrt(pow(current.x-destination.x,2) +
				pow(current.y-destination.y,2) +
				pow(current.z-destination.z,2));
}