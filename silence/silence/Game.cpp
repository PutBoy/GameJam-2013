#include "Game.h"
#include "MapCollider.h"
#include "WindowManager.h"
Game::Game()
	:player(sf::Vector2f(200,200),MapCollider(new Map(50,50)))
	,msElapsed(0.f)
	,cam(&player)
	,msUpdateRate(10.f)
{
	clock.restart();
}

bool Game::isAlive()
{
	return true;
}

void Game::update()
{
	//I R so clever herp derp
	for (msElapsed += clock.restart().asMilliseconds(); msElapsed > msUpdateRate; msElapsed -= msUpdateRate)
	{
		player.update();

		cam.update();
	}
	
	WindowManager::getInstance()->setView(cam.getView());
}

void Game::render()
{
	player.render();
	map.render();
}