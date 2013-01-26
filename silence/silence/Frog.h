#ifndef FROG_H
#define FROG_H

#include "Enemy.h"
#include "Animation.h"
#include "WindowManager.h"

class Frog : public Enemy
{
public:
	Frog(sf::Vector2f spawnPos);
	~Frog(void);
	virtual void update();
	virtual void render();
	virtual float getHP();
	virtual std::string isID(std::string ID);
	virtual float getDamage();
	virtual void setHP(float damage);
	virtual sf::FloatRect getColBox();
private:
	Animation* mRigth;
	Animation* mCurrentAnim;
	WindowManager* mWindow;
	sf::FloatRect mCollisionBox;
};

#endif