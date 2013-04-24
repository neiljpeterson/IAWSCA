/* 
 * File:   SpaceThing.h
 * Author: Neil
 *
 * Created on April 23, 2013, 10:04 PM
 */

#ifndef SPACETHING_H
#define	SPACETHING_H
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include "InventoryItem.h"
using namespace std;

class SpaceThing {
public:

	SpaceThing() {
	};

	~SpaceThing() {
	};

	SpaceThing(vector<InventoryItem> inventory) {
		for (InventoryItem item : inventory) {
			manifest.insert(item);
		}
	}

	void buy(int);
	InventoryItem sell(int, int);
	
	map<int,string> getExternalAds();
	map<int,string> getAds();
	
	int getItemPrice(int);
	InventoryItem removeItem(int id);
	
	
	

	
	void dock(SpaceThing&);
	bool isDocked();
	
	void setName(const string name){this->name = name;};
	string getName(){return name;};
	
protected:
	
	set<InventoryItem> manifest;
	SpaceThing* dockedThing;
	bool docked;
	string name;
};

#endif	/* SPACETHING_H */