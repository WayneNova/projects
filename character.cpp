#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include "character.h"
using namespace std; // So "std::cout" may be abbreviated to "cout"

int character::getHp() const {

	return hp;

}

void character::setHp(int h) {

	hp = h;

	if (hp < 0) {

		hp;

	}
}

int character::getAttackPower() const {

	return attackPower;

}

void character::setAttackPower(int a) {

	attackPower = a;

}

character::character() {

	hp = 10;
	attackPower = 1;

}