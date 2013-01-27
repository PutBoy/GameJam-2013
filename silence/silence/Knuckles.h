#ifndef KNUCKLES_INCLUDE
#define KNUCKLES_INCLUDE

#include "Weapon.h"

class Animation;
class ResourceManager;

class Knuckles : public Weapon

{
public:
	Knuckles(std::shared_ptr<Entity> player);
	~Knuckles();

	std::shared_ptr<Entity> shoot();
	sf::Sprite& getSprite();
	std::shared_ptr<Entity> createBullet();
	sf::FloatRect getColBox();

protected:

	std::shared_ptr<Entity> getPlayer();

private:
	Animation mAnimation;

};

#endif