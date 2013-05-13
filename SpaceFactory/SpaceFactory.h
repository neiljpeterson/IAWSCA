//
//  SpaceFactory.h
//  IAWSCA
//
//  Created by Neil Peterson on 5/12/13.
//  Copyright (c) 2013 Neil Peterson. All rights reserved.
//

#ifndef __IAWSCA__SpaceFactory__
#define __IAWSCA__SpaceFactory__

#include "../SpaceThing/SpaceThing.h"
#include "../IAWSCA/Station.h"

#include <iostream>
#include <fstream>
#include <string>

#include <ctime>
#include <cstdlib>
#include <stdio.h>

using namespace std;

class SpaceFactory{
public:
	const string FILES_DIRECTORY;
	const int PASSENGER_FARE_VARIANCE = 500;
	const int MAX_BACON = 5000;
	const int MAX_FUEL = 5000;
	const int UNIVERSE_RADIUS_FAR = 500;
	const int UNIVERSE_RADIUS_NEAR = 50;
	const int NEAR_FAR_RATIO = 3;
	int RND_COUNTER;
	
	vector<Station> stations;
	
	vector<string> locationNames;
	
	SpaceFactory(string DIR){
		string line;
		ifstream file;
		RND_COUNTER = 0;
		
		//------------------------------------Load cargo
		vector<CargoType> cargoTypes;
		int typeID = 3000;
		file.open(DIR + "CargoTypes");
		if (file.is_open()){
			while ( file.good() ){
				
				getline (file,line);
				stringstream splits(line);
				vector<string> cargoStrings = splitString(line,'\t');
				
				string typeName = cargoStrings[0];
				int weight = atoi(cargoStrings[1].c_str());
				int price = atoi(cargoStrings[2].c_str());
				
				int count = 5;
				while(count--){
					cargoTypes.push_back(*new CargoType(
					typeID++,typeName,weight,10 + price + (RND(price) * (RND(2)?-1:1))));
				}
			}
			file.close();
		} else cout << "Unable to open 'CargoTypes' file";
		
		//------------------------------------Load Coordinates
		vector<Coordinate> locations;
		file.open(DIR + "LocationNames");
		if (file.is_open()){
			while ( file.good() ){
				getline (file,line);
				
				locations.push_back(
				*new Coordinate(
				(RND (RND(NEAR_FAR_RATIO)?UNIVERSE_RADIUS_NEAR:UNIVERSE_RADIUS_FAR) * (RND(2)?-1:1) ),
				(RND (RND(NEAR_FAR_RATIO)?UNIVERSE_RADIUS_NEAR:UNIVERSE_RADIUS_FAR) * (RND(2)?-1:1) ),
				(RND (RND(NEAR_FAR_RATIO)?UNIVERSE_RADIUS_NEAR:UNIVERSE_RADIUS_FAR) * (RND(2)?-1:1) ),
				line));
			}
			file.close();
		} else cout << "Unable to open 'LocationNames' file";
		
		//------------------------------------Load Passengers
		vector<Passenger> passengers;
		file.open(DIR + "PassengerNames");
		if (file.is_open()){
			string name;
			while ( file.good() ){
				getline (file,name);
				passengers.push_back(*new Passenger(name,0,100,locations[RND((int)locations.size()-1)]));
			}
			file.close();
		} else cout << "Unable to open 'LocationNames' file";
		
		
		//----------------------------------------Build stations
		file.open(DIR + "StationNames");
		if (file.is_open()){
			string name;
			int pngr_index = 0;
			while ( file.good() ){
				getline (file,name);
				
				vector<CargoBin> cargo;
				int numberOfCargos = 5;
				
				while(numberOfCargos--)
					cargo.push_back( CargoBin( cargoTypes[RND((int)cargoTypes.size()-1)] ,RND(100) ));
				
				vector<Passenger> stationPassengers;
				int numberOfPassengers = 5;
				while(numberOfPassengers--)
					stationPassengers.push_back(passengers[pngr_index++]);
				
				stations.push_back( *new SpaceThing(
				name,RND(MAX_BACON),0,cargo,
				locations[RND((int)locations.size()-1)],
				stationPassengers));
			}
			file.close();
		} else cout << "Unable to open 'StationNames' file";
	};
	
	Station randomStation(){
		return stations[RND((int)stations.size()-1)];
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

	
	int RND(int max,int min = 0){
		srand((unsigned)time(NULL) * RND_COUNTER++ );
		return (min + (rand() % max));
	}
	
};
#endif /* defined(__IAWSCA__SpaceFactory__) */
