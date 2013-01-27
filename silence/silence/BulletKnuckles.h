#ifndef BULLETKNUCKLES_H
#define BULLETKNUCKLES_H

#include "bullet.h"

class BulletKnuckles :
	public Bullet
{
public:
	BulletKnuckles(sf::Vector2f mpos, std::shared_ptr<Entity> ent);
	~BulletKnuckles(void);
private:
	sf::Vector2f mPos;

	sf::Clock mTimer;
};

#endif 