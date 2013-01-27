#ifndef BULLET_INCLUDE
#define BULLET_INCLUDE
#include "Entity.h"

class Bullet: public Entity
{

public:

	Bullet(sf::Vector2f mpos, std::shared_ptr<Entity> ent);
	
	void update(){}
	void render(){}
	void ResolveCollision(std::shared_ptr<Entity> entity){}
	virtual sf::FloatRect getColBox(){return sf::FloatRect(0,0,0,0);}

protected: 

	std::shared_ptr<Entity> getEntity();

private:
	std::shared_ptr<Entity> mEnt;

};


#endif
