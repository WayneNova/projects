#include "Room.h"
#include "Monster.h"
#include "Item.h"
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

void Room::setName(string n)
{
	name = n;
}

string Room::getName() const
{
	return name;
}

void Room::setEastRoom(Room* r)
{
	east = r;
}

void Room::setWestRoom(Room* r)
{
	west = r;
}

void Room::setNorthRoom(Room* r)
{
	north = r;
}

void Room::setSouthRoom(Room* r)
{
	south = r;
}

Room* Room::getEastRoom() const
{
	return east;
}

Room* Room::getWestRoom() const
{
	return west;
}

Room* Room::getNorthRoom() const
{
	return north;
}

Room* Room::getSouthRoom() const
{
	return south;
}

void Room::setRoomMonster(Monster* m)
{
	roomMonster = m;
}

Monster* Room::getRoomMonster() const
{
	return roomMonster;
}

void Room::setRoomItem(item* i)
{
	roomItem = i;
}

item* Room::getRoomItem() const
{
	return roomItem;
}

bool Room::isExit()
{
	if (exit)
	{
		return true;
	}
	return false;
}

Room::Room(string na, Room* n, Room* s, Room* e, Room* w, Monster* m, item* i)
{
	name = na;
	north = n;
	south = s;
	east = e;
	west = w;
	setRoomMonster(m);
	setRoomItem(i);
}

Room::Room(string na, Room* n, Room* s, Room* e, Room* w, Monster* m)
{
	name = na;
	north = n;
	south = s;
	east = e;
	west = w;
	setRoomMonster(m);
}

Room::Room(string na, Room* n, Room* s, Room* e, Room* w, item* i)
{
	name = na;
	north = n;
	south = s;
	east = e;
	west = w;
	setRoomItem(i);
}

Room::Room(string na, Room* n, Room* s, Room* e, Room* w, bool ex)
{
	name = na;
	north = n;
	south = s;
	east = e;
	west = w;
	exit = ex;
}

Room::Room()
{
	name = "";
	north = NULL;
	south = NULL;
	east = NULL;
	west = NULL;
	exit = 0;
}