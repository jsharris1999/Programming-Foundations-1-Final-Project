#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <fstream>
#include "Monster.h"
#include "Room.h"
#include "Dungeon.h"
using namespace std;

int main()
{
	// Initialize random number generator
	srand(time(NULL));

	// Open map.txt file
	ifstream fin;
	fin.open("map.txt");
	int size, start, end;
	fin >> size;
	fin >> start;
	fin >> end;

	// Initialize dungeon from map.txt
	Dungeon dungeon;
	for (int index = 0; index < size; index++)
	{
		// Read map.txt file
		string monster_name, room_name;
		int strength, health, defense, speed, north, south, east, west;
		fin >> room_name >> north >> south >> east >> west
			>> monster_name >> strength >> health >> defense >> speed;

		// Add monster and room to dungeon
		Monster monster(monster_name, strength, health, defense, speed);
		Room room(room_name, monster, north, south, east, west);
		dungeon.addRoom(room);
	}

	// Close map.txt file
	dungeon.cleanup();
	fin.close();

	// Start player in dungeon
	Monster player("The Player", 30, 100, 30, 10);
	dungeon.play(start, end, player);
	return 0;
}