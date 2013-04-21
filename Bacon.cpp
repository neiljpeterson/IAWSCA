//
//  File:         Bacon.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Non-inline member function definitions.
//

#include "Bacon.h"
#include <fstream>

using namespace std;

Bacon::Bacon(int w, int u) : CargoItem(w, u)
{
}

Bacon::~Bacon()
{
}

int Bacon::getAmount()
{
	return getUnits();
}

void Bacon::gainBacon()
{
}

void Bacon::spendBacon()
{
}