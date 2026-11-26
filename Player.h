#pragma once

// Owner: Krystian - Player stats and actions
class Player
{
private:
	int health = 100;
	int damage = 20;
	int potions = 3;
	int score = 0;
public:
	int getHealth() const;
	int getDamage() const;
	int getPotions() const;
	int getScore() const;
	bool isAlive() const;
	void takeDamage(int amount);
	bool heal();
	void addScore(int amount);
	void restore(int hp, int attackDamage, int potionCount, int points);
};

