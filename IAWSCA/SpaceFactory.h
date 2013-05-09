//
//  SpaceFactory.h
//  IAWSCA
//
//  Created by Neil Peterson on 5/9/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef __IAWSCA__SpaceFactory__
#define __IAWSCA__SpaceFactory__

#include "../SpaceThing/SpaceThing.h"

#include "../SpaceThing/SpaceTrader/SpaceTrader.h"
#include "../SpaceThing/SpaceTrader/CargoBin.h"

#include "../SpaceThing/SpaceTraveler/Passenger.h"
#include "../SpaceThing/SpaceTraveler/Coordinate.h"


#include <iostream>

struct SpaceFactory{

	static SpaceThing buildSpaceThing(){
		vector<SpaceThing> thing = buildSpaceThings(1);
		return thing[0];
	}
	
	static vector<SpaceThing> buildSpaceThings(int n){
		vector<SpaceThing> things;
		
		return things;
	}
};
#endif /* defined(__IAWSCA__SpaceFactory__) */
