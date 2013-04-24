//
//  File:         Station.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Non-inline member function definitions.
//

#include "Station.h"
#include <fstream>

using namespace std;

Station::Station() {
}

Station::Station(vector<InventoryItem> inventory) {
	for (InventoryItem item : inventory) {
		manifest.push_back(item);
	}
}

Station::~Station() {
}

//a published or agreed upon item and price
bool Station::sellItem(int itemNumber, int price){
	cout << "station is selling item#" << itemNumber << endl;
	//add price to balance 
	//remove item from manifest
	return true;
}

int getItemPrice(int itemNumber){
	//lookup item number price and return it
	return 42;
}

vector<string> Station::getAds() {
	vector<string> ads;
	for (InventoryItem item : manifest) {
		ads.push_back(item.getAdHeader());
	}

	return ads;
}
