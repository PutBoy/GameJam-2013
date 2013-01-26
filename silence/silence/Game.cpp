#include "Game.h"
#include "MapCollider.h"
#include "WindowManager.h"


Game::Game()
	:player(sf::Vector2f(200,200),
	MapCollider(map.getMap()))
	,cam(&player)
	,frog(sf::Vector2f(300,300))
{
}

bool Game::isAlive()
{
	return true;
}

void Game::update()
{

		player.update();
		frog.update();
		cam.update();
	WindowManager::getInstance()->setView(cam.getView());
}

void Game::render()
{
	player.render();
	frog.render();
	map.render();
}