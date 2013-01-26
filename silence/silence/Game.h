#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "MapManager.h"
#include "Player.h"
#include "Camera.h"
#include <SFML\Window\Keyboard.hpp>


class StateManager;
class PauseMenu;

class Game: public State
{
public:
	Game();
	bool isAlive();
	void update();
	void render();
	void input();
private:

	MapManager map;
	Player player;
	Camera cam;
	bool mAlive;

};

#endif