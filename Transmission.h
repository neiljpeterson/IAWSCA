#ifndef TRANSMISSION_H
#define TRANSMISSION_H

//
//  File:         Transmission.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Transmission.
//

#include <iostream>
#include <string>
#include <vector>

class Transmission {


public:
	Transmission();
	~Transmission();
	
private:
	bool isRead;
	int timeOut;
	int reward;
};

#endif