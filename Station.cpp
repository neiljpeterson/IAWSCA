//
//  File:         Station.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Non-inline member function definitions.
//

#include "Station.h"
#include "Bacon.h"
#include <fstream>

using namespace std;

template <typename T, size_t N>
T* tBegin(T(&arr)[N]) { return &arr[0]; }

template <typename T, size_t N>
T* tEnd(T(&arr)[N]) { return &arr[0]+N; }

//*************************************************************************

Station::Station()
{
	name = "";
	dockingFee = 0;
	stationID = 7;
	offer = "";
	price = stationID%3;
}

Station::~Station()
{
}

//*************************************************************************

string choices[] = { //TODO: map menu options to function pointers??
		"Please choose one", 
		"Warp Manifolds", //1
		"Plasma Relays", //2
		"EPS Conduites", //3
		"Sell Items", //4
		"Back to ship menu" //5
		};

//*************************************************************************

int Station::getPrice()
{
	return price;
}

//*************************************************************************

string Station::buyMenu(){
	vector<string> options (tBegin(choices), tEnd(choices));
	int choice = 0;
	int amount = 0;

	while(choices[choice] != "Back to ship menu")
		choice = chooseToBuy(menu(options), amount);

	return choices[choice];
}

//*************************************************************************

int Station::chooseToBuy(int choice, int amount)
{
	switch (choice) {
		case 1: amount = numberToBuy(choices[choice], amount);
			break;
		case 2: amount = numberToBuy(choices[choice], amount);
			break;
		case 3: amount = numberToBuy(choices[choice], amount);
			break;
		case 4: sellMenu();
			break;
		case 5: break;
	}

	return choice;
}

//*************************************************************************

string Station::sellMenu(){
	vector<string> options (tBegin(choices), tEnd(choices));
	int choice = 0;
	int amount = 0;

	while(choices[choice] != "Back to ship menu")
		choice = chooseToSell(menu(options), amount);

	return choices[choice];
}

//*************************************************************************

int Station::chooseToSell(int choice, int amount)
{
	string hi;
	switch (choice) {
		case 1: amount = numberToSell(choices[choice], amount);
			break;
		case 2: amount = numberToSell(choices[choice], amount);
			break;
		case 3: amount = numberToSell(choices[choice], amount);
			break;
		case 4: buyMenu();
			break;
		case 5: break;
	}

	return choice;
}

//*************************************************************************

int Station::numberToBuy(const string & choice, int amount)
{
	int items = 0;
	int baconAmount = 0;
	cout << "How many " << choice << " would you like to buy?\n";
	cin >> amount;
	return amount*getPrice();
}

//*************************************************************************

int Station::numberToSell(const string & choice, int amount)
{
	int items = 0;
	cout << "How many " << choice << " would you like to sell?";
	cin >> amount;
	return amount;
}

//*************************************************************************

int Station::menu(vector<string>& options)
{
	system("clear"); //TODO: detect verious OSs and pass appropriate commands
	system("cls");

	int choice = 0;
 
	for(size_t choice = 0; choice < options.size(); choice++){
		if(choice) 
		{
			cout << choice << ": "; 
			cout << options[choice] << endl;
		}
}


cout << "> ";

return getIntWithinRange(1,options.size(),"That is not a valid option. Please try again\n");
}

//*************************************************************************

int Station::getIntWithinRange(int min, int max, string error)
{
	int input = 0;
	bool badInput = true;
	while(badInput) {
		cin >> input; 
		cin.ignore();
		if(input < min || input > max) 
			cout << error;
		else badInput = false;
		}
	return input;
}

//*************************************************************************