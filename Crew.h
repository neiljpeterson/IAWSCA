#ifndef CREW_H
#define CREW_H

//
//  File:         Crew.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Crew.
//

#include "Captain.h"
#include "CrewMember.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Crew {


public:
	Crew();
	~Crew();
	
private:
	int federatedID;
	string name;
};

#endif