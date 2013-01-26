#ifndef INCLUDED_STARTMENU
#define INCLUDED_STARTMENU

#include "State.h"
#include "SFML\Window\Keyboard.hpp"
#include "SFML\Graphics\Sprite.hpp"

class StateManager;
class ResourceManager;
class WindowManager;


class StartMenu : public State{
public:
	StartMenu();
	~StartMenu();
	bool isAlive();
	void update();
	void render();
	void input();
private:

	sf::Sprite mSprite;
};

#endif