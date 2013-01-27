#ifndef WEAPON_H
#define WEAPON_H

#include <SFML\Graphics\Sprite.hpp>

#include "Entity.h"
#include "Animation.h"

class Weapon
{
public:
	Weapon(std::shared_ptr<Entity> player){mPlayer = player;}; //   <---------------correct med måsvingar ??
	virtual ~Weapon(){};
	virtual std::shared_ptr<Entity> shoot()=0;
	virtual sf::Sprite& getSprite()=0;
	virtual sf::FloatRect getColBox()=0;
protected:
	std::shared_ptr<Entity> getPlayer(){return mPlayer;};
private:
	sf::Vector2f mDirection;
	std::shared_ptr<Entity> mPlayer;
};

#endif