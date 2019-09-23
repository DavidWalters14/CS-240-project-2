#ifndef PARSER_DW
#define PARSER_DW
#include "Planet.h"
#include <vector>


class Parser{
	private:
		std::vector<Planet> planets; 
	public:
		Parser(std::string filename);
		std::vector<Planet> getPlanets();
};

#endif
