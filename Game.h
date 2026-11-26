#pragma once
#include "Player.h"
#include "Enemy.h"

class Game
{
private:
	Player player;
	int level = 1;
	int encounter = 0;
	void play();
	bool combat(Enemy& enemy);
public:
	void run();
};
