#ifndef INCLUDED_PAUSEMENU
#define INCLUDED_PAUSEMENU

#include "State.h"
#include <SFML\Graphics\Sprite.hpp>
#include <SFML\Window\Keyboard.hpp>

class ResourceManager;
class PauseMenu;

class PauseMenu : public State{
public:
	PauseMenu();
	~PauseMenu();
	bool isAlive();
	void update();
	void render();
	void input();
private:
	sf::Sprite mSprite;
	bool mAlive;

};

#endif