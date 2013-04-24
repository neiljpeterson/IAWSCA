#ifndef CARGOITEM_H
#define CARGOITEM_H

//
//  File:         CargoItem.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for CargoItem.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CargoItem {


public:
	CargoItem(int w = 0, int u = 0);
	~CargoItem();
	void setWeight(int);
	void setUnits(int);
	int getUnits();
	
private:
	int weight;
	int units;
};

#endif