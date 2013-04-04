#ifndef DOCK_H
#define CREWMEMBER_H

//
//  File:         CrewMember.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for CrewMember.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class CrewMember {


public:
	CrewMember();
	~CrewMember();
	void deleteCrewMember();
	void addCrewMember();
	
private:
	string jobTitle;
	int pay;
	string supply;
	int supplyUsage;
};

#endif