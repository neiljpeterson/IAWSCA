//
//  SpaceTraveler.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/30/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef __IAWSCA__SpaceTraveler__
#define __IAWSCA__SpaceTraveler__

#define SHIP_EMPTY_WEIGHT 10000

#include "../SpaceTrader/CargoBin.h"//this should be refactored out
#include "../SpaceTrader/SpaceTrader.h"//this should be refactored out
#include "../SpaceTraveler/Coordinate.h"
#include "../SpaceTraveler/Passenger.h"

#include <iostream>
#include <cmath>
#include <cstdio>
#include <sstream>
#include <map>
#include <utility>
#include <thread>

using namespace std;

struct SpaceTraveler{//this might need to be part of spacething i think
	//SpaceTraveler(string name):name(name){};
	
	/*
	 SpaceTraveler(int (Trader::*totalWeight)(),bool (CargoBin::*burnFuel)(int),string n = "", double x = 0,double y = 0,double z = 0):
	totalWeight( 
	burnFuel( (*burnFuel)(int)() ),
	name(n),
	current(x,y,z)
	{
		burnRate = 1;
	};
	*/
	
	//This should be done with function pointers to burnFuel() and getTotalWeight()
	//Trying to avoid pointers to sibling objects. See commented out constructor above
	SpaceTraveler(SpaceTrader &trader,CargoBin &bacon,CargoBin &fuel,
				  Coordinate location = Coordinate(0,0,0,"Earth"), vector< Passenger > pssngrs = *new vector<Passenger> ):
	trader(&trader),
	fuel(&fuel),
	bacon(&bacon),
	current(location),
	passengers(pssngrs)
	{}
	
	/* \brief returns the fuel needed to reach the next destination
	 * \param destination A Coordinate object with the destination coordinates
	 */
	bool set_course(Coordinate destination);
	
	bool engage();
	
	void arrive();
	
	bool dock(SpaceTraveler& other);
	
	SpaceTraveler* getDocked();
		
	double getBurnRate();
	
	double getEngineEfficiency();
		
	Coordinate getCurrent();
	
	Coordinate getNext();
	
	double distanceTo(Coordinate destination);
	
	vector< Passenger > getLayovers();
	
	int getTotalWeight();
	
	vector< Passenger > getPassengers();
	
	map< Coordinate,int > getDestinations();
	
	//calls other.load(this,item)
	//this is a "push"
	bool unloadPassenger(SpaceTraveler& other, int passengerID);
	
	//calls other.unload(item)
	//this is a "pull"
	bool loadPassenger(SpaceTraveler& other, int passengerID);
	
	//actually removes the passenger
	//this is a "release"
	Passenger unloadPassenger(int passengerID);
	

//private:
	vector< Passenger > passengers;
	
	Coordinate current;
	Coordinate next;
	
	SpaceTraveler* docked;
	
	CargoBin* fuel;
	CargoBin* bacon;
	SpaceTrader* trader;
	
};

#endif /* defined(__IAWSCA__SpaceTraveler__) */
