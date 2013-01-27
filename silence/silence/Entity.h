#ifndef ENTITY_H
#define ENTITY_H
#include <SFML\System\Vector2.hpp>
#include <vector>
#include <string>
#include <SFML\Graphics\Rect.hpp>
#include <set>
#include <string>

class Entity
{
public:
	Entity(sf::Vector2f startPos);
	virtual ~Entity();
	Entity* getNextDrop();
	void Drop(Entity* drop);
	
	float getXpos()const;
	float getYpos()const;

	sf::Vector2f getPos();

	virtual void update()=0;
	virtual void render()=0;
	bool isID(std::string ID);
	void setPos(sf::Vector2f);
	virtual sf::FloatRect getColBox()=0;
	virtual void closeToEnemy(Entity* en);

	virtual void ResolveCollision(Entity* entity)=0;

protected:
	void pushID(std::string ID);
	
	sf::Vector2f mPos;
	bool closeToMyEnemy;
	sf::Vector2f directionToMyEnemy;

	sf::Vector2f distanceRectToRect(sf::FloatRect r0, sf::FloatRect r1);
	sf::Vector2f getMajorVector(sf::Vector2f vec);
private:
	std::vector <Entity*> drops;
	std::set<std::string> IDset;
};

#endif