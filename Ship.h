#ifndef SHIP_H
#define SHIP_H

//
//  File:         Ship.h
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  A class definition for Ship.
//
#include <iostream>
#include <string>

class Ship {
public:
    /**
     *  Constructor
     */
    Ship(const std::string& n);

    /**
     *  Destructor
     */
    ~Ship();

    /**
     *  Modifier function to set the name of the store
     */
    void setName(const std::string& n);

    /**
     *  Access function to get the name of the store
     */
    std::string getName() const;

    /**
     *  Display store information
     */
    void displayStore() const;

    /**
     *  Add a new Customer
     */
    void addNewCust();

    /**
     *  Display all existing customers
     */
    void displayCusts() const;

    /**
     *  Add an item (existing title)
     */
    void addItem();

    /**
     *  Add a new title
     */
    void addItemSpec();

    /**
     *  Display all items
     */
    void displayAllItems() const;

    /**
     *  Display a item specification
     */
    void displayItemSpec() const;

    /**
     *  Display items with a specific title
     */
    void displayItems() const;

    /**
     *  Display all videos
     */
    void displayVideos() const;

    /**
     *  Display all DVDs
     */
    void displayDVDs() const;


private:

    /**
     *  Name of Store
     */
    std::string name;

};

/**
 *  Access function to get the name of the store
 */
inline
std::string Store::getName() const
{
    return name;
}

#endif
