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
	
	
	
	Ship(Interface &interface,string name,Coordinate start,int bacon, int fuel)://map<int,int> otherCargo
	interface(&interface),
	SpaceThing(name,bacon,fuel,start)
	{}
	
	/** \brief Lists all items for sale by a certain SpaceThing if only one SpaceThing lists those
	 *
	 */
	void buyFrom(SpaceThing &seller){
		bool again = true;
		while(again){
			vector < CargoBin > forSale = seller.getForSale(); //get the items for sale
			vector < string > forSaleStrings;// = *new vector < string >;
			for(CargoBin item:forSale){ //build strings from the for sale items
				ostringstream pushMe;
				
				pushMe <<
				item.name << " \t" <<
				item.getCountForSale() << " in stock\t" <<
				item.getPrice() << "BCN each\t" <<
				item.getUnitWeight() << "kg \n\t" <<
				item.getTradeListing();
				
				forSaleStrings.push_back(pushMe.str());
			}
			
			interface->message("Your current balance is " + to_string(getCurrencyCount()));
			
			interface->showMenu(
			seller.getName() + " has the following items for sale", forSaleStrings);
			
			int menuChoice = interface->prompt(
			"Please choose an item to buy",1,(int)forSale.size());
			
			//this is just for brevity's sake
			CargoBin* item = &forSale[menuChoice-1];
			
			int soldAmount = interface->prompt(
			"How many " + item->name + "s would you like to buy?",0,item->getCountForSale());
			
			int totalPrice = item->getPrice() * soldAmount;
			
			bool confirm = interface->prompt("Your total is " + to_string(totalPrice) + "BCN for " +
											 to_string(soldAmount) + " " +
											 item->name + ((soldAmount==1)?(""):("s")) + "\n" +
											 "Is this correct?","Yes","No") ;
			bool saleComplete =
			SpaceThing::buy(seller, soldAmount, item->typeID, totalPrice);
			
			if(confirm && saleComplete){
				//sale went through
				interface->message("Thank you for your purchase");
			}
			else if(confirm && !saleComplete){
				//user confirmed but sale did not go through
				interface->message("Your purchase was not able to be made. Please check your balance");
			}else{
				//user did not confirm
				interface->message("Your purchase was canceled.");
			}
			
			again = interface->prompt("Would like to make another purchase","Yes","No");
			//who is responsible for looping? Ship or main? hmm...
		}
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
