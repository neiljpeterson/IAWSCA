#ifndef SUPPLIES_H
#define SUPPLIES_H

//
//  File:         Supplies.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Supplies.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Supplies {


public:
	Supplies();
	~Supplies();
	
private:
	string name;
	int units;
	float price;
};

#endif