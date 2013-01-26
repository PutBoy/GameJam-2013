#include "Entity.h"


Entity::Entity(sf::Vector2f startPos): mPos(startPos)
{
}


Entity::~Entity(void)
{
}

float Entity::getXpos()const
{
	return mPos.x;
}

float Entity::getYpos()const
{
	return mPos.y;
}





void Entity::Drop(Entity* drop){
	if(drop != nullptr){
		drops.push_back(drop);
	
	}
}

Entity* Entity::getNextDrop(){

	Entity* ent = nullptr;
	if(drops.size() == 0)
		return nullptr;

	ent = drops[drops.size() - 1];
	drops.pop_back();

	return ent;

}