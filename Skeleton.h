#pragma once
#include "Enemy.h"

// Owner: Krystian
class Skeleton : public Enemy
{
public:
	Skeleton(std::string name, int health, int damage);
	int attack() override;
};

