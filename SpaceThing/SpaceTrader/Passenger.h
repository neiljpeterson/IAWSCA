//
//  Passanger.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/29/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef __IAWSCA__Passenger__
#define __IAWSCA__Passenger__

#include "./CargoBin.h"

#include <iostream>
#include <utility>
#include <map>

using namespace std;

class Passenger:public CargoBin{
	 
	Passenger():CargoBin(ACR.PAX){};

	map<int, string> passangers;
};

#endif /* defined(__IAWSCA__Passenger__) */
