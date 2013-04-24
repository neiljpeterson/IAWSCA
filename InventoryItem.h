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
	InventoryItem(int id){
		this->setId(id);
	}
	InventoryItem(string name, int price, string ad, int id = 42) {
		this->setId(id);
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

	bool operator==(const InventoryItem& right) const { return this->id == right.getId();}
	bool operator!=(const InventoryItem& right) const { return *this != right;}
	bool operator<(const InventoryItem& right) const { return this->id < right.getId();}
	bool operator>(const InventoryItem& right) const { return *this > right;}
	bool operator<=(const InventoryItem& right) const { return *this < right;}
	bool operator>=(const InventoryItem& right) const { return *this > right;}
	
	
	string getAdHeader();
	string getAdBody();

	int const getId() const {
		return id;
	};

	void setId(int value) {
		id = value;
	};
private:
	int id;

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

