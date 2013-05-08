//
//  SpaceTrader.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef IAWSCA_SpaceTrader_h
#define IAWSCA_SpaceTrader_h

#include "./CargoBin.h"

#include <vector>
#include <map>
#include <string>
#include <iostream>

using namespace std;

class SpaceTrader{
public:
    string name;
	
	SpaceTrader(CargoBin currency, CargoBin fuel,string name = ""):
    currency(currency),
    name(name){
		this->assets.insert(make_pair(fuel.typeID,fuel));
    }
	
    SpaceTrader(CargoBin currency, vector< CargoBin > assets,string name = ""):
    currency(currency),
    name(name){
        for(CargoBin bin:assets)
            this->assets.insert(make_pair(bin.typeID,bin));
    }
    
    //Trader(int dollars,string name):Trader(dollars,0,name){}
    bool sell(SpaceTrader &trader, int amount, int typeID, int currency);
	
    bool buy(SpaceTrader &trader, int amount, int typeID, int currency);
    
	CargoBin* getFuelAddress(){//Used by SpaceTraveler for fuel deduction
		return &assets[ACR.FUEL.typeID];
	}
	
	int getCurrencyCount();
    vector< CargoBin > getCargo();
	vector< CargoBin > getForSale();
	int getTotalWeight();
	
private:
    CargoBin currency;
    map<int,CargoBin> assets;
	
	bool sell(int amount, int typeID, int currency);
};

//Note: Is there a way to build a comparison operator for an object such that only the fields provided are compared?

#endif
