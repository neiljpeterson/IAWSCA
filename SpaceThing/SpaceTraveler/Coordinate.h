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
#include <cstdlib>

#define ACCURACY 2

using namespace std;

struct Coordinate{
	//Coordinate(string n,double x = 0.0,double y = 0.0,double z = 0.0):x(x),y(y),z(z),name(n){};
	Coordinate(double x = 0.0,double y = 0.0,double z = 0.0,string n="Unnamed"):
	x(x),y(y),z(z),name(n)
	{}
	
	//const Coordinate(const Coordinate &c):x(c.x),y(c.y),z(c.z){};
	
	const bool equals(const Coordinate &compareMe) const {
		return ( (abs((int)(this->x - compareMe.x)) < ACCURACY ) &&
				 (abs((int)(this->x - compareMe.x)) < ACCURACY ) &&
				 (abs((int)(this->x - compareMe.x)) < ACCURACY )
				);
	}

	const bool less(const Coordinate &compareMe) const {
			return
		( this->x + this->y + this->z ) < (compareMe.x + compareMe.y + compareMe.z);
	}
	

	
	string toString(){
		ostringstream result;
		result << name << " [" << x << ", " << y << ", " << z << "]";
		return result.str();
	}
	
	string name;
	double x;
	double y;
	double z;
};

inline bool operator==(const Coordinate& lhs, const Coordinate& rhs){return lhs.equals(rhs); }
inline bool operator!=(const Coordinate& lhs, const Coordinate& rhs){return !operator==(lhs,rhs);}
inline bool operator< (const Coordinate& lhs, const Coordinate& rhs){return lhs.less(rhs);}
inline bool operator> (const Coordinate& lhs, const Coordinate& rhs){return  operator< (rhs,lhs);}
inline bool operator<=(const Coordinate& lhs, const Coordinate& rhs){return !operator> (lhs,rhs);}
inline bool operator>=(const Coordinate& lhs, const Coordinate& rhs){return !operator< (lhs,rhs);}

#endif
