#pragma once
#include "Player.h"
class SaveSystem
{
public:
	static bool save(const Player& player, int level, int encounter);
	static bool load(Player& player, int& level, int& enounter);
};
