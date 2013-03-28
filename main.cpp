//
//  File:         main.cpp
//
//  Author:       Brendan Nash & Neil Peterson
//
//  Description:  Driver application.
//
#include "Ship.h"
#include <iostream>

/**
 *  Display the main menu and read selection from user
 */
char mainMenu();

/**
 *  Select desired menu option
 */
void selectOption(Ship& s, char option);

int main()
{
    using namespace std;

    Ship s("Welcome, captain, to your starship. My name is " Ship.name". Let's space today!");
    char option;

    do {
		if(Ship.docked == true) {
			option = stationMenu();
			stationOption(s, option);
		}
		else {
			option = spaceMenu();
			spaceOption(s, option);
		}
    } while (option != 'y' && option != 'Y');

    return 0;
}

/**
 *  Display the main menu and read selection from user
 */
char stationMenu()
{
    using namespace std;

    char option;

    system("cls");

    cout << "A) Buy supplies\n\n"
         << "B) Sell supplies\n\n"
         << "C) Load passengers\n\n"
         << "D) Unload passengers\n\n"
         << "E) Hire crew member\n\n"
         << "F) Travel to station\n\n"
		 << "G) View message\n\n"
		 << "H) View inventory\n\n"
         << "Q) Quit\n\n" << endl;

    cout << "Enter option: ";
    cin >> option;
    cin.ignore();
    cout << "\n\n" << endl;
    return option;
}

/**
 *  Select desired menu option
 */
void stationOption(Ship& s, char option)
{
    using namespace std;

    switch (toupper(option)) {
        case 'A': s.buySupplies();
                  break;
        case 'B': s.sellSupplies();
                  break;
        case 'C': s.loadPassengers();
                  break;
        case 'D': s.unloadPassengers();
                  break;
        case 'E': s.hireCrewMember();
                  break;
        case 'F': s.travelToStation();
				  break;
		case 'G': s.viewMessage();
                  break;
		case 'H': s.viewInventory();
                  break;
        case 'Q': do {
						cout << "Are you sure you want to quit?(Y/N)";
						cin >> option;
						cin.ignore();
						if(option=='y' || option=='Y') {
							"Quitting Application" << endl;
						}
						else
							break;
				  } while (option != 'y' && option != 'Y' && option != 'n' && option != 'N');
                  break;
        default:  cout << "Unknown option" << endl;
    }
    cout << "\n\n---Any character to continue";
    cin.get();
}

char spaceMenu()
{
    using namespace std;

    char option;

    system("cls");

    cout << "A) Dock\n\n"
         << "B) View Message\n\n"
         << "C) View inventory\n\n"
         << "Q) Quit\n\n" << endl;

    cout << "Enter option: ";
    cin >> option;
    cin.ignore();
    cout << "\n\n" << endl;
    return option;
}

/**
 *  Select desired menu option
 */
void spaceOption(Ship& s, char option)
{
    using namespace std;

    switch (toupper(option)) {
        case 'A': s.dock();
                  break;
        case 'B': s.viewMessage();
                  break;
        case 'C': s.viewInventory();
                  break;
        case 'Q': do {
						cout << "Are you sure you want to quit?(Y/N)";
						cin >> option;
						cin.ignore();
						if(option=='y' || option=='Y') {
							"Quitting Application" << endl;
						}
						else
							break;
				  } while (option != 'y' && option != 'Y' && option != 'n' && option != 'N');
                  break;
        default:  cout << "Unknown option" << endl;
    }
    cout << "\n\n---Any character to continue";
    cin.get();
}
