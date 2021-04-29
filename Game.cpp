#include "Game.h"
#include <windows.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

Game::Game()
{
	createMap();
	hero b(3, 3, 30, 7);
	bob = b;
}

void Game::run()
{
	//previous room
	Room* previousRoom = NULL;
	Room* portal = currentRoom;
	int portalCount = 0;
	bool port = false;
	bool retreat = false;

	while ((bob.isAlive() == 1) && (currentRoom->isExit() == 0))
	{
		//Game intro
		if (retreat == false)
		{
			if (currentRoom->getName() == "Start")
			{
				if (portalCount == 0)
				{
					cout << " ... ";
					Sleep(1000);
					cout << " ... ";
					Sleep(1000);
					cout << " ... " << endl;
					Sleep(1000);
					cout << "You wake with a start." << endl;
					cout << "You find yourself drenched in sweat and laying on a torn up blanket on a hard and cold floor." << endl;
					cout << "There is a single lit torch on the wall that you can use as a light source." << endl << endl;
					Sleep(3000);
				}
				else
				{
					cout << endl << "You emerge back in the room with the torn blanket on the ground." << endl << endl;
					port = false;
				}
			}
			else
			{
				port = false;
			}
		}
		else
		{
			retreat = false;
		}
		if ((currentRoom->getName() == "Dungeon") && (portalCount == 0))
		{
			cout << endl << "As you're making your way to the next room, you hear a rumbling..." << endl;
			Sleep(1000);
			cout << "The rumbling gets louder as you get farther into the room..." << endl;
			Sleep(1000);
			cout << "The torch from your light finally reveals the source of the noise..." << endl << endl;
		}
		//display room information
		cout << "== Room's Information ==" << endl;
		cout << "Name: " << currentRoom->getName() << endl;
		if (currentRoom->getRoomMonster() == NULL)
		{
			cout << "Monster: none" << endl;
		}
		else
		{
			if (currentRoom->getName() == "Dungeon")
			{
				cout << "Boss: HP/" << currentRoom->getRoomMonster()->getHp() << " AP/" << currentRoom->getRoomMonster()->getAttackPower() << endl;
			}
			else
			{
				cout << "Monster: HP/" << currentRoom->getRoomMonster()->getHp() << " AP/" << currentRoom->getRoomMonster()->getAttackPower() << endl;
			}
		}
		if (currentRoom->getRoomItem() == NULL)
		{
			cout << "Item: none" << endl;
		}
		else if (currentRoom->getRoomItem()->isDefense())
		{
			cout << "Item: DP/" << currentRoom->getRoomItem()->getValue() << endl;
		}
		else
		{
			cout << "Item: HP/" << currentRoom->getRoomItem()->getValue() << endl;
		}
		cout << "Bob: " << "HP/" << bob.getHp() << " : AP/" << bob.getAttackPower() << " : DP/" << bob.getDefensePower() << " : RC/" << bob.getRetreatCount() << endl << endl;
		//retreat section
		if ((bob.getRetreatCount() > 0) && (!previousRoom == NULL) && (currentRoom->getName() != "Start"))
		{
			char y;
			cout << "******RETREAT SECTION******" << endl;
			cout << "Do you wish to retreat? (y/n): ";
			cin >> y;
			if (y == 'y')
			{
				Room* temp = currentRoom;
				currentRoom = previousRoom;
				previousRoom = temp;
				bob.decreaseRetreatCount();
				retreat = true;
				cout << endl;
			}
		}
		if (retreat == false)
		{
			//item section
			if (bob.anyItems() == true)
			{
				char y;
				int item;
				int slot[3] = { 0, 0, 0 };
				cout << "******ITEM SECTION******" << endl;
				cout << "Would you like to use an item?(y/n)? ";
				cin >> y;
				if (y == 'y')
				{
					for (int i = 0; i < 3; i++)
					{
						if (bob.bag[i] == NULL)
						{
							cout << i << ") None" << endl;
						}
						else if (bob.bag[i] == 0)
						{
							cout << i << ") HP/" << bob.bag[i]->getValue() << endl;
							slot[i] = 1;
						}
						else
						{
							cout << i << ") DP/" << bob.bag[i]->getValue() << endl;
							slot[i] = 1;
						}
					}
					cout << "Which item do you want to use? (0-2):  ";
					cin >> item;
					while (slot[item] == 0)
					{
						cout << "No item is found in that slot. Select a different slot: ";
						cin >> item;
					}
					if (bob.bag[item] == 0)
					{
						int tempHP = bob.getHp();
						bob.setHp(bob.getHp() + bob.bag[item]->getValue());
						cout << "Your health increased by " << bob.getHp() - tempHP << endl;
						bob.bag[item] = NULL;
					}
					else
					{
						int tempDP = bob.getDefensePower();
						bob.setDefensePower(bob.getDefensePower() + bob.bag[item]->getValue());
						cout << "Your defense increased by " << bob.getDefensePower() - tempDP << endl;
						bob.bag[item] = NULL;
					}
				}
			}
			//battle section
			if (currentRoom->getRoomMonster() != NULL)
			{
				Monster m(currentRoom->getRoomMonster()->getHp(), currentRoom->getRoomMonster()->getAttackPower());
				int fight;
				cout << "*****BATTLE SECTION******" << endl;
				//boss
				if (currentRoom->getName() == "Dungeon")
				{
					if (portalCount > 0)
					{
					}
					else
					{
						cout << "Bob: " << "HP/" << bob.getHp() << " : AP/" << bob.getAttackPower() << " : DP/" << bob.getDefensePower() << " : RC/" << bob.getRetreatCount() << endl << endl;
						cout << "Boss: HP/" << m.getHp() << " AP/" << m.getAttackPower() << endl << endl;
						while ((bob * m) == 0)
						{
							Sleep(500);
							cout << "Bob: " << "HP/" << bob.getHp() << " : AP/" << bob.getAttackPower() << " : DP/" << bob.getDefensePower() << " : RC/" << bob.getRetreatCount() << endl << endl;
							cout << "Boss: HP/" << m.getHp() << " AP/" << m.getAttackPower() << endl << endl;
						}
						if (bob.getHp() > 0)
						{
							cout << "Bob: " << "HP/" << bob.getHp() << " : AP/" << bob.getAttackPower() << " : DP/" << bob.getDefensePower() << " : RC/" << bob.getRetreatCount() << endl << endl;
							cout << "Boss: HP/" << m.getHp() << " AP/" << m.getAttackPower() << endl << endl;
							cout << "You beat the boss!" << endl;
							cout << "There's a mysterious portal on the ground... you decide to step into it...";
							Sleep(2000);
							cout << " ... ";
							Sleep(2000);
							cout << " ... " << endl;
							Sleep(2000);
							currentRoom->setRoomMonster(NULL);
							currentRoom = portal;
							previousRoom = NULL;
							portalCount++;
							port = true;
						}
						else
						{
							bob.setHp(0);
						}
					}
				}
				//regular monster
				else
				{
					cout << "Bob: " << "HP/" << bob.getHp() << " : AP/" << bob.getAttackPower() << " : DP/" << bob.getDefensePower() << " : RC/" << bob.getRetreatCount() << endl << endl;
					cout << "Monster: HP/" << currentRoom->getRoomMonster()->getHp() << " AP/" << currentRoom->getRoomMonster()->getAttackPower() << endl << endl;
					while ((bob * m )== 0)
					{
						Sleep(500);
						cout << "Bob: " << "HP/" << bob.getHp() << " : AP/" << bob.getAttackPower() << " : DP/" << bob.getDefensePower() << " : RC/" << bob.getRetreatCount() << endl << endl;
						cout << "Monster: HP/" << currentRoom->getRoomMonster()->getHp() << " AP/" << currentRoom->getRoomMonster()->getAttackPower() << endl << endl;
					}
					if (bob.getHp() > 0)
					{
						cout << "Bob: " << "HP/" << bob.getHp() << " : AP/" << bob.getAttackPower() << " : DP/" << bob.getDefensePower() << " : RC/" << bob.getRetreatCount() << endl << endl;
						cout << "Boss: HP/" << m.getHp() << " AP/" << m.getAttackPower() << endl << endl;
						cout << "You beat the monster!" << endl;
						currentRoom->setRoomMonster(NULL);
					}
					else
					{
						bob.setHp(0);
					}
				}
			}
			if (port == false)
			{
				if ((currentRoom->getName() == "Dungeon") && (portalCount > 0))
				{
					cout << "The Boss's corpse lies motionless on the ground." << endl;
					cout << "You step back through the mysterious portal." << endl;
					currentRoom = portal;
					previousRoom = NULL;
					port = true;
					portalCount++;
				}
				//check if hero is alive
				else if (bob.getHp() != 0)
				{
					cout << "******POST-BATTLE SECTION******" << endl;
					//get new item
					if (currentRoom->getRoomItem() != NULL)
					{
						char y;
						int i = 0;
						item* found;
						cout << "---A new item has been found!" << endl;
						if (currentRoom->getRoomItem()->isDefense())
						{
							found = new item(1, currentRoom->getRoomItem()->getValue());
							cout << "---Item: DP/" << found->getValue() << endl;
						}
						else
						{
							found = new item(0, currentRoom->getRoomItem()->getValue());
							cout << "---Item: HP/" << found->getValue() << endl;
						}
						cout << "---Would you like to pick up the item? (y/n): ";
						cin >> y;
						if (y == 'y')
						{
							while (bob.bag[i] != NULL)
							{
								i++;
							}
							bob.bag[i] = found;
							currentRoom->setRoomItem(NULL);
						}

					}
					//directions
					int nor = 10;
					int sou = 10;
					int eas = 10;
					int wes = 10;
					cout << "---Directions" << endl;
					previousRoom = currentRoom;
					int option;
					bool valid = 0;
					if (currentRoom->getNorthRoom() != NULL)
					{
						cout << "---(0) North: " << currentRoom->getNorthRoom()->getName() << endl;
						nor = 0;
					}
					if (currentRoom->getSouthRoom() != NULL)
					{
						cout << "---(1) South: " << currentRoom->getSouthRoom()->getName() << endl;
						sou = 1;
					}
					if (currentRoom->getEastRoom() != NULL)
					{
						cout << "---(2) East: " << currentRoom->getEastRoom()->getName() << endl;
						eas = 2;
					}
					if (currentRoom->getWestRoom() != NULL)
					{
						cout << "---(3) West: " << currentRoom->getWestRoom()->getName() << endl;
						wes = 3;
					}
					cout << "---Which direction do you want to head? (0-3): ";
					cin >> option;
					if (option != nor)
					{
						if (option != sou)
						{
							if (option != eas)
							{
								if (option != wes)
								{

								}
								else
								{
									valid = 1;
								}
							}
							else
							{
								valid = 1;
							}
						}
						else
						{
							valid = 1;
						}
					}
					else
					{
						valid = 1;
					}
					while (valid == 0)
					{
						cout << "---Invalid direction. Choose a different direction: ";
						cin >> option;
						if (option != nor)
						{
							if (option != sou)
							{
								if (option != eas)
								{
									if (option != wes)
									{

									}
									else
									{
										valid = 1;
									}
								}
								else
								{
									valid = 1;
								}
							}
							else
							{
								valid = 1;
							}
						}
						else
						{
							valid = 1;
						}
					}
					switch (option)
					{
					case 0:
						previousRoom = currentRoom;
						currentRoom = currentRoom->getNorthRoom();
						break;
					case 1:
						previousRoom = currentRoom;
						currentRoom = currentRoom->getSouthRoom();
						break;
					case 2:
						previousRoom = currentRoom;
						currentRoom = currentRoom->getEastRoom();
						break;
					case 3:
						previousRoom = currentRoom;
						currentRoom = currentRoom->getWestRoom();
						break;
					default:
						break;
					}
					cout << endl;
				}
			}
			else
			{
				port = false;
			}
		}
	}
	if (currentRoom->isExit() == 1)
	{
		cout << "You see light up ahead!" << endl
			<< "You run as fast as you can until you reach the exit of the cave." << endl
			<< "You win!" << endl;
	}
	if (bob.isAlive() == 0)
	{
		cout << "You lose the last bit of your strength and fall to the ground..." << endl;
		Sleep(1000);
		cout << " ... ";
		Sleep(1000);
		cout << " ... " << endl;
		Sleep(1000);
		cout << "You feel yourself losing consciousness as the monster approaches you..." << endl;
		Sleep(1000);
		cout << " ... ";
		Sleep(1000);
		cout << " ... " << endl;
		Sleep(1000);
		cout << "It raises both it's fists..." << endl;
		Sleep(1000);
		cout << " ... ";
		Sleep(1000);
		cout << " ... " << endl;
		Sleep(1000);
		cout << "Your vision fades to black as you watch the monster's fists head straight for your face..." << endl << endl;
		Sleep(1000);
		cout << "...Game Over..." << endl << endl;
	}
}

void Game::createMap()
{
	//monster objects
	Monster* m1 = new Monster(5, 2);
	Monster* m2 = new Monster(12, 6);
	Monster* m3 = new Monster(24, 10);

	//define items
	item* i1 = new item(0, 5);
	item* i2 = new item(1, 5);
	item* i3 = new item(0, 5);

	//create rooms
	Room* room0 = new Room("Start", nullptr, nullptr, nullptr, nullptr, false);
	Room* room1 = new Room("Floor 1 - Room 1", nullptr, nullptr, nullptr, nullptr, false);
	Room* room2 = new Room("Floor 1 - Room 2", nullptr, nullptr, nullptr, nullptr, i1);
	Room* room3 = new Room("Floor 1 - Room 3", nullptr, nullptr, nullptr, nullptr, i2);
	Room* room4 = new Room("Floor 1 - Room 4", nullptr, nullptr, nullptr, nullptr, m1);
	Room* room5 = new Room("Floor 1 - Room 5", nullptr, nullptr, nullptr, nullptr, false);
	Room* room6 = new Room("Exit", nullptr, nullptr, nullptr, nullptr, true);
	Room* room7 = new Room("Floor 2 - Room 1", nullptr, nullptr, nullptr, nullptr, m2);
	Room* room8 = new Room("Floor 2 - Room 2", nullptr, nullptr, nullptr, nullptr, i3);
	Room* room9 = new Room("Floor 2 - Room 3", nullptr, nullptr, nullptr, nullptr, false);
	Room* room10 = new Room("Dungeon", nullptr, nullptr, nullptr, nullptr, m3);
	
	//room pathing
	///starting room
	currentRoom = room0;
	room0->setNorthRoom(room1);
	room0->setSouthRoom(room7);
	///first branches
	room7->setSouthRoom(room8);
	room1->setNorthRoom(room3);
	room1->setEastRoom(room2);
	///second branches
	room8->setWestRoom(room9);
	room3->setEastRoom(room4);
	room2->setNorthRoom(room4);
	///third branches
	room9->setSouthRoom(room10); //boss room
	room4->setEastRoom(room5);
	///fourth branches
	room5->setEastRoom(room6); //exit room
}

