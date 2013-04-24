#ifndef BACON_H
#define BACON_H

//
//  File:         Bacon.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Bacon.
//

#include "CargoItem.h"
#include <iostream>
#include <string>
#include <vector>

class Bacon : public CargoItem {
public:
	Bacon(int w = 0, int u = 0);
	~Bacon();
	void gainBacon();
	void spendBacon();
	int getAmount(); 
	
private:
};

#endif