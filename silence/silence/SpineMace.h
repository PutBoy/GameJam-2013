#ifndef INCLUDED_SPINEMACE
#define INCLUDED_SPINEMACE

#include "Weapon.h"
#include <SFML\System\Clock.hpp>


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
	Animation mAnimIdle;
	Animation mAnimAttack;
	Animation* mCurrentAnimation;
	sf::Clock mAttackTimer;

	float mAttackSpeed;


	/*Animation* */

};

#endif