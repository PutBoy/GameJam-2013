#ifndef KNUCKLES_INCLUDE
#define KNUCKLES_INCLUDE
#include "Animation.h"
#include "Weapon.h"
#include <SFML\System\Clock.hpp>
class ResourceManager;
class BulletKnuckles;

class Knuckles : public Weapon

{
public:
	Knuckles(std::shared_ptr<Entity> player);
	~Knuckles();

	std::shared_ptr<Entity> shoot();
	sf::Sprite& getSprite();
	
	sf::FloatRect getColBox();

protected:

	std::shared_ptr<Entity> getPlayer();

private:
	Animation mAnimIdle;
	Animation mAnimAttackForward;
	Animation mAnimAttackBack;
	Animation mAnimAttackLeft;
	Animation mAnimAttackRight;

	Animation mAnimFel;

	Animation* mCurrentAttack;

	bool mAttacking;

	sf::Clock mAttackTimer;

	float mAttackSpeed;

	int mKillCounter;
};

#endif