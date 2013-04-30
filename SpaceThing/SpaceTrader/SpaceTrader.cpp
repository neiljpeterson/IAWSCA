//
//  SpaceTrader.cpp
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#include "./SpaceTrader.h"

bool SpaceTrader::sell(SpaceTrader* trader, int amount, CargoType cargoType, int currency){
	return trader->buy(this,amount,cargoType,currency);
	
}

bool SpaceTrader::buy(SpaceTrader* trader, int amount, CargoType cargoType, int currency){
	
	if(currency <= getCurrencyCount() //has the money
	   && trader->sell(amount,cargoType,currency)){ //and seller will make the sale
		this->currency.remove(currency);
		assets[cargoType.id].add(amount);
		return true;
	}
	//else
	return false;
};

bool SpaceTrader::sell(int amount, CargoType cargoType, int currency){
	
	if(assets[cargoType.id].remove(amount)){//find cargoType, check count, check price
		this->currency.add(currency);
		return true;
	}
	//else
	return false;
};

int SpaceTrader::getCurrencyCount(){
	return currency.getCount();
}

vector< CargoBin > SpaceTrader::getForSale(){
	vector< CargoBin > sales;
	for(pair<int,CargoBin> asset:assets)
		if(asset.second.getCountForSale() > 0)
			sales.push_back(asset.second);
	return sales;
}

vector< pair<CargoType,int> > SpaceTrader::getCargoCounts(){
	vector< pair<CargoType,int> > counts;
	for(pair<int,CargoBin> asset:assets)
		counts.push_back(make_pair(asset.second.cargoType,asset.second.getCount()));
	
	return counts;
};
