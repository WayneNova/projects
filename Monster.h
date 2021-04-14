#pragma once
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include "character.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

class Monster : public character
{
public:
	void decreaseAttackPower();
	Monster(int, int);
};

