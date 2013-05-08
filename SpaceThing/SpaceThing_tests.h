//
//  SpaceThing_tests.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/30/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef IAWSCA_SpaceThing_tests_h
#define IAWSCA_SpaceThing_tests_h

#include "./SpaceTrader/SpaceTrader.h"
#include "./SpaceTraveler/SpaceTraveler.h"
#include "./SpaceTalker/SpaceTalker.h"

#include "./SpaceThing.h"

#include <string>

using namespace std;

class SpaceThing_tests{
public:
	
//	static void displayBalances(vector<SpaceThing*> traders){
//		for(SpaceThing* t:traders){
//			cout << t->getName() << ": $" << t->getCurrencyCount() << " \t";
//			
//			for(pair<CargoType,int> stock:t->getCargoCounts())
//				cout << stock.first.name << ": " << stock.second << "\t";
//			cout << "\n";
//		}
//		
//		cout << "\n";
//	};
	
	static bool runAll(){
		SpaceThing bob = SpaceThing("Bob",1000,1000);
		SpaceThing alice = SpaceThing("Alice",1000,1000);
		
		
		//=====================SpaceTalker
		
		bob.send(alice,SpaceTalker::Message("hello","How are you?"));
		
		bob.send(alice,SpaceTalker::Message("hey","Lets meet"));
		
		bob.send(alice,SpaceTalker::Message("This an important message","Your Allied Cargo Transport license will expire in 3 Earth weeks"));
		
		vector<SpaceTalker::Message*> unread = alice.getUnread();
		
		cout << unread.back()->getSubject() << endl <<
		unread.back()->getBody() << endl;


	
	//=====================SpaceTraveler

		cout << "My name is " << bob.getName() << ". I am at " << bob.getCurrent().toString() << endl;
		Coordinate pluto(10,10,10,"Pluto");
		cout << "I am going to travel " << bob.distanceTo(pluto) << endl;
		if (bob.set_course(pluto)){
			bob.engage();
			cout << "I am now at " << bob.getCurrent().name << endl;
		}

	//====================SpaceTrader
		
		vector<SpaceThing*> traders;
		
		traders.push_back(&alice);
		traders.push_back(&bob);

		
//		displayBalances(traders);
//		bob.buy(alice,10,ACR.FUEL,10);
//		alice.sell(bob,10,ACR.FUEL,10);
//		displayBalances(traders);
//		bob.buy(alice,50,ACR.FUEL,60);
//		displayBalances(traders);
		
		return true;
	}
};

#endif
