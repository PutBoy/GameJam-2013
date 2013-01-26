#include "Game.h"
#include "MapCollider.h"
#include "WindowManager.h"
#include "Entity.h"
#include "StateManager.h"
#include "PauseMenu.h"

#include "SpineMacePickup.h" //<------ ta bort

Game::Game()

	:mAlive(true)
	,mPlayer(new Player(sf::Vector2f(200,200),MapCollider(map.getMap())))
{
	mCam = std::auto_ptr<Camera>(new Camera(mPlayer, 200));
	mEntityMan.AddPlayer(mPlayer);
	mEntityMan.Add(new SpineMacePickup(sf::Vector2f(400,400), map.getMap())); //<----------statisk position
}

bool Game::isAlive()
{
	return mAlive;
}

void Game::update()
{
	//Entity* newEntity = spawnEnemy();
	if(mEnemySpawnTimer.getElapsedTime().asSeconds() > 1)
	{
		
		
		//mEntityMan.Add(newEntity);
		mEnemySpawnTimer.restart();
	}
	mEntityMan.Update();

	mEntityMan.AliveCheck();
	mEntityMan.Collision();
	mEntityMan.Updatedrops();

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
			spawnY = mPlayer->getYpos()-500;
		}
		else
		{
			spawnX = rand()%1600;
			spawnY = mPlayer->getYpos()+500;
		}
		Entity* frog = new Frog(sf::Vector2f(spawnX,spawnY),map.getMap());
		return frog;
	}
	else if(enemyType == 1)
	{
		if(randomSide == 0)
		{
			spawnX = mPlayer->getXpos()+900;
			spawnY = rand()%900;
		}
		else
		{
			spawnX = mPlayer->getXpos()-900;
			spawnY = rand()%900;
		}
		Entity* bat = new Bat(sf::Vector2f(spawnX,spawnY),map.getMap());
		return bat;
	}
	
}