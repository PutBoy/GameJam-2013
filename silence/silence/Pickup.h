#ifndef INCLUDED_PICKUP
#define INCLUDED_PICKUP

#include "Entity.h"
class Animation;
class ResourceManager;
class WindowManager;

class Pickup : public Entity{
public:
	Pickup(sf::Vector2f startPos):Entity(startPos){};
	virtual ~Pickup(){};
	virtual void update()=0;
	virtual void render()=0;
	virtual std::string isID(std::string ID)=0;
	virtual sf::FloatRect getColBox()=0;
	virtual void ResolveCollision(Entity* entity)=0;
};


#endif
