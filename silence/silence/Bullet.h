#ifndef BULLET_INCLUDE
#define BULLET_INCLUDE
#include "Entity.h"

class Bullet: public Entity
{

public:

	Bullet(sf::Vector2f mpos, Entity* ent);
	
	void update(){}
	void render(){}
	void ResolveCollision(Entity* entity){}
	virtual sf::FloatRect getColBox(){return sf::FloatRect(0,0,0,0);}

protected: 

	Entity* getEntity();

private:
	Entity* mEnt;

};


#endif
