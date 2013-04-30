//
//  SpaceTrader_tests.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//



#ifndef IAWSCA_SpaceTrader_Tests_h
#define IAWSCA_SpaceTrader_Tests_h

#include "./SpaceTrader.h"
#include "./CargoBin.h"

#include <vector>
#include <iostream>
#include <utility>

using namespace std;

class SpaceTrader_Tests{
public:
	void displayBalances(vector<SpaceTrader*> traders){
		for(SpaceTrader* t:traders){
			cout << t->name << ": $" << t->getCurrencyCount() << " \t";
			
			for(pair<CargoType,int> stock:t->getCargoCounts())
				cout << stock.first.name << ": " << stock.second << "\t";
			cout << "\n";
		}
		
		cout << "\n";
	};
	
	bool runAll(bool verbose = true){
		
		vector<SpaceTrader*> traders;
		vector<CargoBin> market;
		
		market.push_back(CargoBin(ACR.GOOG,21));
		market.push_back(CargoBin(ACR.AAPL,32));
		market.push_back(CargoBin(ACR.BTC,43));
		
		traders.push_back(new SpaceTrader(CargoBin(ACR.DOLLARS,100),market,"Alice"));
		traders.push_back(new SpaceTrader(CargoBin(ACR.DOLLARS,100),market,"Bob"));
		
		SpaceTrader* alice = traders[0];
		SpaceTrader* bob = traders[1];
		
		if(verbose) displayBalances(traders);
		bob->buy(alice,1,ACR.BTC,1);
		alice->sell(bob,1,ACR.BTC,1);
		if(verbose) displayBalances(traders);
		bob->buy(alice,50,ACR.BTC,60);
		if(verbose) displayBalances(traders);
		
		return true;
	}
	
};

#endif
