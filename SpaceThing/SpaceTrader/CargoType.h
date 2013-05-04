//
//  AlliedCargoRegistry.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef IAWSCA_AlliedCargoRegistry_h
#define IAWSCA_AlliedCargoRegistry_h

#include "./CargoBin.h"
#include <string>

using namespace std;

struct CargoType{

    CargoType(const CargoType &t)
    //:CargoType(t.id,t.name) //Compiler not supporting delegated constructors?
    {
        id = t.id; //this instead of intializers, compiler version issue
        name = t.name;
    }
	
    CargoType(int i,string n,int w = 0):
	id(i),name(n),unitWeight(w)
	{}
	
    int id;
    string name;
	int unitWeight;
};

struct AlliedCargoRegistry{
public:

	const CargoType EMPTY;
    const CargoType BACON;
	const CargoType FUEL;
	const CargoType PAX;
	
    AlliedCargoRegistry():
	
	EMPTY(0,"Empty"),
	BACON(1000,"Bacon"),
	FUEL(2000,"Fuel",1),
	PAX(3000,"Passanger",1)
    {};
} static const ACR;

#endif
