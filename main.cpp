//
//  File:         main.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Driver application.
//
#include "Ship.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

/**
 *  Display the main menu and read selection from user
 */

int choose(int,Ship&); //make ship static?
void quit(); //only exit from main? bad form?

int menu(vector<string>&); 
int getIntWithinRange(int,int,string);
void pressAnyKey(string prompt = "\nPlease press the any key...");

//Copied from C++11 array.h Returns ptr to begin and end of an c-style array
template <typename T, size_t N>
T* begin(T(&arr)[N]) { return &arr[0]; }

template <typename T, size_t N>
T* end(T(&arr)[N]) { return &arr[0]+N; }
//end copy. TODO: understand this.

int main()
{
    //TODO: How does the ship get created? Do we need an option for Create new ship or Load existing ship?
    Ship ship; //"Welcome, captain, to your starship. My name is " Ship.name". Let's space today!");

    string choices[] = { //TODO: map menu options to function pointers??
    "Please choose one", 
    "Buy supplies", //1
    "Sell supplies", //2
    "Load passengers", //3
    "Unload passengers", //4
    "View passengers",  //5 new
    "Hire crew member", //6
    "Fire crew member", //7 new
    "View crew",      //8 new
    "Travel to station", //9
    "View message", //10
    "View inventory", // 11
    "Quit" //12
    };
    
    vector<string> options (begin(choices), end(choices));
    int choice = 0;

    while(choices[choice] != "Quit")
    choice = choose(menu(options),ship);

    return 0;
}

int choose(int choice,Ship& ship)
{
    switch (choice) {
        case 1: ship.buySupplies();
          break;
        case 2: ship.sellSupplies();
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
        case 11 : ship.viewInventory();
            break;
        case 12: quit();
    }

    pressAnyKey();
    return choice;
}

void quit(){
  cout << "Goodbye" << endl;
  exit(0);
}

//might be rolled into seperate class eventually?
//IO.cpp?
int menu(vector<string>& options){ 
  
  system("clear"); //TODO: detect verious OSs and pass appropriate commands
  system("cls");

 int choice = 0;
 
  for(int choice = 0; choice < options.size(); choice++){
    if(choice) cout << choice << ": "; //0th element is menu header, no #:
    cout << options[choice] << endl;
  }

//sexy C++11
//   for(string option:options){
//     if(choice++) cout << choice - 1 << ": ";
//     cout << option << endl;
//   }

  cout << "> ";

  return getIntWithinRange(1,options.size(),"That is not a valid option. Please try again\n");

//Framework for createing menus and passing them to the choose function
// string options[] = {"Please choose one", "Option A","Option B", "Option C"};
// vector<string> menu (begin(options), end(options));
// choose(menu);
}

int getIntWithinRange(int min, int max, string error){
  int input;
  bool badInput = true;
  while(badInput) {
    cin >> input; 
    cin.ignore();
    if(input < min || input > max) cout << error;
    else badInput = false;
  }
  return input;
}

void pressAnyKey(string prompt){
  cout << prompt;
  cin.ignore();
}


