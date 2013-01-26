#include "Entity.h"
#include <cmath>

Entity::Entity(sf::Vector2f startPos): mPos(startPos)
{
	pushID("Entity");
}

Entity::~Entity(){
	for(int i = 0; i < drops.size(); i++){
	
		delete drops[i];
	}

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

bool Entity::isID(std::string ID)
{
	return (IDset.count(ID) == 1);
}

void Entity::pushID(std::string ID)
{

	IDset.insert(ID);

}

void Entity::setPos(sf::Vector2f newPos)
{
	mPos = newPos;
}

/*	This returns the difference vector between two rectangles. Sort of.
 *		Written: Sebastian Zander 13-01-18 23:21
 *	This function will not work when the difference in size between the rectangles are too big.
 */
sf::Vector2f Entity::distanceRectToRect(sf::FloatRect r0, sf::FloatRect r1)
{
	//calculate the two centers
	sf::Vector2f c0(r0.left + r0.width / 2, r0.top + r0.height / 2);
	sf::Vector2f c1(r1.left + r1.width / 2, r1.top + r1.height / 2);
	//calculate the diffence between the two centers.
	sf::Vector2f diff = c1 - c0;

	//scale the distance to take account for the width and height of the objects. THIS IS NOT PERFECT.
	diff.x = diff.x / (r0.width / 2 + r1.width / 2);
	diff.y = diff.y / (r0.height / 2 + r1.height / 2);

	return diff;
}

/*	This function returns the major (unit) vector given a vector
 *		Written: Sebastian Zander 13-01-18 23:48
 */
sf::Vector2f Entity::getMajorVector(sf::Vector2f vec)
{
	if (std::abs(vec.x) > std::abs(vec.y))
	{
		return sf::Vector2f((vec.x < 0 ? -1.0f : 1.0f), 0.0f);
	}
	else
	{
		return sf::Vector2f(0.0f, (vec.y < 0 ? -1.0f : 1.0f));
	}

}