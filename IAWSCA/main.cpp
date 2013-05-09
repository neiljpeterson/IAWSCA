//
//  main.cpp
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#include "./Ship.h"
#include "../Interface/Interface.h"

#include <iostream>
#include <string>
#include <vector>
//#include <map>

//Copied from C++11 array.h Returns ptr to begin and end of an c-style array
template <typename T, size_t N>
T* begin_address(T(&arr)[N]) {
	return &arr[0];
}

template <typename T, size_t N>
T* end_address(T(&arr)[N]) {
	return &arr[0] + N;
}
//end copy


vector<SpaceThing> makeNewStations();

bool exit();

int main(int argc, const char * argv[])
{
	//Begin Tests
	
	//SpaceThing_tests::runAll();
	
	
	vector < Passenger > passengersA;
	vector < Passenger > passengersB;
	
	passengersB.push_back(Passenger("Saffron",200,50
									,Coordinate(20,15,12,"Delphi System"),"I travel very light"));
	
	passengersB.push_back(Passenger("Mrs. Reynolds",150,120
									,Coordinate(2,2,2,"Europa Colony"),"Just trying to get back my husband!"));
	
	passengersB.push_back(Passenger("Yolanda",500,100
									,Coordinate(20,15,12,"Delphi System"),"I am a courier of sensitive items"));
	
	passengersB.push_back(Passenger("Tracey Smith ",200,50
									,Coordinate(20,15,12,"Delphi System"),"Just a guy"));
	
	passengersB.push_back(Passenger("Magistrate Higgins ",600,120
									,Coordinate(2,2,2,"Europa Colony"),"I am very important person"));
	
	passengersB.push_back(Passenger("Stitch Hessian",100,100
									,Coordinate(100,72,32,"3rd moon of Persephone"),"Just get me there"));
	
	SpaceThing station("Station",100,100,Coordinate(0,0,0,"Earth"),passengersB);
	
	
	
	//		cout << "Testing Buy function\n\n";
	//		ship.buy();
	//		cout << "Testing Load Passangers\n\n";
	//		ship.loadPassengers();
	//		cout << "Testing New Course\n\n";
	//		ship.setNewCourse();
	
//==============================================everything above line is trash
	
	Interface interface;
	
	Ship ship(interface,"HMS Down-to-the-wire",Coordinate(0,0,0,"Earth"),1000,2000);
	ship.dock(station);//trash
	bool close;
	
	string choices[] = {//TODO: map menu options to function pointers??
		"TRADE CARGO", //1
		"LOAD PASSENGERS", //2
		"DISEMBARK", //3
		"DOCK", //4
		"VIEW INVENTORY", //5
		"VIEW PASSENGERS", //6
	};
	
	while (!close) {
		
		vector < string >  mainMenu(begin_address(choices),end_address(choices));
		
		int choice = interface.showMenu("MAIN MENU", mainMenu,"Please choose an action");
		
		switch (choice){
			case 1: ship.buy();
				break;
			case 2: ship.loadPassengers();
				break;
			case 3: ship.setNewCourse();
				break;
			case 4: ship.dock( makeNewStations() );
				break;
			case 5: ship.viewInventory();
				break;
			case 6:	ship.viewPassengers();
				break;
			case 7: close = exit();
				break;
		}
	}
	
    return 0;
}

vector<SpaceThing> makeNewStations(){
	
}

bool exit(){
	cout << "Goodbye!" << endl;
}

