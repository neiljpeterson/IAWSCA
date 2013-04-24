

#include "SpaceThing.h"

//a published or agreed upon item and price
InventoryItem SpaceThing::sellItem(int itemNumber, int price){
	cout << "station is selling item#" << itemNumber << endl;
	//add price to balance 
	//remove item from manifest
	return removeItem(itemNumber);
}

InventoryItem SpaceThing::removeItem(int id){
	InventoryItem item = *manifest.find(*(new InventoryItem(id)));
	manifest.erase(item);
	return item;
}

int SpaceThing::getItemPrice(int itemNumber){
	//lookup item number price and return it
	return 42;
}

vector<string> SpaceThing::getAds() {
	vector<string> ads;
	for (InventoryItem item : manifest) {
		ads.push_back(item.getAdHeader());
	}

	return ads;
}

