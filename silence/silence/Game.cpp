#include "Game.h"
#include "MapCollider.h"
#include "WindowManager.h"
#include "Entity.h"
#include "StateManager.h"
#include "PauseMenu.h"
#include "MegaSuperHackerGuy.h"
#include "SpineMacePickup.h" //<------ ta bort
#include <memory>

Game::Game()

	:mAlive(true)
	,mPlayer(std::make_shared<Player>(sf::Vector2f(200,200),MapCollider(map.getMap())))
{
	
	mCam = std::auto_ptr<Camera>(new Camera(mPlayer, 200));
	mEntityMan.AddPlayer(mPlayer);
	mEntityMan.Add(std::make_shared<SpineMacePickup>(sf::Vector2f(400,400), map.getMap())); //<----------statisk position
	mMusic = MusicManager::getInstance();
	mMusic->loadSound("battle", "sounds/Heartbeater_Battle.aif");
}

bool Game::isAlive()
{
	return mAlive;
}

void Game::update()
{
	if(!mMusic->isThisPlaying("battle"))
	{
		mMusic->playSound("battle");
	}
	std::shared_ptr<Entity> newEntity = spawnEnemy();
	if(mEnemySpawnTimer.getElapsedTime().asSeconds() > 1)
	{
		mEntityMan.Add(newEntity);
		mEnemySpawnTimer.restart();
	}

	mEntityMan.Update();

	input();
	mCam->update();

}

void Game::render()
{
	WindowManager::getInstance()->setView(mCam->getView());
	mEntityMan.Draw();
	map.render();
}

void Game::input(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::P)){
		mMusic->pauseSound("battle");
		StateManager::getInstance()->add(new PauseMenu());
	}
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
		mMusic->stopSound("battle");
		mAlive = false;
	}
}

std::shared_ptr<Entity> Game::spawnEnemy()
{
	
	int enemyType = rand()%11;
	int randomSide = rand()%2;
	int spawnX,spawnY;

	int randX = rand()%1600+ mPlayer->getXpos();
	int randY = rand()%900+ mPlayer->getYpos();

	if(enemyType <= 4)
	{
		if(randomSide == 0)
		{
			spawnX = randX;
			spawnY = mPlayer->getYpos()-460;
		}
		else
		{
			spawnX = randX;
			spawnY = mPlayer->getYpos()+460;
		}
		std::shared_ptr<Entity> frog = std::make_shared<Frog>(sf::Vector2f(spawnX,spawnY),map.getMap());
		return frog;
	}
	else if(enemyType > 4 && enemyType <= 8)
	{
		if(randomSide == 0)
		{
			spawnX = mPlayer->getXpos()+850;
			spawnY = randY;
		}
		else
		{
			spawnX = mPlayer->getXpos()-850;
			spawnY = randY;
		}
		std::shared_ptr<Entity> bat = std::make_shared<Bat>(sf::Vector2f(spawnX,spawnY),map.getMap());
		return bat;
	}
	else if(enemyType >= 9)
	{
		if(randomSide == 0)
		{
			spawnX = mPlayer->getXpos()+850;
			spawnY = randY;
		}
		else
		{
			spawnX = randX;
			spawnY = mPlayer->getYpos()+460;
		}
		std::shared_ptr<Entity> megaGuy = std::make_shared<MegaSuperHackerGuy>(sf::Vector2f(spawnX,spawnY),map.getMap());
		return megaGuy;
	}
	
	return nullptr;
}
