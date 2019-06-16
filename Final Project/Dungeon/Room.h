#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "Monster.h"
using namespace std;

#ifndef ROOM_H
#define ROOM_H

class Room
{
public:
	Room();
	Room(string name, Monster monster, int north, int south, int east, int west);
	Room(const Room & room);
	~Room();
	void Look();
	int Move(int RoomNumber);
	bool Alive();
	void Fight(Monster mon);
	void Clean(int rooms);

private:
	string Name;
	Monster monster;
	int North;
	int South;
	int East;
	int West;
};

#endif