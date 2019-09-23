#include "Planet.h"
#include <iostream>
#include <cstdlib>
#include <string>


Planet::Planet(std::string ID, double prob){
	id=ID;
	probability=prob;
}

std::string Planet::getName(){
	return id;
}

double Planet::getProbability(){
	return probability;
}

double Planet::refine(double r){ 
	 probability+=r;
	 if(probability < 0) {
	   	probability = 0;
	 }	 
	 if(probability > 100) {
	 	probability = 100;
	 } 
	 return probability;
}

bool Planet::operator>(Planet  & p2){
	if(getProbability()>p2.getProbability()){
		return true;
	}
	return false;
}

bool Planet::operator<(Planet & p2){
	if(getProbability()<p2.getProbability()){
		return true;
	}
	return false;
}

bool Planet::operator>=(Planet & p2){
	if(getProbability()>=p2.getProbability()){
		return true;
	}
	return false;
}

bool Planet::operator<=(Planet & p2){
	if(getProbability()<=p2.getProbability()){
		return true;
	}
	return false;
}

bool Planet::operator==(Planet & p2){
	if(getProbability()==p2.getProbability()){
		return true;
	}
	return false;
}

bool Planet::operator!=(Planet  & p2){
	if(getProbability()!=p2.getProbability()){
		return true;
	}
	return false;
}
