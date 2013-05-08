//
//  Ship.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/30/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef __IAWSCA__Ship__
#define __IAWSCA__Ship__

#include "../SpaceThing/SpaceThing.h"
#include "../Interface/Interface.h"

#include <iostream>
#include <sstream>
#include <utility>

using namespace std;

class Ship: public SpaceThing{
public:
	
	
	
	Ship(Interface &interface):
	interface(&interface),
	SpaceThing("HMS Down-to-the-wire",1001,2001,Coordinate(0,0,0,"Earth"))
	{
		
	}
	
	/** \brief Lists all items for sale by a certain SpaceThing if only one SpaceThing lists those
	 *
	 */
	void buyFrom(SpaceThing &seller){
		vector < CargoBin > forSale = seller.getForSale();
		vector < string > forSaleStrings;
		for(CargoBin item:forSale){
			
			ostringstream pushMe;
			
			pushMe <<
			item.cargoType.name << " \t" <<
			item.getCountForSale() << " in stock\t" <<
			item.getPrice() << "BCN each\t" << 
			item.getUnitWeight() << "kg \n" <<
			item.getTradeListing();
			
			forSaleStrings.push_back(pushMe.str());
		}
		
		interface->showMenu(
						   seller.getName() + " has the following items for sale", forSaleStrings);
	}
	
	void dock(SpaceThing &station){
		others.insert(make_pair(station.getName(),&station));
	}
	
	void buy(){
		//TODO: if more than one element in others
		//prompt which SpaceThing to buy from or from all
		//for(pair<string,SpaceThing*> thing:others){
		//	buyFrom(thing);
		//}
		buyFrom(*others.begin()->second);//quick hack
	}
	
	
	
	//private:
	Interface *interface;
	map<string,SpaceThing*> others;
	
	
};
#endif /* defined(__IAWSCA__Ship__) */
