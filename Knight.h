#pragma once
#include "Enemy.h"

// Owner: Krystian - one of the enemies
class Knight : public Enemy
{
public:
	Knight(std::string name, int health, int damage);
	int attack() override;
};

