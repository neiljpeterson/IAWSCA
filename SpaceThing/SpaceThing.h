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

#include <thread>

using namespace std;

class SpaceThing{
//protected: //?
public:
	
	//TODO: make one giant constructor, and smaller ones that call that as needed
    //considering removing these defaults...
	SpaceThing(
	
	//SpaceThing values
	string name,
	
	//SpaceTrader values
	int bacon = 0,int fuel = 0,//vector< CargoBin > otherCargo = *new vector < CargoBin >,
	
	//SpaceTraveler values
	Coordinate location = Coordinate(0,0,0,"Earth"),vector< Passenger > passengers = *new vector < Passenger >
	):
	
	name(name),
	trader(CargoBin(ACR.BACON,bacon),CargoBin(ACR.FUEL,fuel),name),
	traveler(trader,*trader.getBaconAddress(),*trader.getFuelAddress(),location,passengers),
	talker(name)
	{

		//linker errors
//		next = *new Coordinate;
//		underway = false;
//		distanceRemaining = 0;
	}
		
	//===============SpaceThing Functions

	string getName(){
		return name;
	}
	
	//===============SpaceTrader Public Interface
	bool sell(SpaceThing &other, int amount, int typeID, int currency){
		return this->trader.sell(other.trader,amount, typeID,currency);
	}
	
	bool buy(SpaceThing &other, int amount, int typeID, int currency){
		return this->trader.buy(other.trader, amount, typeID, currency);
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
	
	vector< Passenger > getLayovers(){
		return this->traveler.getLayovers();
	}
	
	bool loadPassenger(SpaceThing& other, Passenger passenger){
		return this->traveler.loadPassenger(other.traveler, passenger.id);
	}
	
	bool unloadPassenger(SpaceThing& other, Passenger passenger){
		return this->traveler.unloadPassenger(other.traveler, passenger.id);
	}
	
	int getTotalWeight(){
		return this->traveler.getTotalWeight() + this->trader.getTotalWeight();
	}
	
	vector< Passenger > getPassengers(){
		return this->traveler.getPassengers();
	}
	
	map< Coordinate,int > getDestinationsMap(){
		return this->traveler.getDestinations();
	}
	
	vector< pair< Coordinate,int > > getDestinations(){
		vector< pair< Coordinate,int > > destinations;
		//repack destinations into a vector for easier usage and referance by child object
		for(pair< Coordinate,int > d:this->traveler.getDestinations())
			destinations.push_back(d);
		return destinations;
	}
	
	bool setCourse(Coordinate destination){
		return this->traveler.set_course(destination);
	}
	
	void arrive(){
		this->traveler.arrive();
	}
	
	void dock(SpaceThing &other){
		docked = &other;
		this->traveler.dock(other.traveler);
	}
	
	SpaceThing* getDocked(){
		return docked;
	}
	
	int getFuelCount(){
		return this->trader.getFuelCount();
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
	
protected:
	//these statics are for multithreading
//	static Coordinate next;
//	static bool underway;
//	static int distanceRemaining;
	
	
private: //must be public for tests to run
	
	string name;
	SpaceThing* docked;
	SpaceTrader trader;
	SpaceTraveler traveler;
	SpaceTalker talker;
	
	
};


#endif
