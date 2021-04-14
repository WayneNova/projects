#pragma once
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include "Monster.h"
#include "item.h"
using namespace std;

class Room
{
	string name;
	Room* east;
	Room* west;
	Room* north;
	Room* south;
	Monster* roomMonster;
	item* roomItem;
	bool exit;
public:
	void setName(string);
	string getName() const;
	void setEastRoom(Room*);
	void setWestRoom(Room*);
	void setNorthRoom(Room*);
	void setSouthRoom(Room*);
	Room* getEastRoom() const;
	Room* getWestRoom() const;
	Room* getNorthRoom() const;
	Room* getSouthRoom() const;
	void setRoomMonster(Monster*);
	Monster* getRoomMonster() const;
	void setRoomItem(item*);
	item* getRoomItem() const;
	bool isExit();
	Room(string, Room*, Room*, Room*, Room*, Monster*, item*);
	Room(string, Room*, Room*, Room*, Room*, Monster*);
	Room(string, Room*, Room*, Room*, Room*, item*);
	Room(string, Room*, Room*, Room*, Room*, bool);
	Room();
};

