#pragma once
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include "character.h"
#include "item.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

class hero : public character {

	//int getHp() const;
	//void setHp(int h);
	//int getAttackPower() const;
	//void setAttackPower(int a);
	//character();

private:

	int defensePower;
	int retreatCount;


public:
	
	item * bag[3];

	int getDefensePower() const;
	void decreaseDefensePower();
	void setDefensePower(int s);
	int getRetreatCount() const; 
	void decreaseRetreatCount();
	bool anyItems() const;
	bool isAlive() const;
	hero(int a, int b, int c, int d);


};