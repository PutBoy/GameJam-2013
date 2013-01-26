#include "Game.h"
#include "MapCollider.h"
#include "WindowManager.h"
Game::Game()
	:player(sf::Vector2f(200,200),
	MapCollider(map.getMap()))
	,cam(&player)
{
}

bool Game::isAlive()
{
	return true;
}

void Game::update()
{

		player.update();

		cam.update();
	WindowManager::getInstance()->setView(cam.getView());
}

void Game::render()
{
	player.render();
	map.render();
}