#include "StartMenu.h"
#include "StateManager.h"
#include "Game.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "MapCollider.h"
#include "Map.h"
#include "MusicManager.h"
#include "WinState.h"
#include "IntroScreen.h"
WinState::WinState()
{
	mSprite.setTexture(ResourceManager::getInstance()->loadTexture("WinScreen","images/win_screen_png.png",sf::IntRect(0,0,1600,900)));
	MusicManager* m = MusicManager::getInstance();
	donotContinue.restart();
	mAlive = true;
}

WinState::~WinState(){
	
}

bool WinState::isAlive(){
	return mAlive;
}

void WinState::update(){
	input();
}

void WinState::render(){
	WindowManager::getInstance()->setDefaultView();
	WindowManager::getInstance()->renderToCanvas(mSprite, 5);
}

void WinState::input(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		StateManager::getInstance()->add(new IntroScreen());
		mAlive = false;
	}
}