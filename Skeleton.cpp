#include "Skeleton.h"

Skeleton::Skeleton(std::string name, int health, int damage)
	: Enemy(name, health, damage) { }

int Skeleton::attack()
{
	// Return damage rather than modifying the player directly
	return getDamage();
}