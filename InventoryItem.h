/* 
 * File:   InventoryItem.h
 * Author: Neil
 *
 * Created on April 18, 2013, 1:59 PM
 */

#ifndef INVENTORYITEM_H
#define	INVENTORYITEM_H

#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
using namespace std;

class InventoryItem {
public:

	InventoryItem() {
		//init();
	};
	
	InventoryItem(int id){
		init();
		this->setId(id);
	}
	
	//Copy Constructor
	//tried to use getters, got const errors
	InventoryItem(const InventoryItem &copyMe) {
		init();
		this->setId(copyMe.id);
		this->setName(copyMe.name);
		this->setPrice(copyMe.price);
		this->setAdHeader(copyMe.adHeader);
		this->quantity = copyMe.quantity;
	}
	
	InventoryItem(string name, int price, string ad, int id, int quantity) {
		init();
		this->setId(id);
		this->setName(name);
		this->price = price;
		this->adHeader = ad;
		this->quantity = quantity;
	};

	~InventoryItem() {
	};
	
	void init(){ //inits that should happen for all constructors here
		//char baconSymbol = '\u3647';
		//quantity = 0;
	}
	
	//Could be inline, non-member and/or friend functions??
	bool operator==(const InventoryItem& right) const { return this->id == right.id;}
	bool operator!=(const InventoryItem& right) const { return *this != right;}
	bool operator<(const InventoryItem& right) const { return this->id < right.id;}
	bool operator>(const InventoryItem& right) const { return *this > right;}
	bool operator<=(const InventoryItem& right) const { return *this < right;}
	bool operator>=(const InventoryItem& right) const { return *this > right;}
	
	operator std::string() const { return toString(); }
	
	
	int const getId() {return id;};
	void setId(int value) {id = value;};
	
	string const getName() {return name;};
	void setName(string value) {name = value;};
	
	string const getType() {return type;};
	void setType(string value) {type = value;};
	
	int const getPrice() {return price;};
	void setPrice(int value) {price = value;};
	
	bool const getForSale() {return forSale;};
	void setForSale(bool value) {forSale = value;};
	
	string const getAdHeader() {
		string quantityString = static_cast<ostringstream*>( &(ostringstream() << quantity) )->str();
		string priceString = static_cast<ostringstream*>( &(ostringstream() << price) )->str();
		//string priceString = static_cast<ostringstream*>( &(ostringstream() << price) )->str();
		//char baconSymbol = '\u3647';
		return name 
			+ "\t" + quantityString
			+ "\tBCN " + priceString + "/each" 
			+ "\n" + adHeader;
	};
	void setAdHeader(string value) {adHeader = value;};
	
	string  const getAdBody() {return adBody;};
	void setAdBody(string value) {adBody = value;};

	int const getQuantity() {return quantity;};
	void increaseQuantity(int value) {quantity += value;};
	void decreaseQuantity(int value) {quantity -= value;};
	
	string toString() const {
		//is there a better way to build strings in c++11??
		string quantityString = static_cast<ostringstream*>( &(ostringstream() << quantity) )->str();
		return name + "\t\t\t" + quantityString;
	}
	
private:
	int id;
	int quantity;
	string name;
	string type;
	int price;
	bool forSale;
	string adHeader;
	string adBody;

};

/*inline getter setter code, this way is faster
 *I get a "no matching functions error"
inline bool operator==(const InventoryItem& left, const InventoryItem& right) {
	return left.iNum() == right.iNum();
}

inline bool operator!=(const InventoryItem& left, const InventoryItem& right) {
	return !operator==(left, right);
}

inline bool operator<(const InventoryItem& left, const InventoryItem& right) {
	return left.iNum() < right.iNum();
}

inline bool operator>(const InventoryItem& left, const InventoryItem& right) {
	return operator<(right, left);
}

inline bool operator<=(const InventoryItem& left, const InventoryItem& right) {
	return !operator>(left, right);
}

inline bool operator>=(const InventoryItem& left, const InventoryItem& right) {
	return !operator<(left, right);
}
 */

#endif	/* INVENTORYITEM_H */

