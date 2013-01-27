#ifndef ENEMY_H
#define ENEMY_H

#include "entity.h"
class Enemy :
	public Entity
{
public:
	Enemy(sf::Vector2f spawnPos,float HP);
	virtual ~Enemy(void);
	virtual void update()=0;
	virtual void render()=0;
	void doDamage(float damage);

	virtual sf::FloatRect getColBox()=0;

	virtual void ResolveCollision(Entity* entity);
protected:
	float getHP();
	float mHP;
	sf::Vector2f getRandomMove();
};

#endif