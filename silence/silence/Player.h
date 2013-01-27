#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Animation.h"
#include "MapCollider.h"
#include "HealthBar.h"

class Weapon;
class WindowManager;

class Player : public Entity
{
public:
	Player(sf::Vector2f startPos, MapCollider m );
	~Player(void);
	virtual void update();
	virtual void render();
	void doDamage(float damage);


	void setWep(Weapon* weapon);

protected:
	sf::Vector2f getDirection(); // <---------------ingen aning ? 

	virtual sf::FloatRect getColBox();
	virtual void ResolveCollision(Entity* entity);

	void attack();
	

private:

	Animation mDown;
	Animation mLeft;
	Animation mRigth;
	Animation mUp;

	Animation mDownIdle;

	Animation* mCurrentAnim;


	MapCollider mMapColider;
	sf::Vector2f mDirection;
	sf::FloatRect mCollisionBox;

	float mYvel, mXvel;
	WindowManager* mWindow;
	float mHP;

	Weapon* mWeapon;

	HealthBar* mHealthBar;
};

#endif