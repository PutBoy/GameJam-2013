#ifndef WEAPON_H
#define WEAPON_H

#include <SFML\Graphics\Sprite.hpp>

class Player; // kanske

class Entity;

class Weapon
{
	friend class Player;
public:
	Weapon(Entity* player){}; //   <---------------correct med måsvingar ??
	virtual ~Weapon(){};
	virtual bool shoot()=0;
	virtual sf::Sprite getSprite()=0;
	virtual Entity* createBullet()=0;
protected:
	virtual Entity* getPlayer()=0;
private:
	sf::Vector2f mDirection;
	Player* mPlayer;
};

#endif