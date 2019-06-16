#include "Dungeon.h"
#include <iostream>
using namespace std;

Dungeon::Dungeon()
{
	size = 0;
}

Dungeon::Dungeon(const Dungeon& orig)
{
	size = 0;
	for (int i = 0; i < orig.size; i++)
		addRoom(orig.rooms[i]);
}

Dungeon::~Dungeon()
{
}

void Dungeon::addRoom(Room room)
{
	if (size >= MAX_ROOMS)
		return;
	rooms[size] = room;
	size++;
}

void Dungeon::cleanup()
{
	for (int i = 0; i < size; i++)
		rooms[i].Clean(size);
}

string Dungeon::getAction()
{
	string response = "";
	while (response != "attack" && response != "move" &&
		response != "look" && response != "quit")
	{
		cout << "Choose an action: (\'attack\', \'move\', \'look\', \'quit\'):";
		cin >> response;
		for (int i = 0; i < (int)response.length(); i++)
			response[i] = tolower(response[i]);
	}
	cout << endl;
	return response;
}

void Dungeon::play(int start_room, int boss_room, Monster& player)
{
	int location = start_room;
	string command = "";
	command = getAction();
	while (command != "quit" && player.getHealth() > 0 &&
		rooms[boss_room].Alive())
	{
		if (command == "attack")
			rooms[location].Fight(player);
		if (command == "look")
			rooms[location].Look();
		if (command == "move")
			location = rooms[location].Move(location);
		if (player.getHealth() > 0 && rooms[boss_room].Alive())
			command = getAction();
	}

	if (!rooms[boss_room].Alive())
	{
		cout << "\n\tYou managed to slay the boss monster! congratulations you win!\n\n";
	}
	if (player.getHealth() <= 0)
	{
		cout << "\n\tUnfortunatly you fell in battle, your adventuring days are over.\n\n";
	}
	if (command == "quit")
	{
		cout << "\n\tYou manage to escape, hopefully another brave adventurer will defeat the boss.\n";
	}
}