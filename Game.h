#pragma once
#include "Room.h"
#include "hero.h"
#include "Monster.h"
#include "item.h"
#include "character.h"
class Game
{
public:
	Game();
	void run();
private:
	void createMap();
	Room* currentRoom;
	hero bob;
};

