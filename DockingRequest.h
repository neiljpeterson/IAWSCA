#ifndef DOCKINGREQUEST_H
#define DOCKINGREQUEST_H

//
//  File:         DockingRequest.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for DockingRequest.
//

#include <iostream>
#include <string>
#include <vector>

class DockingRequest {


public:
	DockingRequest();
	~DockingRequest();
	DockingRequest requestDock();
	
private:
	int dockingFee;
	bool confirmation;
};

#endif