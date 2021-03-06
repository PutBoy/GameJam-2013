#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Animation.h"
#include "MapCollider.h"
#include "HealthBar.h"
#include <stack>
#include "AnimationEntity.h"

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
	
	sf::Vector2f getDirection();

	sf::Vector2f getDir(); //<---------------seans

	sf::Clock& deadforTime();
	void setWep(std::shared_ptr<Weapon> weapon);
protected:

	virtual sf::FloatRect getColBox();
	virtual void ResolveCollision(std::shared_ptr<Entity> entity);

	void attack();
	

private:

	Animation mDown;
	Animation mLeft;
	Animation mRigth;
	Animation mUp;

	Animation mDownIdle;
	Animation mUpIdle;
	Animation mLeftIdle;
	Animation mRigthIdle;
	AnimationEntity* mDeathAnim;

	Animation* mCurrentAnim;


	MapCollider mMapColider;
	sf::Vector2f mDirection;
	sf::FloatRect mCollisionBox;

	float mYvel, mXvel;
	WindowManager* mWindow;
	float mHP;

	std::shared_ptr<Weapon> mWeapon;

	sf::Clock deathTimer;
	HealthBar* mHealthBar;

	sf::Vector2f mDir; //<------------seanass

};

#endif