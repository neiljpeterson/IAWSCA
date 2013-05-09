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
	//Add obstacles and detour functionality later if time allows
	if( (distanceTo(next) * getBurnRate()) >= fuel->getCount() ){
		next = destination;
		return true;
	}else{
		next = current;
		return false;
	}
	return false;
}

 bool SpaceTraveler::engage(){
	return false;
};

/* \brief BurnRate is the amount of fuel burned per au at current weight
 *
 */
double SpaceTraveler::getBurnRate(){
	return (this->getTotalWeight())/getEngineEfficiency();
};

/* \brief EngineEfficiency is the amount of fuel burned per kg/au
 *
 */
double SpaceTraveler::getEngineEfficiency(){
	return 10000;
}

Coordinate SpaceTraveler::getCurrent(){
	return current;
}

Coordinate SpaceTraveler::getNext(){
	return next;
}

/* brief\ returns the total ship weight, cargo, ship and passengers
 *
 */
int SpaceTraveler::getTotalWeight(){
	int result = SHIP_EMPTY_WEIGHT;
	for(Passenger p:passengers){ //TODO: make an update funtion, a private variable and a getter. Trigger update in load
		result += p.weight;
	}
	result += trader->getTotalWeight();
	return result;
}

void SpaceTraveler::arrive(){
	fuel->remove(distanceTo(next) * getBurnRate());
	current = next;
}

bool SpaceTraveler::dock(SpaceTraveler& other){
	docked = &other;
	for(Passenger passenger:passengers)
		if(passenger.destination == current)
			unloadPassenger(other,passenger.id);
	return true;
}

SpaceTraveler* SpaceTraveler::getDocked(){
	return docked;
}

vector< Passenger > SpaceTraveler::getLayovers(){
	return passengers; //TODO: set flags for passangers who want to leave or not
}

vector< Passenger > SpaceTraveler::getPassengers(){
	return passengers;
}

int SpaceTraveler::getPassangerTotal(){
	return (int)passengers.size();
}

map< Coordinate,int > SpaceTraveler::getDestinations(){
	//TODO: make an update funtion, a private variable and a getter. Trigger update in load
	//this could obvious be done better with a database
	map< Coordinate,int > destinations;
	for(Passenger passenger:passengers){
		pair< Coordinate,int > destination = make_pair(passenger.destination,passenger.fare);
		pair< map< Coordinate,int >::iterator, bool > result;
		result = destinations.insert( make_pair(passenger.destination,passenger.fare) );
		if (result.second == false){ //element found
			destinations[destination.first] += destination.second;
			//result.first->second += destination.second;
		}
	}
	return destinations;
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
	bacon->add(unloadedPassenger.fare);
	passengers.erase(unloadMe);
	return unloadedPassenger;
}

double SpaceTraveler::distanceTo(Coordinate destination){
	return sqrt(pow(current.x-destination.x,2) +
				pow(current.y-destination.y,2) +
				pow(current.z-destination.z,2));
}