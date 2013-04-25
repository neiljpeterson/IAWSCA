

#include "SpaceThing.h"

//a published or agreed upon item and price

void SpaceThing::buy(int id) {
	cout << "selling an item" << endl;
	InventoryItem newItem = dockedThing->sell(id,dockedThing->getItemPrice(id));
	manifest.insert(newItem);
}

InventoryItem SpaceThing::sell(int itemNumber, int price) {
	
	depositBacon(price);
	//remove item from manifest
	InventoryItem newItem = removeItem(itemNumber); //I think this is where the segmentation fault is
	
	
	return newItem;
		
}

bool SpaceThing::depositBacon(int amount){
	//TODO: extend vector<InventoryItem> to create custom methods
	//TODO: OR create InventoryItem.Int() and InventoryItem.String() implicit conversion 
	//for type and id .find
	//Would also need comparison operator methods with string and int as left side
	bool goBaconGo = true;
	
	//manifest.insert( *(new InventoryItem("Bacon",1,"",100)) );
			
	set<InventoryItem>::iterator bacon 
		= manifest.find( *(new InventoryItem(100)) ); //bacon will live at 100 until type stuff works
	
	if(bacon == manifest.end()) {
		pair<set<InventoryItem>::iterator,bool> baconItem 
		= manifest.insert( *(new InventoryItem("Bacon",1,"",100)) );
		bacon = baconItem.first;
		goBaconGo = baconItem.second;
	}
	
	if(goBaconGo) { // all this should be handled by a wrapper class
		InventoryItem newBacon = *bacon;
		manifest.erase(bacon);
		newBacon.increaseQuantity(amount);
		manifest.insert(newBacon); 
	}
	
	return goBaconGo;
}

InventoryItem SpaceThing::removeItem(int id) {
	set<InventoryItem>::iterator originalItem 
		= manifest.find(*(new InventoryItem(id)));
	InventoryItem newItem(*originalItem);
	manifest.erase(originalItem);
	return newItem;
}

int SpaceThing::getItemPrice(int itemNumber) {
	//lookup item number price and return it
	return 42;
}

map<int,string> SpaceThing::getAds() {
	map<int,string> ads;
	for (InventoryItem item : manifest) {
		ads.insert( std::pair<int,string>(item.getId(), item.getAdHeader()));
	}

	return ads;
}

map<int,string> SpaceThing::getExternalAds(){
	return dockedThing->getAds();
}

void SpaceThing::dock(SpaceThing &dockedThing){
	this->dockedThing = &dockedThing;
	docked = true;
}

bool SpaceThing::isDocked(){
	return docked;
}

