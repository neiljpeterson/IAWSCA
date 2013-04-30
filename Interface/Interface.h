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
public:
	Interface(){};
	
	void newMenu(string name,string title,vector<string> menu){
		menu.push_back(title);
		menus.insert(make_pair(name,menu));
	}
	
	void showMenu(string name,bool numbers = true){
		int i = 0;
		for(string line:menus[name])
			cout << i++ << line << endl;
		
	}
	
	int getMenuSize(string name){
		return menus[name].size();
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
};
#endif /* defined(__IAWSCA__Interface__) */
