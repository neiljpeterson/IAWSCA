#ifndef CAPTAIN_H
#define CAPTAIN_H

//
//  File:         Captain.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Captain.
//

#include <iostream>
#include <string>
#include <vector>

class Captain {


public:
	Captain();
	~Captain();
	void addBenefit();
	
private:
	int benefit;
	int benefits[10];
};

#endif