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