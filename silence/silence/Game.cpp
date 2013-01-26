#include "Game.h"
#include "MapCollider.h"
#include "WindowManager.h"
#include "Entity.h"
#include "StateManager.h"
#include "PauseMenu.h"


Game::Game()
	:player(sf::Vector2f(200,200),MapCollider(map.getMap()))
	,cam(&player),
	mAlive(true)
{
	mEntityMan = EntityManager::getInstance();
	mEntityMan->AddPlayer(&player);
	mEntityMan->Add(&player);

}

bool Game::isAlive()
{
	return mAlive;
}

void Game::update()
{
	Entity* newEntity = spawnEnemy();
	if(mEnemySpawnTimer.getElapsedTime().asSeconds() > 1)
	{
		mEntityMan->Add(newEntity);
		mEnemySpawnTimer.restart();
	}
	mEntityMan->Update();

	input();
	cam.update();

}

void Game::render()
{
	WindowManager::getInstance()->setView(cam.getView());
	mEntityMan->Draw();
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

Entity* Game::spawnEnemy()
{
	
	int enemyType = rand()%2;
	int randomSide = rand()%2;
	int spawnX,spawnY;
	if(enemyType == 0)
	{
		if(randomSide == 0)
		{
			spawnX = rand()%1600;
			spawnY = player.getYpos()-500;
		}
		else
		{
			spawnX = rand()%1600;
			spawnY = player.getYpos()+500;
		}
		Entity* frog = new Frog(sf::Vector2f(spawnX,spawnY),map.getMap());
		return frog;
	}
	else if(enemyType == 1)
	{
		if(randomSide == 0)
		{
			spawnX = player.getXpos()+900;
			spawnY = rand()%900;
		}
		else
		{
			spawnX = player.getXpos()-900;
			spawnY = rand()%900;
		}
		Entity* bat = new Bat(sf::Vector2f(spawnX,spawnY),map.getMap());
		return bat;
	}
	
}