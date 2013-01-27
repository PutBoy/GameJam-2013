#include "StartMenu.h"
#include "StateManager.h"
#include "Game.h"
#include "ResourceManager.h"
#include "WindowManager.h"
#include "MapCollider.h"
#include "Map.h"
#include "MusicManager.h"

StartMenu::StartMenu()
{
	mSprite.setTexture(ResourceManager::getInstance()->loadTexture("background","paint_background.png",sf::IntRect(0,0,1600,900)));
	MusicManager* m = MusicManager::getInstance();
	m->loadSound("intro", "sounds/Heartbeater_Titlescreen_Menu.aif");
	m->playSound("intro");
}

StartMenu::~StartMenu(){
	
}

bool StartMenu::isAlive(){
	return true;
}

void StartMenu::update(){
	input();
}

void StartMenu::render(){
	WindowManager::getInstance()->setDefaultView();
	WindowManager::getInstance()->renderToCanvas(mSprite, 5);
}

void StartMenu::input(){
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Return)){
		MusicManager::getInstance()->stopSound("intro");
		StateManager::getInstance()->add(new Game());
	}
}