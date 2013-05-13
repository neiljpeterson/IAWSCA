//
//  Station.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/30/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef __IAWSCA__Station__
#define __IAWSCA__Station__

#include "../SpaceThing/SpaceThing.h"
//#include "../SpaceFactory/SpaceFactory.h"

#include <iostream>

using namespace std;

class Station: public SpaceThing{
public:
	
	//SpaceThing(String name,int bacon, int fuel,
	//vector<CargoBin> otherCargo,Coordinate location,vector<Passenger> passengers)\
	
	Station(SpaceThing &thing):
	SpaceThing(thing)
	{};

};
#endif /* defined(__IAWSCA__Station__) */


