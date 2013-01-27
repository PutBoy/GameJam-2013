#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <SFML\System\Vector2.hpp>
#include <SFML\Graphics.hpp>
#include "WindowManager.h"



class HealthBar
{
public:
	HealthBar();
	~HealthBar(void);
	void update(float health);
	void render();
private:
	sf::RectangleShape mShape;
	WindowManager* mWindow;
};

#endif