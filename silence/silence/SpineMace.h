#ifndef INCLUDED_SPINEMACE
#define INCLUDED_SPINEMACE

#include "Weapon.h"

class Animation;
class ResourceManager;
class BulletSpineMace;

class SpineMace : public Weapon{
public:
	SpineMace(Entity* player);
	~SpineMace();

	Entity* shoot();
	Entity* specialShoot();
	sf::Sprite& getSprite();
	sf::FloatRect getColBox();

private:
	Animation* mAnimation;
	/*Animation* */

};

#endif