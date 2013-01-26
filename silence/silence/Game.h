#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "MapManager.h"
#include "Player.h"
#include "Camera.h"
#include "Frog.h"

class Game: public State
{
public:
	Game();
	bool isAlive();
	void update();
	void render();
private:

	MapManager map;

	Player player;
	Frog frog;
	Camera cam;
};

#endif