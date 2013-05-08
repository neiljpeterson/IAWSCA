//
//  SpaceThing.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef IAWSCA_SpaceThing_h
#define IAWSCA_SpaceThing_h

#include "./SpaceTrader/SpaceTrader.h"
#include "./SpaceTraveler/SpaceTraveler.h"
#include "./SpaceTalker/SpaceTalker.h"
#include "./SpaceTrader/CargoType.h"

using namespace std;

class SpaceThing{
//protected: //?
public:
	
    //considering removing these defaults...
	SpaceThing(string name,int bacon = 0,int fuel = 0,Coordinate location = Coordinate(0,0,0,"Earth")):
	name(name),
	trader(CargoBin(ACR.BACON,bacon),CargoBin(ACR.FUEL,fuel),name),
	traveler(trader,*trader.getFuelAddress(),name),
	talker(name)
	{}
		
	//===============SpaceThing Functions
	string getName(){
		return name;
	}
	
	//===============SpaceTrader Public Interface
	bool sell(SpaceThing &trader, int amount, int typeID, int currency){
		return this->trader.sell(trader.trader,amount, typeID,currency);
	}
	
	bool buy(SpaceThing &trader, int amount, int typeID, int currency){
		return this->trader.buy(trader.trader, amount, typeID, currency);
	}
	
	int getCurrencyCount(){
		return this->trader.getCurrencyCount();
	}
	
//	vector< pair<CargoType,int> > getCargo(){
//		return NULL; //this->trader.getCargo();
//	}
	
	vector< CargoBin > getForSale(){
		return this->trader.getForSale();
	}
	
	
	//===============SpaceTravler Public Interface
	bool set_course(Coordinate destination){
		return this->traveler.set_course(destination);
	}
	
	bool engage(){
		return this->traveler.engage();
	}
	
	double getBurnRate(){
		return this->traveler.getBurnRate();
	}
	
	Coordinate getCurrent(){
		return this->traveler.getCurrent();
	}
	
	Coordinate getNext(){
		return this->traveler.getNext();
	}
	
	double distanceTo(Coordinate destination){
		return this->traveler.distanceTo(destination);
	}
	
	//===============SpaceTalker Public Interface
	void send(SpaceThing &recipient,SpaceTalker::Message message){
		return this->talker.send(recipient.talker, message);
	}
	
	void recieve(SpaceTalker::Message &message){
		return this->talker.recieve(message);
	}
	
	vector<SpaceTalker::Message*> getUnread(){
		return this->talker.getUnread();
	}
	
private: //must be public for tests to run
	string name;
	
	SpaceTrader trader;
	SpaceTraveler traveler;
	SpaceTalker talker;
	
	
};


#endif
