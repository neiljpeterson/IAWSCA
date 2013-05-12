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
#include <thread>
#include <iomanip>

using namespace std;

class Interface{
	//All prototypes should be generic enough that we can overload them with a child class if we have time to implement ncurses
	//I'm playing with Doxygen here. You can get details here: http://www.stack.nl/~dimitri/doxygen/manual/docblocks.html
	//and here http://www.stack.nl/~dimitri/doxygen/manual/commands.html
	//I'm going to try and document as I go. Feel free to delete this comment once you see it. -N
	//there will be a good bit of hard coding in here. im not too worried about it.
public:
	
	Interface(){
	}
	
	/** \brief Creates and stores a menu for later use
	 *  \param name A unique name given to the menu. If empty menu will be deleted after it is used.
	 *  \param title The title that will appear at the top of the menu, this is the key value for accessing the menu in the future
	 *  \param menu These strings will be the menu, in the order they are in the container
	 *  \return Returns false if the menu is not created because the name was already taken
	 */
	int newMenu(string title,vector<string> menu, string prmpt = "",bool withCloseOption = true){
		if (withCloseOption) menu.push_back("Close this menu");
		
		if (!prmpt.empty()){
			menu.push_back("\n");
			menu.push_back(prmpt);
		}
		
		menu.insert(menu.begin(),title); //insert title to begin of menu
		menus.push_back(menu);
		return (int)menus.size()-1; //return the "key" for the new menu
		
	}

	/** \brief Creates a one-time-use menu with tabulated each fields deliminated by \t
	 *	\param headings provides column headers and column widths
	 *	\param lines are the menu optons to be printed
	 *	\param title is the string that will be used to title the menu, optional
	 *	\param prmt is the prompt presented to the user at the end of the menu, optional
	 *  \param withCloseOption appends an option to close this menu, if selected returns the menu choice like any other
	 *	\param withNumbers 
	 */
	int showMenu(string headings, vector<int> widths, vector<string> lines, string title = "", string prmpt = "",
		//TODO: detect field widths, detect delim chars then combine showMenu methods
				 
		bool withCloseOption = true, bool withNumbers = true){
		
		if (withCloseOption)
			lines.push_back("Close this menu\t");
		
		int totalWidth = 0;
		for(int t:widths)
			totalWidth+=t;
		
		
		int menuChoice = -1;
		int i = -1;
		
		cout << endl;
		while(i<=(int)lines.size()){
			string line;
 			if( i == -1){//this line is the title
				line = title;
			} else if( i == 0){//this line is the column headers
				cout << string(totalWidth,'=') << endl; //put a line of ===
				line = headings;
			} else if( i > 0){
				//every other line
				line = lines[i - 1];
				if(withNumbers) line.insert(0, to_string(i) + ") ");
			}
				
			vector<string> fields = splitString(line,'\t');
			int w = 0;
			for (string field:fields){
				cout << setw(widths[w++]) << left << field;
			}
			
			cout << endl;
			i++;
		}
		
		if(!prmpt.empty())
			menuChoice = prompt(prmpt,1,(int)lines.size());
			
		return menuChoice;
	}
	
	vector<string> splitString(string splitMe, char delim){
		vector<string> results;
		stringstream splits(splitMe);
		string field;
		while( getline(splits,field,delim) ){
			results.push_back(field);
		}
		return results;
	}
	
	/** \brief Creates a one-time-use menu with an optional prompt
	 *	\param prompt if provided will also provide the user a close menu option
	 */
	int showMenu(string title, vector<string> menu, string prmpt = "", bool withCloseOption = true, bool withNumbers = true){
		int temp = newMenu(title,menu,prmpt,withCloseOption);
		int menuChoice = showMenu(temp,withNumbers);
		deleteMenu(temp);
		return menuChoice;
	}
	
	/** \brief Displays the a menu maped to the value of index
	 *	\param index is the key value the menu is stored under
	 *	\param withNumbers Set to false if you do not want each line enumerated. Default is true.
	 */
	int showMenu(int index, bool withNumbers = true){
		//display all the lines in menu[name]
		int i = 0;
		int menuChoice;
		bool nextLineIsPrompt = false;
		cout << endl;
		for(string line:menus[index]){
			//if showing with numbers and the next line isnt a prompt then put a line number
			if( (i == 0 && withNumbers) &&
			   !nextLineIsPrompt &&
			   line.compare("\n") != 0){
				cout << line << "\n" << string((int)line.size(),'=') << "\n";//prints a line
				
				//if this line is a newline or the line after the new line
			} else if(line.compare("\n") == 0){
				cout << line << endl;
				nextLineIsPrompt = true;
			} else if (nextLineIsPrompt){
				menuChoice = prompt(line,1,i-2); //-2 for two extra prompt lines;
			}
			else if(withNumbers)
				cout << i << ") " << line << endl;
			else{
				cout << line << endl;
			}
			i++;
		}
		return menuChoice;
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
	int prompt(string prompt,int lower,int upper,bool acceptEmpty = false ){
		int input;
		bool badinput = true;
		while(badinput){
			cout << endl << prompt << endl << "> ";
			bool goodInt = getInt(cin,input);
			if(acceptEmpty && !goodInt){
				input = lower - 1;
				badinput = false;
			}else if( goodInt && lower <= input && input <= upper ){
				badinput = false;
			}
			else if (!acceptEmpty){
				cout << "Please only enter a number between " <<
				lower << " and " << upper << ". Please try again." <<
				endl;
			}
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
			
			if( (input.compare(yes) == 0) || (strcmp(&i,&y) == 0) ){
				//there is a bug here with strcmp. first letters are not reconized
				return true;
			} else if( (input.compare(no) == 0) || (strcmp(&i,&n) == 0) ){
				return false;
			} else {
				cout << "Enter " << yes << " or " << no << " only. " << endl <<
				"Please try again. " << endl;
			}
		}
		
		return false;
	}
	
	void message(string message,bool withConfirm = false){
		string line;
		cout << message << endl;
		if(withConfirm){
			cout << "Please press any key to continue";
			getline(cin,line);
		}
	}
	
	void wait(string message,double seconds){
		double interval = 0.25;
		cout << message << endl;
		while(0<(seconds-=interval)){
			cout << ".";
			sleep(interval);
		}
	}
	
	void sleep(double seconds){
		int ms = (int)1000*seconds;
		this_thread::sleep_for(chrono::milliseconds(ms));
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
};
#endif /* defined(__IAWSCA__Interface__) */
