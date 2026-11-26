#include "Game.h"
#include "SaveSystem.h"
#include "EnemyFactory.h"
#include <iostream>
#include <sstream>

static int readChoice(int min, int max)
{
	std::string line;
	while (std::getline(std::cin, line))
	{
		std::istringstream input(line);
		int choice; 
		char extra;
		if (input >> choice && !(input >> extra) && choice >= min && choice <= max)
			return choice;
		std::cout << "Invalid choice. Try again: ";
	}
	return -1;
}

void Game::run()
{
	while (true)
	{
		std::cout << "\nDungeon Gauntlet\n1. New game\n2. Load\n3. Quit\n";
		int choice = readChoice(1, 3);
		if (choice == -1 || choice == 3)
			return;
		if (choice == 1)
		{
			//reset previous run and player stats
			player = Player();
			level = 1;
			encounter = 0;
		}
		else if (!SaveSystem::load(player, level, encounter))
		{
			std::cout << "Missing or invalid save.\n";
			continue;
		}
		play();
	}
}

void Game::play()
{
	while (player.isAlive() && level <= 2)
	{
		std::cout << "\nLevel " << level << " Encounter " << encounter + 1 << "HP: " << player.getHealth() << " Score: " << player.getScore() << "\n1. Fight\n2. Save\n3. Main menu\n> ";
		int choice = readChoice(1, 3);
		if (choice == -1 || choice == 3)
			return;
		if (choice == 2)
		{
			std::cout << (SaveSystem::save(player, level, encounter) ? "Saved.\n" : "Save failed/\n");
			continue;
		}
		Enemy* enemy = EnemyFactory::createEnemy(level, encounter);
		if (!enemy) 
		{
			std::cout << "Invalid encounter.\n";
			return;
		}
		bool won = combat(*enemy);

		delete enemy;
		if (!won)
		{
			if (!player.isAlive())
			{
				std::cout << "Defeat! Score: " << player.getScore() << '\n';
			}
			return;
		}
		player.addScore(100);
		if (++encounter == 2)
		{
			encounter = 0;
			++level;
		}
	}
	if (level == 3)
	{
		std::cout << "Victory! Score: " << player.getScore() << '\n';
	}
}

bool Game::combat(Enemy& enemy)
{
	while (player.isAlive() && enemy.getHealth())
	{
		std::cout << "\n" << enemy.getName() << " HP: " << enemy.getHealth() << " | Your HP: " << player.getHealth() << " | Potions: " << player.getPotions() << "\n1. Attack\n2. Heavy attack\n3. Heal\n>";
		int choice = readChoice(1, 3);
		if (choice == -1)
			return false;
		if (choice == 3)
		{
			if (!player.heal())
			{
				std::cout << "Cannot heal.\n";
				continue;
			}
		}
		else 
		{
			//heavy attack does more damage
			int damage = player.getDamage();
			if (choice == 2)
			{
				damage += damage / 2;
			}
			enemy.takeDamage(damage);
			std::cout << "You deal " << damage << " damage.\n";
		}
		if (!enemy.isAlive())
			return true;
		int damage = enemy.attack();
		if (choice == 2)
			damage += damage / 2;
		player.takeDamage(damage);
		std::cout << "Enemy deals " << damage << " damage.\n";
	}
	return false;
}
