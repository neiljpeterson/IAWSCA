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
#include <utility>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <functional>
#include <string>
#include <locale>

using namespace std;

class Interface{
	//All prototypes should be generic enough that we can overload them with a child class if we have time to implement ncurses
	//I'm playing with Doxygen here. You can get details here: http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
	//and here http://www.stack.nl/~dimitri/doxygen/manual/commands.html
	//I'm going to try and document as I go. Feel free to delete this comment once you see it. -N
	//there will be a good bit of hard coding in here. im not too worried about it.
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
	bool newMenu(string title,vector<string> menu){
		//TODO: remove name, newMenu() returns its own key value which the client must store. Easier then dealing with key collisions i think.
		menu.insert(menu.begin(),title); //insert title to begin of menu 
		menus.push_back(menu);
		return menus.size()-1; //return the "key" for the menu
		
	}
	
	/** \brief Creates a one-time-use menu
	 */
	void showMenu(string title,vector<string> menu,bool withNumbers = true){
		// "temp" wont be nessesary in future. see todo in bool newMenu()
		int temp = newMenu(title,menu);
		showMenu(temp,withNumbers);
		deleteMenu(temp);
	}
	
	/** \brief Displays the menu maped to the value of name
	 *	\param name is the key value the menu is stored under
	 *	\param withNumbers Set to false if you do not want each line enumerated. Default is true.
	 */
	void showMenu(int index, bool withNumbers = true){
		//display all the lines in menu[name]
		int i = 0;
		for(string line:menus[index]){
			if((i > 0) && withNumbers) cout << i << ") ";
			cout << line << endl;
			if(i==0) cout << string((int)line.size(),'=') << "\n";
			i++;
		}
	}
	
	bool deleteMenu(int index){
		return menus.erase(menus.begin() + index) != menus.end();
	}
	
	/** \brief Returns the number of options in the menu
	 *  \param name The name the menu was given during newMenu()
	 */
	int getMenuSize(int index){
		return (int)menus[index].size();
	}
	
	/** \brief Returns a string from standar input
	 *  \param prompt is the string presented to the user
	 */
	string prompt(string prompt){
		string input;
		cout << endl << prompt << endl << "> ";
		getline(cin,input);
		return input;
	}
	
	/** \brief Returns an int read frmo standard input that is INCLUSIVLY within the range specified
	 *  \param prompt is the string presented to the user
	 */
	int prompt(string prompt,int lower,int upper){
		int input;
		bool badinput = true;
		while(badinput){
			cout << endl << prompt << endl << "> ";
			if(getInt(cin,input) && lower <= input && input <= upper )
				badinput = false;
			else
				cout << "Please only enter a number between " <<
				lower << " and " << upper << ". Please try again." <<
				endl;
		}
		return input;
	}
	
	/** \brief Returns true or false based on two string choices. if the first letters of the strings differ prompt will also accept those as well.
	 *  \param prompt is the string presented to the user
	 *  \param yes is the string the user must choose for true
	 *  \param no is the string the user must choose for false
	 */
	bool prompt(string prompt, string yes, string no){
		string input;
		prompt = prompt + "(" + yes + "/" + no + ")";
		char y,n,i; //first letter values
		bool badinput = true;
		
		//lower them
		tolower(yes);
		tolower(no);
		
		//are the first letters differnt?
		if( yes[0] != no[0] ){
			y = yes[0];
			n = no[0];
		}//then we only care about the first chars
		
		while(badinput){
			input = Interface::prompt(prompt);
			tolower(input);
			i = input[0];
			
			if( (input.compare(yes) == 0) || (strcmp(&i,&y) == 0) ){ //there is a bug here with strcmp
				cout << "you told me " << input << endl;
				return true;
			} else if( (input.compare(no) == 0) || (strcmp(&i,&n) == 0) ){
				cout << "you told me " << input << endl;
				return false;
			} else {
				cout << "Enter " << yes << " or " << no << " only. " << endl <<
				"Please try again. " << endl;
			}
		}
		
		return false;
	}
	
	void message(string message){
		cout << message << endl;
	}
	
	static string toString(int i){
		stringstream result;
		result << i;
		return result.str();
	}
	
	/** \brief trys to read an int from standard input, returns true if successful
	 *
	 */
	bool getInt(istream&  cin, int& result){
		string input;
		getline(cin,input);
		stringstream stream(input);
		if(stream >> result)
			return true;
		else return false;
	}
	
	bool tolower(string &lower){
		try{
			std::transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
			return true;
		} catch(int e) { return false; };
		return false;
	}
	
	//old. delete after usages have been removed.
	int getInt(int upper,int lower = 0,string prompt = "Please enter a number: " , string error = "Invalid Input"){
		int input;
		bool badInput = true;
		while (badInput) {
			input = getInt(upper, lower, prompt, error); //uh oh. bad recursion here.
			cin.ignore();
			if (input < upper || input > lower) cout << error;
			else badInput = false;
		}
		return input;
	}
	
private:
	vector< vector<string> > menus;
	string hr;
};
#endif /* defined(__IAWSCA__Interface__) */
