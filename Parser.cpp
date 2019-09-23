#include "Parser.h"
#include "Planet.h"
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

Parser::Parser(std::string filename){
	ifstream inFile;
	inFile.open(filename);
	if(!inFile.is_open()){
		cout << "file could not be opened" << endl;
	}
	else{
		std::string id;
		double prob;
		while(!inFile.eof()){ //check EOF file and fail flag 
			inFile >> id;
			inFile >> prob;
			if(!inFile.fail()) {
				inFile.ignore(1000, '\n');
				Planet p = Planet(id,prob);
				planets.push_back(p);
			}
		}
	}
	inFile.close();
}
vector<Planet> Parser::getPlanets() { //returns a copy of the vector?
	return planets;
}




