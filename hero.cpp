#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include "hero.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

int hero::getDefensePower() const
{
	return defensePower;
}

void hero::decreaseDefensePower()
{

}

void hero::setDefensePower(int s) {

	defensePower = s;

}

int hero::getRetreatCount() const
{
	return retreatCount;
}

void hero::decreaseRetreatCount()
{
	retreatCount--;
}

bool hero::anyItems() const
{
	return false;
}

bool hero::isAlive() const
{
	return false;
}

 hero::hero(int a, int b , int c, int d) {

	 defensePower = a;
	 retreatCount = b;
	 hp = c;
	 attackPower = d;

	 bag[3] = { NULL };

}

int hero::operator*(Monster& m)
{
	return 0;
}
