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

class Passenger {


public:
	Passenger();
	~Passenger();
	
private:
	std::string name;
	std::string destination;
	int toleranceLevel;
	float fare;
	int ID;
};

#endif