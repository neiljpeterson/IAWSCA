#ifndef PASSENGER_H
#define PASSENGER_H

//
//  File:         Passenger.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Passenger.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Passenger {


public:
	Passenger();
	~Passenger();
	
private:
	string name;
	string destination;
	int toleranceLevel;
	float fare;
	int ID;
};

#endif