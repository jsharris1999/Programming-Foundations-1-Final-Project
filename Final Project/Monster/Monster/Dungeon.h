//---------------------------------------------------
// Purpose: Header file for the Dungeon class.
// Author:  Blake Keeling
//---------------------------------------------------
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include "Monster.h"
#include "Room.h"
using namespace std;

#ifndef DUNGEON_H
#define DUNGEON_H

class Dungeon
{
public:
	// Constructors and destructor
	Dungeon();
	Dungeon(const Dungeon& orig);
	~Dungeon();

	// Mutators
	void addRoom(Room room);
	void cleanup();
	void play(int start_room, int boss_room, Monster& player);
	static string getAction();

private:
	static const int MAX_ROOMS = 20;
	Room rooms[MAX_ROOMS];
	int size;
};

#endif
