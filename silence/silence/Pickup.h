#ifndef INCLUDED_PICKUP
#define INCLUDED_PICKUP

#include "MapCollider.h"
#include "Entity.h"
#include "Animation.h"

class ResourceManager;
class WindowManager;


class Pickup : public Entity{
public:
	Pickup(sf::Vector2f startPos):Entity(startPos){};
	virtual ~Pickup(){};
	virtual void update()=0;
	virtual void render()=0;
	virtual sf::FloatRect getColBox()=0;
	virtual void ResolveCollision(std::shared_ptr<Entity> entity)=0;
};


#endif
