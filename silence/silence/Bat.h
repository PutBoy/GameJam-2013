#ifndef BAT_H 
#define BAT_H

#include "enemy.h"
#include "Animation.h"
#include "WindowManager.h"
#include "MapCollider.h"

class Bat :
	public Enemy
{
public:
	Bat(sf::Vector2f spawnPos, MapCollider map);
	~Bat(void);
	virtual void update();
	virtual void render();
	virtual float getHP();
	virtual std::string isID(std::string ID);
	virtual float getDamage();
	virtual void setHP(float damage);
	virtual sf::FloatRect getColBox();
private:
	Animation* mRigth;
	Animation* mLeft;
	Animation* mUp;
	Animation* mDown;
	Animation* mCurrentAnim;
	WindowManager* mWindow;

	MapCollider mMap;

	sf::FloatRect mCollisionBox;
};

#endif