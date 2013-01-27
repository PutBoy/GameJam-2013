#ifndef BULLETKNUCKLES_H
#define BULLETKNUCKLES_H

#include "bullet.h"
#include <SFML\System\Clock.hpp>
#include "Enemy.h"

class BulletKnuckles :
	public Bullet
{
public:
	BulletKnuckles(sf::Vector2f mpos, std::shared_ptr<Entity> ent);
	void update();
	void render();

	
	void ResolveCollision(std::shared_ptr<Entity> entity);
	sf::FloatRect getColBox();
private:
	sf::Vector2f mPos;

	sf::Clock mTimer;
};

#endif 