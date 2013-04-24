//
//  File:         CargoItem.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Non-inline member function definitions.
//

#include "CargoItem.h"
#include <fstream>

using namespace std;

CargoItem::CargoItem(int w, int u)
{
	setWeight(w);
	setUnits(u);
}

CargoItem::~CargoItem()
{
}

void CargoItem::setWeight(int w)
{
    weight = w;
}

void CargoItem::setUnits(int u)
{
    units = u;
}

int CargoItem::getUnits()
{
	return units;
}