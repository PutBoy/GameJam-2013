#include "Entity.h"
#include <cmath>

Entity::Entity(sf::Vector2f startPos): mPos(startPos)
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

void Entity::closeToEnemy(Entity* en)
{
	sf::Vector2f direction;
	direction.x = (mPos.x) - en->getXpos();
	direction.y = mPos.y - en->getYpos();
	float length = ((direction.x*direction.x)+(direction.y*direction.y));
	length = sqrt(length);
	if(length < 1000)
	{
		if(length > 0.0)
		{
			direction.x = direction.x/length;
			direction.y = direction.y/length;
		}
		directionToMyEnemy = direction;
		closeToMyEnemy = true;
	}
	else
	{
		closeToMyEnemy = false;
	}
}