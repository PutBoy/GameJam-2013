#pragma once

#include "State.h"
#include "SFML\Window\Keyboard.hpp"
#include "SFML\Graphics\Sprite.hpp"

class StateManager;
class ResourceManager;
class WindowManager;

class WinState: public State
{
public:
	WinState(void);
	~WinState(void);
	bool isAlive();
	void update();
	void render();
	void input();
private:
	sf::Sprite mSprite;
	sf::Clock donotContinue;
	bool mAlive;
};

