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
	
    CargoType(int i,string n){
        id = i;
        name = n;
    }
    int id;
    string name;
};

struct AlliedCargoRegistry{
public:

    const CargoType DOLLARS;
    const CargoType YEN;
    const CargoType BTC;
    const CargoType AAPL;
    const CargoType MSFT;
    const CargoType GOOG;

	const CargoType EMPTY;
    const CargoType BACON;
	const CargoType FUEL;
	const CargoType PAX;
	
    AlliedCargoRegistry():
    DOLLARS(1111,"Dollars"),
    YEN(1100,"Yen"),
    BTC(1200,"Bitcoin"),
    AAPL(2222,"Apple"),
    MSFT(3333,"Microsoft"),
    GOOG(4444,"Google"),
	
	EMPTY(0,"Empty"),
	BACON(1000,"Bacon"),
	FUEL(2000,"Fuel"),
	PAX(3000,"Passanger")
    {};
} static const ACR;

#endif
