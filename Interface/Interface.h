//
//  Interface.h
//  IAWSCA
//
//  Created by Neil Peterson on 4/30/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef __IAWSCA__Interface__
#define __IAWSCA__Interface__

#include <iostream>
#include <vector>
#include <map>
#include <utility>

using namespace std;

class Interface{
	//All prototypes should be generic enough that we can overload them with a child class if we have time to implement ncurses
	//I'm playing with Doxygen here. You can get details here: http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
	//and here http://www.stack.nl/~dimitri/doxygen/manual/commands.html
	//I'm going to try and document as I go. Feel free to delete this comment once you see it. -N
public:
	Interface(){
	hr = "=========================";
	}
	
	/** \brief Creates and stores a menu for later use
	 *  \param name A unique name given to the menu. If empty menu will be deleted after it is used.
	 *  \param title The title that will appear at the top of the menu, this is the key value for accessing the menu in the future
	 *  \param menu These strings will be the menu, in the order they are in the container
	 *  \return Returns false if the menu is not created because the name was already taken
	 */
	bool newMenu(string name,string title,vector<string> menu){
		//TODO: remove name, newMenu() returns its own key value which the client must store. Easier then dealing with key collisions i think.
		menu.insert(menu.begin(),title);
		if (menus.find(name) == menus.end()){
			menus.insert(make_pair(name,menu));
			return true;
		}
		//else
		return false;
		
	}
	
	/** \brief Creates a one-time-use menu
	 */
	void showMenu(string title,vector<string> menu,bool withNumbers = true){
		// "temp" wont be nessesary in future. see todo in bool newMenu()
		newMenu("temp",title,menu);
		showMenu("temp",withNumbers);
		//deleteMenu("temp"); //TODO: implement this
	}
	
	/** \brief Displays the menu maped to the value of name 
	 *	\param name is the key value the menu is stored under
	 *	\param withNumbers Set to false if you do not want each line enumerated. Default is true.
	 */
	void showMenu(string name, bool withNumbers = true){
		//display all the lines in menu[name]
		int i = 0;
		for(string line:menus[name]){
			if((i > 0) && withNumbers) cout << i << ") ";
			cout << line << endl;
			if(i==0) cout << string((int)line.size(),'=') << "\n";
			i++;
		}
	}

	/** \brief Returns the number of options in the menu
	 *  \param name The name the menu was given during newMenu()
	 */
	int getMenuSize(string name){
		return (int)menus[name].size();
	}
	
	int getInt(string prompt = "Please enter a number: " , string error = "Invalid Input"){
		int input;
		cout << endl << prompt;
		cin >> input;
		// more validation needed here
		return input;
	}
	
	int getInt(int upper,int lower = 0,string prompt = "Please enter a number: " , string error = "Invalid Input"){
		int input;
		bool badInput = true;
		while (badInput) {
			input = getInt(prompt, error);
			cin.ignore();
			if (input < upper || input > lower) cout << error;
			else badInput = false;
		}
		return input;
	}
	
private:
	map<string, vector<string> > menus;
	string hr;
};
#endif /* defined(__IAWSCA__Interface__) */
