

#include "SpaceThing.h"

//a published or agreed upon item and price

void SpaceThing::buy(int id) {//or referenceCode? 
	cout << "selling an item" << endl;
	InventoryItem newItem = dockedThing->sell(id,dockedThing->getItemPrice(id));
	manifest.insert(newItem);
}

InventoryItem SpaceThing::sell(int itemNumber, int price) {
	cout << "I am selling item #" << itemNumber << endl;
	//add price to balance 
	//remove item from manifest
	InventoryItem newItem = removeItem(itemNumber);
	return newItem;
		
}

InventoryItem SpaceThing::removeItem(int id) {
	set<InventoryItem>::iterator originalItem = manifest.find(*(new InventoryItem(id)));
	InventoryItem newItem(*originalItem);
	manifest.erase(originalItem);
	return newItem;
}

int SpaceThing::getItemPrice(int itemNumber) {
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

vector<string> SpaceThing::getExternalAds(){
	return dockedThing->getAds();
}

void SpaceThing::dock(SpaceThing &dockedThing){
	this->dockedThing = &dockedThing;
	docked = true;
}

bool SpaceThing::isDocked(){
	return docked;
}