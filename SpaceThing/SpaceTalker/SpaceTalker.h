//
//  SpaceTalker.h
//  IAWSCA
//
//  Created by Neil Peterson on 5/2/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef __IAWSCA__SpaceTalker__
#define __IAWSCA__SpaceTalker__

#include <iostream>
#include <string>
#include <vector>

using namespace std;



struct SpaceTalker{
	
	struct Message{//Must be inner class to avoid a circular referance 
		
		Message(){};
		
		//Message(const &Message m){};
		
		Message(string subject,string body):
		subject(subject),
		body(body)
		{};
		
		SpaceTalker* sender;
		SpaceTalker* recipient;
		
		string getSubject(){
			return subject;
		};
		
		string getBody(){
			return body;
		};
		
		//private:
		bool unread;
		string subject;
		string body;
	};
	
	string name;
	int unreadCount;
	vector<Message*> unread;
	vector<Message*> read;
	
	SpaceTalker(string name):name(name){
		
	}
	
	void send(SpaceTalker &recipient,Message message){
		message.sender = this;
		message.recipient = &recipient;
		recipient.recieve(message);
	}
	
	void recieve(Message &message){
		unread.push_back(new Message(message));
		unreadCount++;
	}
	
	vector<Message*> getUnread(){
		return unread;
	}
	
	void markRead(Message* message){
		
	}

};

#endif /* defined(__IAWSCA__SpaceTalker__) */
