#include "Monster.h"
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include "character.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

void Monster::decreaseAttackPower()
{
	int attack = getAttackPower() - 1;
	setAttackPower(attack);
}

Monster::Monster(int hp, int attack)
{
	setHp(hp);
	setAttackPower(attack);
}
