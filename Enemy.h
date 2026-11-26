#pragma once
#include <string>

// Owner: Krystian - common enemy behaviour.
class Enemy
{
private:
	std::string name;
	int health;
	int damage;
public:
	Enemy(std::string name, int health, int damage);
	virtual ~Enemy() = default;
	std::string getName() const;
	int getHealth() const;
	int getDamage() const;
	bool isAlive() const;
	void takeDamage(int amount);
	virtual int attack() = 0;
};

