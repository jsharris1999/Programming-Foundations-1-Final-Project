#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "Monster.h"
#include "Room.h"
using namespace std;

Room::Room()
{
	Name = "None";
	Monster monster();
	North = -1;
	South = -1;
	East = -1;
	West = -1;
}

Room::Room(string name, Monster mon, int north, int south, int east, int west)
{
	Name = name;
	monster = mon;
	North = north;
	South = south;
	East = east;
	West = west;
}

Room::Room(const Room & room)
{
	Name = room.Name;
	monster = room.monster;
	North = room.North;
	South = room.South;
	East = room.East;
	West = room.West;
}

Room::~Room()
{

}

void Room::Look()
{
	cout << "This room is the " << Name << "." << endl;
	if (Alive())
	{
		cout << "This room contains a/an " << monster.getName() << " that is alive." << endl;
	}
	else
	{
		cout << "This room contains a/an " << monster.getName() << " that is dead." << endl;
	}
	if (North > -1)
	{
		cout << "There is a room to the North of your current position." << endl;
	}
	if (South > -1)
	{
		cout << "There is a room to the South of your current position." << endl;
	}
	if (East > -1)
	{
		cout << "There is a room to the East of your current position." << endl;
	}
	if (West > -1)
	{
		cout << "There is a room to the West of your current position." << endl;
	}
}

int Room::Move(int RoomNumber)
{
	string Direction = "?";
	bool InvalidDirection = true;
	cout << "Enter in which direction you would like to go." << endl;
	while (InvalidDirection)
	{
		cin >> Direction;
		if (Direction == "North" || Direction == "north")
		{
			if (North > -1)
			{
				RoomNumber = North;
			}
			InvalidDirection = false;
		}
		else if (Direction == "South" || Direction == "south")
		{
			if (South > -1)
			{
				RoomNumber = South;
			}
			InvalidDirection = false;
		}
		else if (Direction == "East" || Direction == "east")
		{
			if (East > -1)
			{
				RoomNumber = East;
			}
			InvalidDirection = false;
		}
		else if (Direction == "West" || Direction == "west")
		{
			if (West > -1)
			{
				RoomNumber = West;
			}
			InvalidDirection = false;
		}
		else
		{
			cout << "That is not a valid direction." << endl;
		}
	}
	return RoomNumber;
}

bool Room::Alive()
{
	if (monster.getHealth() > 0)
		return true;
	else
		return false;
}

void Room::Fight(Monster Player)
{
	if (monster.getHealth() == 0)
	{
		cout << "Stop trying to fight dead things." << endl;
	}
	else
	{
		monster.Attack(Player);
		if (monster.getHealth() != 0)
		{
			Player.Attack(monster);
		}
	}
}

void Room::Clean(int rooms)
{
	if (North > rooms)
	{
		North = -1;
	}
	if (South > rooms)
	{
		South = -1;
	}
	if (East > rooms)
	{
		East = -1;
	}
	if (West > rooms)
	{
		West = -1;
	}
}