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

class CargoBin: public CargoType{
public:
    //CargoType cargoType;
	
//	CargoBin(const CargoBin& cargoBin):
//    cargoType(cargoBin.cargoType.id,cargoBin.cargoType.name),
//    countOnHand(cargoBin.getCount()),
//	price(1),//If CargoBin could inherit from CargoType. This constructor would be much simpler.
//    tradeListing("This is a really awesome item!"),
//	countForSale(-1),
//	unitWeight(10)
//	{}
	
    CargoBin(CargoType type = ACR.EMPTY,int c = 0, string listing = "No Description"):
    CargoType(type),
    countOnHand(c), 
    tradeListing(listing),
	countForSale(-1)
    {}
    
    int add(int amount){
        return countOnHand+=amount;
    }
    
    bool remove(int amountToRemove){
        if(amountToRemove <= countOnHand){
			countOnHand-=amountToRemove;
			return true;
		}//else
            return false;
    }
    
    int getCount() const { return countOnHand; }
	
	int getCountForSale() {
		//if countForSale is < 0 return countOnHand, easiest way to track the value
		return ( (countForSale < 0) || (countOnHand < countForSale) )?(countForSale = countOnHand):(countForSale);
	}
	
	int setCountForSale(int newCountForSale) {
		//set countForSale to lesser of countForSale and countOnHand, return that value
		return (countForSale = (countForSale<=countOnHand)?(newCountForSale):(countOnHand));
	}
	
	int getTotalWeight(){ return unitWeight * countOnHand; }
	int getUnitWeight(){ return unitWeight; }
	string getTradeListing(){ return tradeListing; }
	int getPrice(){ return unitPrice; }

protected:
	string tradeListing;
    int countForSale;
    int countOnHand;
};

#endif
