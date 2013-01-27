#ifndef ENTITY_H
#define ENTITY_H
#include <SFML\System\Vector2.hpp>
#include <vector>
#include <string>
#include <SFML\Graphics\Rect.hpp>
#include <set>
#include <string>
#include <memory>

class Entity
{
public:
	Entity(sf::Vector2f startPos);
	virtual ~Entity();
	std::shared_ptr<Entity> getNextDrop();
	void Drop(std::shared_ptr<Entity> drop);
	
	bool isDead() {return mIsDead;};
	float getXpos()const;
	float getYpos()const;

	sf::Vector2f getPos();

	virtual void update(){};
	virtual void render(){};
	bool isID(std::string ID);
	void setPos(sf::Vector2f);
	virtual sf::FloatRect getColBox()=0;
	virtual void closeToEnemy(std::shared_ptr<Entity> ent);

	virtual void ResolveCollision(std::shared_ptr<Entity>) = 0;

protected:
	void kill() {mIsDead = true;};
	
	void pushID(std::string ID);
	
	sf::Vector2f mPos;
	bool closeToMyEnemy;
	sf::Vector2f directionToMyEnemy;

	sf::Vector2f distanceRectToRect(sf::FloatRect r0, sf::FloatRect r1);
	sf::Vector2f getMajorVector(sf::Vector2f vec);
private:
	bool mIsDead;
	std::vector<std::shared_ptr<Entity>> drops;


	std::set<std::string> IDset;
	
};

#endif