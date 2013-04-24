#ifndef MESSAGE_H
#define MESSAGE_H

//
//  File:         Message.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Message.
//

#include "Alert.h"
#include "DockingRequest.h"
#include "Transmission.h"
#include <iostream>
#include <string>
#include <vector>

class Message {


public:
	Message();
	~Message();
	
private:
	std::string name;
	std::string body;
};

#endif