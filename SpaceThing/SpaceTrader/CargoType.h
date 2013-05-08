//
//  AlliedCargoRegistry.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef IAWSCA_AlliedCargoRegistry_h
#define IAWSCA_AlliedCargoRegistry_h

//#include "./CargoBin.h"
#include <string>
#include <iostream>

using namespace std;

struct CargoType{

//    CargoType(const CargoType &type):
//	typeID(type.typeID),
//	name(type.name),
//	unitWeight(type.unitWeight),
//	unitPrice(type.unitPrice)
//    //:CargoType(t.id,t.name) //Compiler not supporting delegated constructors?
//    {}
	
    CargoType(int i,string nom,int weight = 0,int price = 0):
	typeID(i),
	name(nom),
	unitWeight(weight),
	unitPrice(price)
	{}

//protected: //TODO: put getters and setters in CargoBin, protect these members
    const int typeID;
    const string name;
	int unitWeight;
	int unitPrice;
	
};

struct AlliedCargoRegistry{
public:

	//map<int,String>;
	
	const CargoType EMPTY;
    const CargoType BACON;
	const CargoType FUEL;
	const CargoType PAX;
	const CargoType CREW;
	
	
	
    AlliedCargoRegistry():
	EMPTY(0,"Empty",0,0),
	BACON(1000,"Bacon",0,1),
	FUEL(2000,"Fuel",1,1),
	PAX(3000,"Passanger",100,0),
	CREW(4000,"Crew Member",100,0)
    {};
	
} static const ACR;

#endif
