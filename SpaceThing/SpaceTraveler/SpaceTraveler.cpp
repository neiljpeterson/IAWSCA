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
int SpaceTraveler::getTotalWeight(){
	int result = 0;
	for(Passenger p:passengers){ //TODO: make an update funtion, a private variable and a getter. Trigger update in load
		result += p.weight;
	}
	return result;
}

vector< Passenger > SpaceTraveler::getLayovers(){
	return passengers; //TODO: set flags for passangers who want to leave or not
}

bool SpaceTraveler::unloadPassenger(SpaceTraveler& other, int passengerID){
	return other.loadPassenger(*this,passengerID);
}

bool SpaceTraveler::loadPassenger(SpaceTraveler& other, int passengerID){
	//TODO: check weight limit
	Passenger passenger = other.unloadPassenger(passengerID);
	passengers.push_back(passenger);
	return true; 
}

Passenger SpaceTraveler::unloadPassenger(int passengerID){
	vector<Passenger>::iterator unloadMe = find(passengers.begin(), passengers.end(), *new Passenger(passengerID));
	Passenger unloadedPassenger = *unloadMe;
	passengers.erase(unloadMe);
	return unloadedPassenger;
}

double SpaceTraveler::distanceTo(Coordinate destination){
	return sqrt(pow(current.x-destination.x,2) +
				pow(current.y-destination.y,2) +
				pow(current.z-destination.z,2));
}