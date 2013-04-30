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
    count(cargoBin.getCount())
    {}
	
    CargoBin(CargoType t = ACR.EMPTY,int c = 0):
    cargoType(t),
    count(c)
    {}
    
    int add(int amount){
        return count+=amount;
    }
    
    bool remove(int amount){
        if(count<=amount)
            return false;
        //else
        count-=amount;
        return true;
    }
    
    int getCount() const {return count;}
	int getCountForSale() const {return countForSale;}
    
protected:
    int countForSale;
    int count;
};

#endif
