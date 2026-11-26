#include "Knight.h"
#include <cstdlib>

Knight::Knight(std::string name, int health, int damage)
	: Enemy(name, health, damage) { }

int Knight::attack()
{
	// Knights occasionally strike with double damage. Game doesn't need to change
	return std::rand() % 4 == 0 ? getDamage() * 2 : getDamage();
}