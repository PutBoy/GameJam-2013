#ifndef KNUCKLES_INCLUDE
#define KNUCKLES_INCLUDE

#include "Weapon.h"

class Animation;
class ResourceManager;

class Knuckles : public Weapon

{
public:
	Knuckles(Entity* player);
	~Knuckles();

	bool shoot();
	sf::Sprite& getSprite();
	Entity* createBullet();
	sf::FloatRect getColBox();

protected:

	Entity* getPlayer();

private:
	Animation* mAnimation;

};

#endif