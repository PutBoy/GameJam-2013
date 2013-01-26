#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "MapManager.h"
#include "Player.h"
#include "Camera.h"
#include <SFML\System\Clock.hpp>
#include <SFML\System\Vector2.hpp>

class Game: public State
{
public:
	Game();
	bool isAlive();
	void update();
	void render();
private:
	sf::Clock clock;
	float msElapsed;
	const float msUpdateRate;

	MapManager map;

	Player player;
	Camera cam;
};

#endif