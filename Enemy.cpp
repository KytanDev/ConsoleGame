#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int damage)
	: name(name), health(health), damage(damage) { }

std::string Enemy::getName() const { return name; }
int Enemy::getHealth() const { return health; }
int Enemy::getDamage() const { return damage; }
bool Enemy::isAlive() const { return health > 0; }

void Enemy::takeDamage(int amount)
{
	// Shared by every enemy, don't duplicate in subclasses
	if (amount > 0)
	{
		health = amount >= health ? 0 : health - amount;
	}
}