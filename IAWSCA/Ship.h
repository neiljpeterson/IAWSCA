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
#include <iomanip>
#include <sstream>
#include <utility>

using namespace std;

class Ship: public SpaceThing{
public:
	
	
	
	Ship(Interface &interface,string name,int bacon, int fuel,
		 vector< CargoBin > cargo = *new vector<CargoBin>,
		 Coordinate start = *new Coordinate(0,0,0,"Unknown"),
		 vector< Passenger > passengers = *new vector<Passenger>
		 ):
		interface(&interface),
		SpaceThing(name,bacon,fuel,cargo,start,passengers)
		{}
	
	void displayHUD(){
		int w = 10;
		char c = '=';
		cout << endl << string(w*5,c) << endl
		<< setw(w) << internal << "FUEL"
		<< setw(w) << internal << "BACON"
		<< setw(w) << internal << "ENGINE"
		<< setw(w) << internal << "WEIGHT";
		
		cout << endl
		<< setw(w) << internal << getFuelCount()
		<< setw(w) << internal << getCurrencyCount()
		<< setw(w) << internal << getBurnRate()
		<< setw(w) << internal << getTotalWeight()
		<< endl << string(w*5,c) << endl;
		
		cout << "Current Location: " << getCurrent().name;
	}
	
	void buy(){
	if(isDocked())
		buyFrom(*docked);
	else
		interface->message("You must be docked with another ship or station before you can trade cargo.\nPlease consult your Space Ship Manual for docking procedures and protocols",true);
	}
	
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
			
			interface->message("Your current balance is " + to_string(getCurrencyCount()) + "\n");
			
			int menuChoice = interface->showMenu(
												 seller.getName() + " has the following items for sale", forSaleStrings,
												 "Please choose an item to buy");
			
			if(menuChoice <= forSale.size()){//if user did not choose the close option
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
				//logic error here
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
			}else{
				again = false; //user chose the quit option
			}
		}
	}
	
	void loadPassengers(){
		if(isDocked())
			loadPassengersFrom(*docked);
		else
			interface->message("You must be docked with another ship or station before you can load passengers.\nPlease consult your Space Ship Manual for passenger on-boarding procedures and protocols",true);
	}
	
	/** \brief Lists all passengers that are layed over at the stopover (station)
	 *	\param &stopOver is the SpaceThing the passengers are at
	 */
	void loadPassengersFrom(SpaceThing &stopOver){
		bool again = true;
		while(again){
			vector < Passenger > layovers = stopOver.getLayovers(); // get passengers waiting for a ride
			vector < string >  layoverStrings;
			for(Passenger passenger:layovers){ //build strings for each layover
				ostringstream pushMe;
				
				pushMe <<
				passenger.destination.name << " \t" << //TODO:add a distance calculation
				passenger.fare << "BCN \t" <<
				passenger.weight << "\n\t" <<
				passenger.personalMessage;
				
				
				layoverStrings.push_back(pushMe.str());
			}
			
			interface->message("Your current weight is " + to_string(getTotalWeight()) );
			interface->message("Your current burn rate is " + to_string(getBurnRate()) );
			
			int menuChoice = interface->showMenu(
												 stopOver.getName() + " has the following layovers", layoverStrings,
												 "Please choose a fare to accept");
			
			if(menuChoice <= layovers.size()){//if user did not choose the close option
				
				//this is just for brevity's sake
				Passenger* passenger = &layovers[menuChoice-1];
				
				bool confirm = interface->prompt("You are going to fly " + passenger->name + " to " +
												 passenger->destination.name + " (a distance of " +
												 to_string(distanceTo(passenger->destination)) + ")" +
												 "for " + to_string(passenger->fare) + "BCN \n" +
												 "Is this correct?","Yes","No");
				bool loadSuccessful = false;
				if(confirm && (loadSuccessful = loadPassenger(stopOver,*passenger))){
					interface->message(passenger->name + " is loaded");
				}
				else if(confirm && !loadSuccessful){
					//user confirmed but sale did not go through
					interface->message("That passenger was able to be loaded. Please check your weight limit");
				}else{
					//user did not confirm
					interface->message("That passenger was not loaded.");
				}
				
				again = interface->prompt("Would like to load more passengers?","Yes","No");
				//who is responsible for looping? Ship or main? hmm...
			}else{
				again = false; //user chose the quit option
			}
		}
	}
	
	void setNewCourse(){
		
		
		bool again = true;
		while(again){
			
			vector< pair< Coordinate,int > > destinations = getDestinations();
			vector < string >  destinationStrings;
			for(pair< Coordinate,int > d:destinations){ //build strings for each layover
				//variables for readability
				Coordinate destination = d.first;
				int totalFare = d.second;
				int totalDistance = distanceTo(destination);
				int totalFuel = totalDistance * getBurnRate();
				
				ostringstream pushMe;
				
				pushMe <<
				destination.name << " \t" << //TODO:add a distance calculation
				totalFare << " BCN of fares \t" <<
				totalFuel << " fuel cells \t" <<
				totalDistance << "au away \n\t" <<
				"No Location Info Availble";
				
				destinationStrings.push_back(pushMe.str());
			}
			
			interface->message("You currently have " + to_string(getFuelCount()) + " fuel cells on hand\n");
			interface->message("Your current burn rate is " + to_string(getBurnRate()) + " cells/au \n\n");
			
			int menuChoice = interface->showMenu("Please choose the next destination",
												 destinationStrings,
												 "Please choose your next destination");
			
			if(menuChoice <= destinations.size()){//if user did not choose the close option
				
				//this is just for brevity's sake
				pair< Coordinate,int > *destination = &destinations[menuChoice-1];
				
				bool confirm = interface->prompt("You are going to fly to " +
												 destination->first.name + " (a distance of " +
												 to_string(distanceTo(destination->first)) + "au) " +
												 "for " + to_string(destination->second) + "BCN \n" +
												 "Is this correct?","Yes","No");
				bool setCourseSuccessful = false;
				if(confirm && (setCourseSuccessful = setCourse(destination->first))){
					interface->message("Course laid in successfully",true);
					engage();
					
					again = false;
				}
				else if(confirm && !setCourseSuccessful){
					//user confirmed but course did not take
					interface->message("That course could not be set. Please check your fuel levels.");
					again = interface->prompt("Would like choose a different course?","Yes","No");
				}else{
					//user did not confirm
					interface->message("Course was canceled");
					again = interface->prompt("Would like choose a different course?","Yes","No");
				}
			} else{
				again = false; //user chose the quit option
			}
		}
	}
	
	void engage(){
		int distance = distanceTo(getNext());
		thread underway(travel,distance);
		underway.detach();//to allow the user to continue using the application
		//underway.join();
		arrive();
	}
	
	static void travel(int distance){
		
		while(distance--){
			this_thread::sleep_for(chrono::milliseconds(500));
			//distanceRemaining = distance;
			//cout << ".";
		}
		
		cout << "Welcome! You have arrived at your destination. Please dock with a station.\n";
		cout << "Please press any key to continue";
		getline(cin,*new string);
	}
	
	bool dock(SpaceThing &station){
		docked = &station;
		return SpaceThing::dock(station);
	}
	
	void dock(vector<SpaceThing> &newStations){
		bool goodDock = false;
		bool again = true;
		ostringstream headings;
		headings << setw(32) << left <<
		"NAME";// << setw(16) << left <<
		//"DOCKING FEE" << setw(18) << left <<
		//"INVENTORY SIZE" << setw(10) << left <<
		//"LAYOVERS";
		
		while(again){
			vector< string > stationStrings;
			for(SpaceThing station:newStations){ //build strings for each station
				ostringstream pushMe;
				pushMe << setw(24) << left <<
				station.getName();
				
				stationStrings.push_back(pushMe.str());
			}
			
			
			int choice = interface->showMenu(headings.str(), stationStrings,"Please select a station to dock with");
			if(choice < newStations.size()){//if menu not closed
				goodDock = dock(newStations[choice-1]);
				
				if(goodDock){
					interface->message("You are now docked with " + docked->getName() + "\n",true);
					again = false;
				}
				else{
					
					interface->message("We were not able to dock with that station.");
					again = interface->prompt("Would you like tor try again?","Yes","No");
				}
			}else again = false; //the user chose close option
		}
	}
	
				
	void manageInventory(){
		
		bool again = true;
		ostringstream headings;
		headings << setw(24) << left <<
		"NAME" << setw(10) << left <<
		"TOTAL" << setw(10) << left <<
		"FOR SALE" << setw(10) << left <<
		"PRICE" << setw(10) << left <<
		"WEIGHT";
		
		while(again) {
			vector< CargoBin > allCargo = this->getCargo();
			vector< string > cargoStrings;
			for(CargoBin cargo:allCargo){ //build strings for each CargoBin
				ostringstream pushMe;
				pushMe.clear();
				pushMe << setw(24) << left <<
				cargo.name << setw(10) << left <<
				cargo.getCount() << setw(10) << left <<
				cargo.getCountForSale() << setw(10) << left <<
				cargo.getPrice() << setw(10) << left <<
				cargo.getUnitWeight();
				
				cargoStrings.push_back(pushMe.str());
			}
			
			int choice = interface->showMenu(headings.str(),cargoStrings,
											"Please select the Cargo item you would like to edit");
			if(choice <= allCargo.size()){
				CargoBin* editMe = &allCargo[choice-1]; //convience pointer
				
				//edit countForSale
				ostringstream countString;
				countString <<
				editMe->getCountForSale() << " " <<
				editMe->getName() << ((editMe->getCountForSale()==1)?(""):("s")) <<
				" are currently listed for sale. Please enter the new value or press return to leave unchanged.";
				int countForSale = interface->prompt(countString.str(),0,editMe->getCount(),true);
				if(countForSale > 0) setCountForSale(editMe->typeID,countForSale);
				
				//edit Price
				ostringstream priceString;
				priceString <<
				"The current price for " <<
				editMe->getName() << "s is " <<
				editMe->getPrice() << " BCN " <<
				"Please enter the new value or press return to leave unchanged.";
				int price = interface->prompt(priceString.str(),0,100000,true);
				if(price > 0 ) setPrice(editMe->typeID, price);
				
				again = interface->prompt("Would you like view or edit any more Cargo?", "Yes", "No");
			} else again = false; //user selected close menu
		}
	}
	
	void viewPassengers(){
		ostringstream headings;
		headings << setw(24) << left <<
		"NAME" << setw(32) << left <<
		"DESTINATION" << setw(16) << left <<
		"DISTANCE" << setw(10) << left <<
		"FARE" << setw(10) << left <<
		"WEIGHT";
		
		
			vector< Passenger > allPassengers = this->getPassengers();
			vector< string > passengerStrings;
			for(Passenger passenger:allPassengers){ //build strings for each passenger
				ostringstream pushMe;
				pushMe << setw(24) << left <<
				passenger.name << setw(32) << left <<
				passenger.destination.name << setw(16) << left <<
				distanceTo(passenger.destination) << setw(10) << left <<
				passenger.fare << setw(10) << left <<
				passenger.weight;
				
				passengerStrings.push_back(pushMe.str());
			}
			
			interface->showMenu(headings.str(), passengerStrings,"",false,false);
			
			interface->message(" ",true);
		
	}
	
	static Coordinate next;
	
private:
	Interface *interface;

};

#endif /* defined(__IAWSCA__Ship__) */
