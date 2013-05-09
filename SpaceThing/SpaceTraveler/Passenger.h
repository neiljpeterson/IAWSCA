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
	
	Passenger(int passengerID):id(passengerID){};
	
	Passenger(string name = "" ,int fare = 0, int weight = 0, Coordinate destination = Coordinate(-1,-1,-1,"Undefined"), string message = "No message"):
	name(name),fare(fare),destination(destination),weight(weight),personalMessage(message)
	{
		id = hash(name.c_str());//yes, we could have just made a random id but hashes are cooler
	}
	
	bool operator==(const Passenger &compareMe){
		return this->id == compareMe.id;
	}
	
	//This is a simple hash adapted from Stroustrup's "Programming: Principles and Practice Using C++"
	int hash(const char *str)
	{
		int h = 0;
		int r = 0;
		while (*str){
			r = rand() % 10000 + 1;//this line is randomness the adaptation. It has a collision likelyhood for the same string on the order of 0.01%
			h = abs((h << 1 ^ *str++) * r);//also the abs was added to not have to worry about signs, but it does double the collison likelyhood
		}
		return h;
	}
	
	string name;
	string personalMessage;
	int fare;
	int id;
	Coordinate destination;
	int weight;
};

#endif /* defined(__IAWSCA__Passengerr__) */
