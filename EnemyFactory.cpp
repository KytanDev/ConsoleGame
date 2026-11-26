#include "EnemyFactory.h"
#include "Skeleton.h"
#include "Knight.h"

Enemy* EnemyFactory::createEnemy(int level, int encounter)
{
	// Centralised so game doesn't need to know the enemy type
	// Levels start at 1; encounters start at 0. Caller owns returned object.
	if (level == 1 && encounter == 0) { return new Skeleton("Skeleton", 40, 8); }
	if (level == 1 && encounter == 1) { return new Knight("Crypt Knight", 60, 10); }
	if (level == 2 && encounter == 0) { return new Skeleton("Cursed Skeleton", 60, 12); }
	if (level == 2 && encounter == 1) { return new Knight("Fallen Knight", 80, 12); }

	return nullptr;
}