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
	if (defensePower > 1)
	{
		defensePower--;
	}
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
	int count = 0;
	for (int i = 0; i < 3; i++)
	{
		if (bag[i] == NULL)
			count++;
		
	};
	if (count ==3)
	{
		return false;
	}
	return true;
}

bool hero::isAlive() const
{
	if (hp > 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

 hero::hero(int a, int b , int c, int d) {

	 defensePower = a;
	 retreatCount = b;
	 setHp(c);
	 setAttackPower(d);
	 for (int i = 0; i < 3; i++)
	 {
		 bag[i] = NULL;
	 }
}

 hero::hero():character()
 {
	 defensePower = 0;
	 retreatCount = 0;
	 for (int i = 0; i < 3; i++)
	 {
		 bag[i] = NULL;
	 }
 }

int hero::operator * (Monster& m)
{
	m.setHp(m.getHp() - getAttackPower() < 0 ? 0 : m.getHp() - getAttackPower());
	setHp(getHp() - (m.getAttackPower() / getDefensePower()));
	m.decreaseAttackPower();
	decreaseDefensePower();
	if (getHp() == 0) // hero died
		return -1;
	else if (m.getHp() == 0)  // monster died
		return 1;
	else   // no character died
		return 0;
}
