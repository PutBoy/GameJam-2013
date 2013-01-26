#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Animation.h"
#include <SFML\Graphics.hpp>

class Player : public Entity
{
public:
	Player(sf::Vector2f startPos);
	~Player(void);
	virtual void update();
	virtual void render();
private:

	Animation* mDown;
	Animation* mLeft;

	Animation* mCurrentAnim;
	float mYvel, mXvel;
	sf::RenderWindow* mWindow;
};

#endif