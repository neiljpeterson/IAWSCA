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

	InventoryItem sellItem(int, int);
	InventoryItem sellItem(int);
	vector<string> getAds();
	int getItemPrice(int);
	InventoryItem removeItem(int id);


private:
	set<InventoryItem> manifest;
};

#endif	/* SPACETHING_H */