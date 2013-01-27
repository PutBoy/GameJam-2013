#ifndef MEGASUPERHACKERGUY_H
#define MEGASUPERHACKERGUY_H

#include "Enemy.h"
#include "Animation.h"
#include "WindowManager.h"
#include "MapCollider.h"

class MegaSuperHackerGuy :
	public Enemy
{
public:
	MegaSuperHackerGuy(sf::Vector2f spawnPos, MapCollider map);
	~MegaSuperHackerGuy(void);
	virtual void update();
	virtual void render();

	virtual sf::FloatRect getColBox();
	virtual void ResolveCollision(std::shared_ptr<Entity> entity);
private:
	Animation* mRigth;
	Animation* mLeft;
	Animation* mDown;
	Animation* mUp;
	Animation* mCurrentAnim;
	WindowManager* mWindow;

	MapCollider mMap;

	sf::FloatRect mCollisionBox;
};

#endif