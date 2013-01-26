#include "Game.h"
#include "MapCollider.h"
#include "WindowManager.h"

#include "Entity.h"
#include "StateManager.h"
#include "PauseMenu.h"

Game::Game()
	:player(sf::Vector2f(200,200),
	MapCollider(map.getMap()))
	,cam(&player)
	,frog(sf::Vector2f(300,300), MapCollider(map.getMap())),
	mAlive(true)

{
}

bool Game::isAlive()
{
	return mAlive;
}

void Game::update()
{

	player.update();
	Entity* p = &player;

	frog.closeToEnemy(p);
	frog.update();

	input();
	cam.update();

}

void Game::render()
{
	WindowManager::getInstance()->setView(cam.getView());
	player.render();
	frog.render();
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