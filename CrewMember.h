#ifndef CREWMEMBER_H
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

class CrewMember {


public:
	CrewMember();
	~CrewMember();
	void deleteCrewMember();
	void addCrewMember();
	
private:
	std::string jobTitle;
	int pay;
	std::string supply;
	int supplyUsage;
};

#endif