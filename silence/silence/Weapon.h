#ifndef WEAPON_H
#define WEAPON_H

#include "Player.h"

class Entity;

class Weapon
{
	friend class Player;
public:
	Weapon(Player* player);
	~Weapon(void);

	Entity* shoot();

private:
	sf::Vector2f mDirection;
	Player* mPlayer;
};

#endif