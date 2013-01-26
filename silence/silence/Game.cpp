#include "Game.h"
#include "MapCollider.h"
#include "WindowManager.h"

#include "StateManager.h"
#include "PauseMenu.h"

Game::Game():
	player(sf::Vector2f(200,200),
	MapCollider(map.getMap())),
	cam(&player),
	mAlive(true)
{
}

bool Game::isAlive()
{
	return mAlive;
}

void Game::update()
{
	input();
	player.update();
	cam.update();
	//WindowManager::getInstance()->setView(cam.getView());
}

void Game::render()
{
	WindowManager::getInstance()->setView(cam.getView());
	player.render();
	map.render();
}

void Game::input(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
		StateManager::getInstance()->add(new PauseMenu());
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		mAlive = false;
	}
}