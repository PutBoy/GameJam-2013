#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Animation.h"
#include "MapCollider.h"

class WindowManager;

class Player : public Entity
{
public:
	Player(sf::Vector2f startPos, MapCollider m );
	~Player(void);
	virtual void update();
	virtual void render();
	virtual float getHP();
	virtual std::string isID(std::string ID);
	virtual float getDamage();
	virtual void setHP(float damage);
	virtual sf::FloatRect getColBox();
private:

	Animation* mDown;
	Animation* mLeft;
	Animation* mRigth;
	Animation* mUp;
	Animation* mCurrentAnim;

	MapCollider mMapColider;

	sf::FloatRect mCollisionBox;

	float mYvel, mXvel;
	WindowManager* mWindow;
};

#endif