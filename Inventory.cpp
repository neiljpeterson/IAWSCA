//
//  File:         Inventory.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Non-inline member function definitions.
//

#include "Inventory.h"
#include <fstream>

using namespace std;

Inventory::Inventory()
{
	int prices = 0;
	string itemNames = "";
	Supplies* inventory = 0;
}

Inventory::~Inventory()
{
}

void Inventory::addCargoItem(int supplyType)
{
}

void Inventory::removeCargoItem(int supplyType)
{
}

void Inventory::displayCargoItems(int supplyType)
{
}

void Inventory::displayStations()
{
}

void Inventory::setName(std::string & n)
{
	itemNames = n;
}

string Inventory::getName()
{
	return itemNames;
}

void Inventory::setPrice(int p)
{
	prices = p;
}

int Inventory::getPrice()
{
	return prices;
}