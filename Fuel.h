#ifndef FUEL_H
#define FUEL_H

//
//  File:         Fuel.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Fuel.
//

#include <iostream>
#include <string>
#include <vector>

class Fuel {


public:
	Fuel();
	~Fuel();
	void purchaseFuel();
	void sellFuel();
	
private:
	int price;
};

#endif