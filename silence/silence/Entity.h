#ifndef ENTITY_H
#define ENTITY_H
#include <SFML\System\Vector2.hpp>
#include <vector>
#include <string>
#include <SFML\Graphics\Rect.hpp>


class Entity
{
public:
	Entity(sf::Vector2f startPos);
	virtual ~Entity();
	Entity* getNextDrop();
	void Drop(Entity* drop);
	
	float getXpos()const;
	float getYpos()const;
	virtual void update()=0;
	virtual void render()=0;
	virtual float getHP()=0;
	virtual std::string isID(std::string ID)=0;
	virtual float getDamage()=0;
	virtual void setHP(float damage)=0;
	virtual sf::FloatRect getColBox()=0;
	virtual void closeToEnemy(Entity* en);
protected:
	sf::Vector2f mPos;
	bool closeToMyEnemy;
	sf::Vector2f directionToMyEnemy;
private:
	std::vector <Entity*> drops;

};

#endif