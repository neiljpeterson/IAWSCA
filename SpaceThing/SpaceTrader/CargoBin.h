//
//  CargoBin.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef IAWSCA_CargoBin_h
#define IAWSCA_CargoBin_h

#include "./CargoType.h"

class CargoBin{
public:
    CargoType cargoType;
	
	
	CargoBin(const CargoBin& cargoBin):
    cargoType(cargoBin.cargoType.id,cargoBin.cargoType.name),
    countOnHand(cargoBin.getCount()),
	price(1),//If CargoBin could inherit from CargoType. This constructor would be much simpler.
    tradeListing("This is a really awesome item!"),
	countForSale(-1),
	unitWeight(10)
	{}
	
    CargoBin(CargoType t = ACR.EMPTY,int c = 0):
    cargoType(t),
    countOnHand(c)
    {}
    
    int add(int amount){
        return countOnHand+=amount;
    }
    
    bool remove(int amount){
        if(countOnHand<=amount)
            return false;
        //else
        countOnHand-=amount;
        return true;
    }
    
    int getCount() const {return countOnHand; }
	int getCountForSale() {
		//if countForSale is -1 return countOnHand, easiest way to track the value
		return (countForSale<0 || countOnHand<countForSale )?(countForSale = countOnHand):(countForSale);
	}
	int setCountForSale(int newCountForSale) {
		//set countForSale to lesser of countForSale and countOnHand, return that value
		return (countForSale = (countForSale<=countOnHand)?(newCountForSale):(countOnHand));
	}
	int getTotalWeight(){ return unitWeight * countOnHand; }
	int getUnitWeight(){ return unitWeight; }
	string getTradeListing(){ return tradeListing; }
	int getPrice(){ return price; }

protected:
	int price;
	string tradeListing;
	int unitWeight;
    int countForSale;
    int countOnHand;
};

#endif
