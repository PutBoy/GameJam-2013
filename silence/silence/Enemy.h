#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
class Enemy :
	public Entity
{
public:
	Enemy(sf::Vector2f spawnPos);
	virtual ~Enemy(void);
	virtual void update()=0;
	virtual void render()=0;
	virtual float getHP()=0;

	virtual float getDamage()=0;
	virtual void setHP(float damage)=0;
	virtual sf::FloatRect getColBox()=0;

	virtual void ResolveCollision(Entity* entity);
protected:
	sf::Vector2f getRandomMove();
};

#endif