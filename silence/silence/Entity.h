#ifndef ENTITY_H
#define ENTITY_H
#include <SFML\System\Vector2.hpp>

class Entity
{
public:
	Entity(sf::Vector2f startPos);
	Entity* GetNextDrop();
	void Drop(Entity*);
	virtual ~Entity(void);
	float getXpos()const;
	float getYpos()const;
	virtual void update()=0;
	virtual void render()=0;
protected:
	sf::Vector2f mPos;


};

#endif