/* 
 * File:   InventoryItem.h
 * Author: Neil
 *
 * Created on April 18, 2013, 1:59 PM
 */

#ifndef INVENTORYITEM_H
#define	INVENTORYITEM_H

#include <string>
using namespace std;

class InventoryItem {
public:

	InventoryItem() {
	};

	InventoryItem(string name, int price, string ad) {
		this->name = name;
		this->price = price;
		this->adHeader = ad;
	};

	~InventoryItem() {
	};

	string name;
	string type;
	int price;
	bool forSale;
	string adHeader;
	string adBody;

	
	string getAdHeader();
	string getAdBody();
private:


};

#endif	/* INVENTORYITEM_H */

