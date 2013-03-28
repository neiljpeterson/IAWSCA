//
//  File:         Store.cpp
//
//  Author:       Peter Maher
//
//  Description:  Non-inline member function definitions.
//
#include "Store.h"
#include <fstream>

/**
 *  Constructor
 */
Store::Store(const std::string& n)
{
    using namespace std;

    setName(n);

    cout << "Store constructor executed" << endl;
}

/**
 *  Destructor
 */
Store::~Store()
{
    using namespace std;

    cout << "Store destructor executed" << endl;
}

/**
 *  Modifier function to set the name of the store
 */
void Store::setName(const std::string& n)
{
    name = n;
}

/**
 *  Display store information
 */
void Store::displayStore() const
{
    using namespace std;

    cout << "Store's name: " << name << endl;
}

/**
 *  Add a new Customer
 */
void Store::addNewCust()
{
   using namespace std;

   cout << "Adding a new customer" << endl;
}

/**
 *  Display all existing customers
 */
void Store::displayCusts() const
{
   using namespace std;

   cout << "Displaying all existing customers" << endl;
}

/**
 *  Add an item (existing title)
 */
void Store::addItem()
{
    using namespace std;

    cout << "Adding an item" << endl;
}

/**
 *  Add a new title
 */
void Store::addItemSpec()
{
    using namespace std;

    cout << "Add a new title" << endl;
}

/**
 *  Display all items
 */
void Store::displayAllItems() const
{
   using namespace std;

   cout << "Display all items" << endl;
}

/**
 *  Display a item specification
 */
void Store::displayItemSpec() const
{
   using namespace std;

   cout << "Display an item specification" << endl;
}

/**
 *  Display items with a specific title
 */
void Store::displayItems() const
{
    using namespace std;

    cout << "Display items with a specified title" << endl;
}

/**
 *  Display all videos
 */
void Store::displayVideos() const
{
    using namespace std;

    cout << "Display all videos" << endl;
}

/**
 *  Display all DVDs
 */
void Store::displayDVDs() const
{
   using namespace std;

   cout << "Display all DVDs" << endl;
}