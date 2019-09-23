#ifndef PLANET_DW
#define PLANET_DW
#include <string>

class Planet{
private:
	std::string id;
	double probability;
public:
	Planet(std::string ID, double prob);
	std::string getName();
	double getProbability();
	double refine(double r);
	bool operator>(Planet & p2);
	bool operator<(Planet & p2);
	bool operator>=(Planet & p2);
	bool operator<=(Planet & p2);
	bool operator==(Planet & p2);
	bool operator!=(Planet & p2);	
};


#endif
