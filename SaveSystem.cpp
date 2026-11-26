#include "SaveSystem.h"
#include <fstream>
#include <string>

bool SaveSystem::save(const Player& player, int level, int encounter) 
{
	std::ofstream file("save.txt");
	if (!file)
		return false;

	file << level << ' ' << encounter << ' ' << player.getHealth() << ' '
		<< player.getDamage() << ' ' << player.getPotions() << ' '
		<< player.getScore() << '\n';
	file.close();
	return !file.fail();
}

bool SaveSystem::load(Player& player, int& level, int& encounter)
{
	std::ifstream file("save.txt");
	int l, e, hp, damage, potions, score;
	std::string extra;

	//validate temp values
	if (!(file >> l >> e >> hp >> damage >> potions >> score) || file >> extra)
		return false;

	if (l < 1 || l > 2 || e < 0 || e > 1 || hp <= 0 || hp > 100 || damage != 20 || potions < 0 || potions > 3 || score != ((l - 1) * 2 + e) * 100)
		return false;

	player.restore(hp, damage, potions, score);
	level = 1;
	encounter = e;

	return true;
}
