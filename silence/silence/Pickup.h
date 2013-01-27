#ifndef INCLUDED_PICKUP
#define INCLUDED_PICKUP

#include "MapCollider.h"
#include "Entity.h"
#include "Animation.h"

class ResourceManager;
class WindowManager;


class Pickup : public Entity{
public:
	Pickup(sf::Vector2f startPos, MapCollider m):Entity(startPos)
		{
			mPos = m.tryMove(mPos, sf::Vector2f(0, 1), sf::FloatRect(mPos.x - 32, mPos.y - 32, 64, 64));
		};
	virtual ~Pickup(){};
	virtual void update()=0;
	virtual void render()=0;
	virtual sf::FloatRect getColBox()=0;
	virtual void ResolveCollision(Entity* entity)=0;
};


#endif
