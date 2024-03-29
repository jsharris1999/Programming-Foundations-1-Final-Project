#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <ctime>
#include "Monster.h"
using namespace std;

Monster::Monster()
{
	Name = "None";
	Health = 0;
	Strength = 0;
	Defense = 0;
	Speed = 0;
}

Monster::Monster(string name, int health, int strength, int defense, int speed)
{
	Name = name;
	if (health < 0)
		Health = 1;
	else if (health < MAX_HEALTH)
		Health = health;
	else
		Health = MAX_HEALTH;
	if (strength < 0)
		Strength = 1;
	else if (strength < MAX_STRENGTH)
		Strength = strength;
	else
		Strength = MAX_STRENGTH;
	if (defense < 0)
		Defense = 1;
	else if (defense < MAX_DEFENSE)
		Defense = defense;
	else
		Defense = MAX_DEFENSE;
	if (speed < 0)
		Speed = 1;
	else if (speed < MAX_SPEED)
		Speed = speed;
	else
		Speed = MAX_SPEED;
}

Monster::Monster(const Monster& orig)
{
	Name = orig.Name;
	Health = orig.Health;
	Strength = orig.Strength;
	Defense = orig.Defense;
	Speed = orig.Speed;
}

Monster::~Monster()
{
}

string Monster::getName() const
{
	return Name;
}

int Monster::getHealth() const
{
	return Health;
}

int Monster::getStrength() const
{
	return Strength;
}

int Monster::getDefense() const
{
	return Defense;
}

int Monster::getSpeed() const
{
	return Speed;
}

void Monster::setName(string name)
{
	Name = name;
}

void Monster::setHealth(int health)
{
	if (health < 0)
		Health = 0;
	else if (health < MAX_HEALTH)
		Health = health;
	else
		Health = MAX_HEALTH;
}

void Monster::setStrength(int strength)
{
	if (strength < 0)
		Strength = 1;
	else if (strength < MAX_STRENGTH)
		Strength = strength;
	else
		Strength = MAX_STRENGTH;
}

void Monster::setDefense(int defense)
{
	if (defense < 0)
		Defense = 1;
	else if (defense < MAX_DEFENSE)
		Defense = defense;
	else
		Defense = MAX_DEFENSE;
}

void Monster::setSpeed(int speed)
{
	if (speed < 0)
		Speed = 1;
	else if (speed < MAX_SPEED)
		Speed = speed;
	else
		Speed = MAX_SPEED;
}

void Monster::Attack(Monster mon)
{
	int AttackSpeed = (rand() % mon.Speed) + 1;
	int DodgeSpeed = (rand() % Speed) + 1;
	int AttackPower = (rand() % mon.Strength) + 1;
	int Percentage = AttackPower - (AttackPower * (Defense/100.0));
	cout << mon.getName() << " is attacking " << Name << " with an attack power of " << AttackPower <<  "!" << endl;
	if (DodgeSpeed > AttackSpeed)
		cout << Name << " has dodged " << mon.getName() << "'s attack!" << endl;
	else
	{
		setHealth(Health - Percentage);
		if (Defense == 100)
			cout << Name << " has blocked " << mon.getName() << "'s attack!" << endl;
		else if (Health > 0)
			cout << Name << " has taken " << Percentage << " damage, leaving it with " << Health << " health!" << endl;
		else
			cout << Name << " has taken " << Percentage << " damage and has died!" << endl;
	}
}

void Monster::Print() const
{
	cout << "Monster: " << Name << endl;
	cout << "Health: " << Health << endl;
	cout << "Strength: " << Strength << endl;
	cout << "Defense: " << Defense << endl;
	cout << "Speed: " << Speed << endl;
}
