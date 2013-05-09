//
//  SpaceTrader.cpp
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#include "SpaceTrader.h"

bool SpaceTrader::sell(SpaceTrader &trader, int amount, int typeID, int price){
	return trader.buy(*this,amount,typeID,price);
	
}

bool SpaceTrader::buy(SpaceTrader &trader, int amount, int typeID, int price){
	
	if(price <= getCurrencyCount() //has the money
	   && trader.sell(amount,typeID,price)){ //and seller will make the sale
		this->currency.remove(price);
		cargo[typeID].add(amount);
		return true;
	}
	//else
	return false;
};

bool SpaceTrader::sell(int soldAmount, int typeID, int price){
	
	if(cargo[typeID].remove(soldAmount)){//find cargoType, check count, check price
		this->currency.add(price);
		return true;
	}
	//else
	return false;
};

int SpaceTrader::getCurrencyCount(){
	return currency.getCount();
}

int SpaceTrader::getFuelCount(){
	return fuel.getCount();
}

int SpaceTrader::getCargoTotal(){
	int count = 0;
	for(pair<int,CargoBin> c:cargo){
		count += c.second.getCount();
	
		return count;
	}
	
}

void SpaceTrader::setPrice(int typeID,int price){
	cargo[typeID].setPrice(price);
}

void SpaceTrader::setCountForSale(int typeID,int count){
	cargo[typeID].setCountForSale(count);
}

//this might need to return pointers
vector< CargoBin > SpaceTrader::getForSale(){
	vector< CargoBin > sales;
	for(pair<int,CargoBin> asset:cargo)
		if(asset.second.getCountForSale() > 0){
			sales.push_back(asset.second);
		}
	return sales;
}

vector< CargoBin >  SpaceTrader::getCargo(){
	vector< CargoBin > result;
	for(pair<int,CargoBin> asset:cargo)
		if(asset.second.getCount() != 0)
			result.push_back(asset.second);
	return result;
};

int SpaceTrader::getTotalWeight(){
	int total = 0;
	for(pair<int,CargoBin> asset:cargo)
		total+=asset.second.getTotalWeight();
	return total;
};
