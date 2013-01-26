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
	virtual float getHP();
	virtual std::string isID(std::string ID);
	virtual float getDamage();
	virtual void setHP(float damage);
	virtual sf::FloatRect getColBox();
private:

	Animation* mDown;
	Animation* mLeft;
	Animation* mRight;

	Animation* mCurrentAnim;
	float mYvel, mXvel;
	sf::RenderWindow* mWindow;
};

#endif