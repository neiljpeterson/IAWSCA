//
//  Passenger.h
//  IAWSCA
//
//  Created by Neil Peterson on 5/8/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef __IAWSCA__Passenger__
#define __IAWSCA__Passenger__

#include "../SpaceTrader/CargoBin.h"
#include "../SpaceTraveler/Coordinate.h"

#include <iostream>
#include <map>

using namespace std;

struct Passenger{
	
	Passenger(string name = "" ,int fare = 0, int weight = 0, Coordinate destination = Coordinate(-1,-1,-1,"Undefined"), string message = "No message"):
	name(name),fare(fare),destination(destination),weight(weight),personalMessage(message)
	{}
	
	string name;
	string personalMessage;
	int fare;
	Coordinate destination;
	int weight;
};

#endif /* defined(__IAWSCA__Passengerr__) */
