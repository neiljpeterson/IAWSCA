//
//  File:         main.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Driver application.
//
//  Last Edit: Neil 18Apr13 1300
//

#include "Ship.h"
#include "Station.h"
#include "InventoryItem.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

/**
 *  Had to do a cut/paste job on main. it was unsalvageable. 
 */

int choose(int); //make ship static?
void quit(); //only exit from main? bad form?

void buySupplies();
void sellSupplies();
void viewInventory();
int table(vector< vector<string> >);
//int menu(vector<string>&);
int menu(vector<string>,string header = "",int spaces = 1,bool exitOption = true);
int getIntWithinRange(int, int, string);
void pressAnyKey(string prompt = "\nPlease press the any key...");

//Copied from C++11 array.h Returns ptr to begin and end of an c-style array

template <typename T, size_t N>
T* beginT(T(&arr)[N]) {
	return &arr[0];
}

template <typename T, size_t N>
T* endT(T(&arr)[N]) {
	return &arr[0] + N;
}
//end copy. TODO: understand this.

static Ship ship; //TODO: make pointers?

int main() {
	//TODO: How does the ship get created? Do we need an option for Create new ship or Load existing ship?

	//ship = new Ship; //if these become pointers, this will be needed
	//staton = new Station;

	string choices[] = {//TODO: map menu options to function pointers??
		"Buy supplies", //1
		"Sell supplies", //2
		"Load passengers", //3
		"Unload passengers", //4
		"View passengers", //5 new
		"Hire crew member", //6
		"Fire crew member", //7 new
		"View crew", //8 new
		"Travel to station", //9
		"View message", //10
		"View inventory", // 11
	};
		
		vector<string> options(beginT(choices), endT(choices));
		int choice = 0;
	
		while (choice != -1)
			choice = choose(menu(options,"Please choose one"));


	return 0;
}

int choose(int choice) //TODO: Is there a more robust way to do this, possibly with func ptrs?
{
	switch (choice) {
		case 1: buySupplies();
			break;
		case 2: sellSupplies();
			break;
		case 3: ship.loadPassengers();
			break;
		case 4: ship.unloadPassengers();
			break;
		case 5: //ship.viewPassengers(); //Not defined yet
			break;
		case 6: ship.hireCrewMember();
			break;
		case 7: //ship.fireCrewMember(); //Not defined yet
			break;
		case 8: //ship.viewCrew(); //Not defined yet
			break;
		case 9: ship.travelToStation();
			break;
		case 10: ship.viewMessage();
			break;
		case 11: viewInventory();
			break;
		case 12: quit();
	}

	pressAnyKey();
	return choice;
}

void quit() {
	cout << "Goodbye" << endl;
	exit(0); //exit should be in main?
}

void buySupplies() {
	vector<string> ads;
	vector<int> ids;
	//ads.push_back("This station has the following items for sale");
	
	for(pair<int,string> ad:ship.getExternalAds()){ // will return a Map<int,string> eventually
		//ads.push_back(string(ad.first) + ": " + ad.second); //what the hell??
		ads.push_back(ad.second);
		ids.push_back(ad.first);
		
	}
	
	
	
	int choice = menu(ads,"This station has the following items for sale",2,1);

	if(choice!=-1){
		ship.buy(ids[choice]);
		cout << "You just bought item #" << choice << endl;
		//Will list item title
		
	}
	
	
}

void sellSupplies(){
	//send out ad alert
	//wait
	cout << "Selling supplies" << endl;
}
//might be rolled into seprate class eventually?
//IO.cpp?

//template <typename T>

void viewInventory(){
	//get inventory strings
	vector<string> inventory;
	for(string item:ship.getInventory()){
		inventory.push_back(item);
	}
	menu(inventory,"SHIP'S INVENTORY",2,1);
}
int table(vector< vector<string> > data) {
	int row = 0;
	int col = 0;
	int rows = data[0].size();
	int cols = data.size();
	for (row = 0; row < rows; row++) { //max number of rows looks to first element for now. fix later
		for (col = 0; col < cols; col++) {
			cout << data[col][row] << "\t"; //carl rove??
		}
		cout << "\n";
	}
	return 1;
}

//returns -1 if exitOption and exit option is chosen
int menu(vector<string> options,string header,int spaces, bool exitOption) { 
	//might need multiple prototypes

	system("clear"); //TODO: detect various OSs and pass appropriate commands
	//system("cls");

	
	if (exitOption) options.push_back("Exit Menu");
	if (!header.empty()) cout << header << "\n\n";
	
	for (int index = 0; index < options.size(); index++) {
		cout << index+1 << " - " << options[index] << endl;
		int newLines = spaces;
		while(--newLines > 0){
			cout << endl;
		}
	}

	//sexy C++11
	//   for(string option:options){
	//     if(choice++) cout << choice - 1 << ": ";
	//     cout << option << endl;
	//   }

	cout << "> ";

	int choice = getIntWithinRange(1, options.size(), "That is not a valid option. Please try again\n");
	if(choice == options.size()) choice = -1;
	
	return choice;
	//Framework for createing menus and passing them to the choose function
	// string options[] = {"Please choose one", "Option A","Option B", "Option C"};
	// vector<string> menu (begin(options), end(options));
	// choose(menu);
}

int getIntWithinRange(int min, int max, string error) {
	int input;
	bool badInput = true;
	while (badInput) {
		cin >> input;
		cin.ignore();
		if (input < min || input > max) cout << error;
		else badInput = false;
	}
	return input;
}

void pressAnyKey(string prompt) {
	cout << prompt;
	cin.ignore();
}

