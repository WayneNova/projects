#pragma once
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
using namespace std; // So "std::cout" may be abbreviated to "cout"

class character {

protected:

	int hp;
	int attackPower;

public:

	int getHp() const;
	void setHp(int h);
	int getAttackPower() const;
	void setAttackPower(int a);
	character();


};