//
//  Coordinate.h
//  IAWSCA
//
//  Created by Neil Peterson on 5/4/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef IAWSCA_Coordinate_h
#define IAWSCA_Coordinate_h

#include <sstream>

struct Coordinate{
	//Coordinate(string n,double x = 0.0,double y = 0.0,double z = 0.0):x(x),y(y),z(z),name(n){};
	Coordinate(double x = 0.0,double y = 0.0,double z = 0.0,string n="Unnamed"):
	x(x),y(y),z(z),name(n)
	{};
	
	//const Coordinate(const Coordinate &c):x(c.x),y(c.y),z(c.z){};
	string name;
	string toString(){
		ostringstream result;
		result << name << " [" << x << ", " << y << ", " << z << "]";
		return result.str();
	};
	
	double x;
	double y;
	double z;
};

#endif
