#ifndef INCLUDED_SPINEMACE
#define INCLUDED_SPINEMACE

#include "Weapon.h"

class Animation;
class ResourceManager;

class SpineMace : public Weapon{
public:
	SpineMace(Entity* player);
	~SpineMace();

	bool shoot();
	sf::Sprite getSprite();
	Entity* createBullet();
protected:
	Entity* getPlayer();

private:
	Animation* mAnimation;

};

#endif