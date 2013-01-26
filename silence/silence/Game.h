#ifndef GAME_H
#define GAME_H

#include "State.h"
#include "MapManager.h"
#include "Player.h"
#include "Camera.h"
#include "Frog.h"
#include "Bat.h"
#include <SFML\Window\Keyboard.hpp>
#include "EntityManager.h"

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
	Entity* spawnEnemy();

	MapManager map;
	EntityManager* mEntityMan;
	
	Player player;
	sf::Clock mEnemySpawnTimer;

	Camera cam;
	bool mAlive;

};

#endif