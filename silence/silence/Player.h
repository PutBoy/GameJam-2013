#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Animation.h"

class Player : public Entity
{
public:
	Player(sf::Vector2f startPos);
	~Player(void);
	virtual void update();
	virtual void render();
private:
	Animation mDown;
};

#endif