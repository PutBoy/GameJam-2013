#ifndef WEAPON_H
#define WEAPON_H

#include <SFML\Graphics\Sprite.hpp>

#include "Entity.h"

class Weapon
{
	friend class Entity;
public:
	Weapon(Entity* player){mPlayer = player;}; //   <---------------correct med måsvingar ??
	virtual ~Weapon(){};
	virtual Entity* shoot()=0;
	virtual Entity* specialShoot()=0;
	virtual sf::Sprite& getSprite()=0;
	virtual sf::FloatRect getColBox()=0;
protected:
	Entity* getPlayer(){return mPlayer;};
private:
	sf::Vector2f mDirection;
	Entity* mPlayer;
};

#endif