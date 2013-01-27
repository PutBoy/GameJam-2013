#ifndef INCLUDED_SPINEMACE
#define INCLUDED_SPINEMACE

#include "Weapon.h"
#include <SFML\System\Clock.hpp>


class ResourceManager;
class BulletSpineMace;

class SpineMace : public Weapon{
public:
	SpineMace(std::shared_ptr<Entity> player);
	~SpineMace();

	std::shared_ptr<Entity> shoot();
	sf::Sprite& getSprite();
	sf::FloatRect getColBox();

private:
	Animation mAnimIdle;
	Animation mAnimAttack;

	bool mAttacking;

	sf::Clock mAttackTimer;

	float mAttackSpeed;


	/*Animation* */

};

#endif