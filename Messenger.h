#ifndef MESSENGER_H
#define MESSENGER_H

//
//  File:         Messenger.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Messenger.
//

#include "Message.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Messenger {


public:
	Messenger();
	~Messenger();
	void listMessages();
	Message* find(Message);
	void displayMessage();
	void addMessage();
	void deleteMessage();
	
private:
	string read;
	string unread;
};

#endif