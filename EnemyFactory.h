#pragma once
#include "Enemy.h"

// Owner: Krystian - follows factory example in notes
class EnemyFactory
{
public:
	// Caller owns returned enemy and must delete it
	static Enemy* createEnemy(int level, int encounter);
};

