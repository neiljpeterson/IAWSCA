//
//  main.cpp
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

//#include "Ship.h"
//#include "../SpaceThing/SpaceTrader/SpaceTrader_Tests.h"
//#include "../SpaceThing/SpaceTraveler/SpaceTraveler_tests.h"
//#include "../SpaceThing/SpaceTalker/SpaceTalker_Tests.h"
#include "../SpaceThing/SpaceThing_tests.h"

#include "./Ship.h"
#include "../Interface/Interface.h"

#include <iostream>
#include <string>
#include <vector>
#include <map>

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

//being lazy with function declarations
//switch to declaration-definition pattern for final product


int main(int argc, const char * argv[])
{
	//Begin Tests
	if(true){
		//SpaceThing_tests::runAll();

		Interface interface;
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
		
		Ship ship(interface,"HMS Down-to-the-wire",Coordinate(0,0,0,"Earth"),1000,2000,passengersB);
		
		SpaceThing station("Station",100,100,Coordinate(0,0,0,"Earth"),passengersA);
		
		ship.dock(station);

//		cout << "Testing Buy function\n\n";
//		ship.buy();
//		cout << "Testing Load Passangers\n\n";
//		ship.loadPassengers();
		cout << "Testing New Course\n\n";
		ship.setNewCourse();
		
		
	}
	
	//End Tests

//    Interface interface;// OR = new Ncurses_Interface();
//	
//	string c[] = {//TODO: map menu options to function pointers??
//		"Buy supplies", //1
//		"Sell supplies", //2
//		"Load passengers", //3
//		"Unload passengers", //4
//		"View passengers", //5 new
//		"Hire crew member", //6
//		"Fire crew member", //7 new
//		"View crew", //8 new
//		"Travel to station", //9
//		"View message", //10
//		"View inventory", // 11
//	};
//	
//	vector<string> choices(begin_address(c),end_address(c));
//	
//	interface.newMenu("Main","Please choose",choices);
//	
//	interface.showMenu("Main");
//	
//	int choice = interface.getInt(choices.size());

	cout << "Goodbye!" << endl;
    return 0;
}

