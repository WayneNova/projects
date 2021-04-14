#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include "character.h"
#include "item.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

bool item::isHP() const
{
	return type == 0;
}

bool item::isDefense() const
{
	return type == 1;
}

int item::getValue() const
{
	return value;
}

item::item(int x, int y)
{

	if (x == 0 || x == 1) {

		type = x;

	}

	else {

		type = 0;

	}
	value = y;
}

item::item()
{
	type = 0;
	value = 0;
}