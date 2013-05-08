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
		cout << "Testing Buy function\n\n";
		Interface interface;
		Ship ship(interface);
		SpaceThing station("Station",100,100);
		ship.dock(station);
		ship.buy();
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

    return 0;
}

