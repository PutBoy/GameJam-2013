#ifndef ENTITY_H
#define ENTITY_H
#include <SFML\System\Vector2.hpp>

class Entity
{
public:
	Entity(sf::Vector2f startPos);
	virtual ~Entity(void);
	float getXpos()const;
	float getYpos()const;
	virtual void update();
	virtual void render();
protected:

	sf::Vector2f mPos;
	float mYvel, mXvel;
};

#endif