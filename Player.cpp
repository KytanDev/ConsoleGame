#include "Player.h"

int Player::getHealth() const { return health; }
int Player::getDamage() const { return damage; }
int Player::getPotions() const { return potions; }
int Player::getScore() const { return score; }
bool Player::isAlive() const { return health > 0; }

void Player::takeDamage(int amount)
{
	// Calculate damage. Player keeps valid health
	if (amount > 0) health = amount >= health ? 0 : health - amount;
}

bool Player::heal()
{
	// Failed healing doesn't use a potion or waste a turn
	if (!isAlive() || health == 100 || potions == 0) { return false; }

	// Add the health check if above 100 and bring it down
	health += 30;
	if (health > 100) { health = 100; }
	
	// Take away a potion
	--potions;

	return true;
}

void Player::addScore(int amount)
{
	if (amount > 0) { score += amount; }
}

void Player::restore(int hp, int attackDamage, int potionCount, int points)
{
	// Save system has to validate all fields before calling this.
	health = hp;
	damage = attackDamage;
	potions = potionCount;
	score = points;
}